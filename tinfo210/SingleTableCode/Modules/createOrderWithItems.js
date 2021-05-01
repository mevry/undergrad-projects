var AWS = require('aws-sdk');
AWS.config.update({region:"us-west-2"});
var print = require('../../helpers').printPretty;
var dyn = new AWS.DynamoDB();
var uuidv4 = require('uuid/v4');
var dateFormat = require('dateformat');
var randomString = require('randomstring');

//function to create an order with order items.
//specify the customer id and the number of items 
//that should be in the order
function createOrderWithItems(customer,noItems){
    //created this to be async to run multiple orders
    let prom = new Promise(function(resolve,reject){
        var today = new Date();
        //ORDER
        //Generate Order with UUID
        let orderId = `order-${uuidv4()}`;
        console.log("Order UUID: " + orderId)
        console.log("Order Created: " + dateFormat(today))
        //Static customerID
        let custId = customer;
        //Today's Date
        let datePlaced = dateFormat(today,"isoDateTime");
        //Initial Order Status
        let status = 'UNFILLED';
        //How many order items do you want to generate?
        let numOfOrderItems = noItems;
        
        
        //Put Query Parameters for Order
        var params = {
            "TableName":"dwf",
            "Item":{
                "pk":{"S":orderId},
                "sk":{"S":custId},
                "date-placed":{"S":datePlaced},
                "gsi1-sk":{"S":status}
            },
            "ReturnConsumedCapacity":"TOTAL"
        };

        //Begin insert of ORDER (async)
        var orderPromise = dyn.putItem(params).promise();
        orderPromise
            //.then(print)
            .catch(print)
        //Push generated order items onto this array:
        let orderItems = [];

        //GENERATE RANDOM ORDER ITEMS
        //For each order, generate random product id (5 chars, only alpha)
        for(let i = 0; i < numOfOrderItems; i++){
            let prodId = `prod-${randomString.generate({
                length:5,
                charset:'alphabetic'
            })}`;
            //Random quantity (1-15)
            let quantity = getRandomInt(1,16);
            //Put Query for each OrderItem
            let obj = {
                PutRequest:{
                    Item:{
                        "pk":{S: orderId},
                        "sk":{S: prodId},
                        "gsi1-sk":{S: custId},
                        //I didn't know what to do for price,
                        //so I just picked the first character's UTF code
                        //This means that there is some randomization,
                        //but the price is always consistent for that ID
                        "price":{N: `${prodId.charCodeAt(5)}`},
                        "qty":{N: `${quantity}`},
                        "date-placed":{"S":datePlaced}
                    }
                }
            }
            //Push each query onto the orderItems array
            //for batch put (supposedly more efficient)
            orderItems.push(obj);
        }

        //This array will hold all the batch jobs so that
        //I can call Promise.All() to measure the approximate
        //time for completion
        let pendingPromises = []

        //Batch Put if there are multiple items
        if(orderItems.length >= 1){           
            //Set up counter of remaining items
            let remainingItems = orderItems.length        
            //Track current index for orderItems array
            let currIndex = 0 
            //Begin Batch operation timer
            console.time(`${noItems}_Items`)

            //While we still have items to process..
            while(remainingItems > 0){
                
                var batchPromise;

                //if remaining > 25, then we work on
                //25 items (the max that BatchWrite can handle)     
                if(remainingItems >= 25){
                    //Begin insert of ORDER ITEMS batch
                    batchPromise = dyn.batchWriteItem({
                        "RequestItems":{
                            //Take 25 items, starting at the index
                            "dwf":orderItems.slice(currIndex, currIndex + 25)
                        },
                        "ReturnConsumedCapacity":"TOTAL"
                    }).promise()
                    //Push the promise onto array to track when all promises are complete
                    pendingPromises.push(batchPromise)
                    //Catch any errors
                    batchPromise
                        //.then(print)
                        .catch(print);
                    //decrement remaining items               
                    remainingItems -= 25
                    //move index up for next batch of items
                    currIndex += 25
                }
                //There are less than 25 items,
                //take the rest of the items
                else{
                    batchPromise = dyn.batchWriteItem({
                        "RequestItems":{
                            "dwf":orderItems.slice(currIndex, currIndex + remainingItems)
                        },
                        "ReturnConsumedCapacity":"TOTAL"  
                    }).promise()
                    pendingPromises.push(batchPromise)
                    batchPromise
                        //.then(print)
                        .catch(print)
                    remainingItems = 0;
                    
                }
            }
            //Wait for all promises to be fulfilled,
            //Then stop the timer
            Promise.all(pendingPromises).then(
                function(){
                    console.timeEnd(`${noItems}_Items`)
                    console.log();
                    resolve()
                }      
            );
        }else{
            console.log("0 items specified in order, nothing created.\n")
        }
        //Generate Random Number
        //From Mozilla Developer Network:
        //https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Math/random
        function getRandomInt(min, max) {
            min = Math.ceil(min);
            max = Math.floor(max);
            return Math.floor(Math.random() * (max - min)) + min;
        }
    });//end Promise
    return prom;
};//end createOrderWithItems()

//Node.js export module
module.exports.createOrderWithItems = createOrderWithItems;
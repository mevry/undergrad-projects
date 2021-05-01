//https://docs.aws.amazon.com/sdk-for-javascript/v2/developer-guide/dynamodb-example-query-scan.html
var AWS = require('aws-sdk');
var print = require('../../helpers').printPretty;
AWS.config.update({region: 'us-west-2'});
var dateFormat = require('dateformat');

var dynamoService = new AWS.DynamoDB({apiVersion: '2012-08-10'});

function getOrderItems(orderId){
    let now = new Date()
    console.log("Order UUID: " + orderId)
    console.log("Order Retrieved: " + dateFormat(now))
    var params = {
        "TableName": "dwf",
        "KeyConditionExpression":"#pk = :val",
        "ExpressionAttributeNames":{"#pk":"pk"},
        "ExpressionAttributeValues":{
            ":val":{"S":orderId}
        },
        "ReturnConsumedCapacity":"TOTAL"
    };
    console.time("GetOrderItemsTime")
    var promise = dynamoService.query(params).promise();
    promise
        .then(function(orderItems){
            console.timeEnd("GetOrderItemsTime")
            print(orderItems)
            printUnfilledOrders(orderItems)
        })
        .catch(print);
    
}
function printUnfilledOrders(data){
    orders = data.Items
    numOrders = 0;
    console.log();
    orders.forEach(element => {
        numOrders++
    });
    console.log(`\nTotal Number of Order Items:  ${numOrders-1}\n`)
}

module.exports.getOrderItems = getOrderItems
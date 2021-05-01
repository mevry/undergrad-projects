//Get all order items for a given customer
//(basically a full timeline of what the customer has ordered)
var AWS = require('aws-sdk');
var print = require('../../helpers').printPretty;
AWS.config.update({region: 'us-west-2'});
var dynamoService = new AWS.DynamoDB({apiVersion: '2012-08-10'});

function getAllOrderItemsByCust(custId){
    var params = {
        "TableName": "dwf",
        "IndexName": "gsi2",
        "KeyConditionExpression":"#gsi1sk = :cust",
        "ExpressionAttributeNames":{"#gsi1sk":"gsi1-sk"},
        "ExpressionAttributeValues":{
            ":cust":{"S":custId}
        },
        "ReturnConsumedCapacity":"TOTAL"
    };

    var promise = dynamoService.query(params).promise();
    promise
        .then(printOrderItems)
        .catch(print);

    function printOrderItems(data){
        orders = data.Items
        numOrders = 0;
        console.log();
        orders.forEach(element => {
            console.log(`ORDER ID: ${element.pk.S}, ORDER ITEM: ${element.sk.S}, PRICE: ${element.price.N}, QUANTITY: ${element.qty.N} DATE PLACED: ${element['date-placed'].S}`)
            numOrders++
        });
        console.log(`\nTotal Number of Order Items:  ${numOrders}\n`)
    }
}
module.exports.getAllOrderItemsByCust = getAllOrderItemsByCust
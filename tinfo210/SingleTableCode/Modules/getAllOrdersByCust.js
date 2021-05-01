//Get all orders for a customer
var AWS = require('aws-sdk');
var print = require('../../helpers').printPretty;
AWS.config.update({region: 'us-west-2'});

var dynamoService = new AWS.DynamoDB({apiVersion: '2012-08-10'});

function getAllOrdersByCust(custId){
    var params = {
        "TableName": "dwf",
        "IndexName": "sk-date-placed",
        "KeyConditionExpression":"#sk = :cust",
        "ExpressionAttributeNames":{"#sk":"sk"},
        "ExpressionAttributeValues":{
            ":cust":{"S":custId}
        },
        "ReturnConsumedCapacity":"TOTAL"
    };

    var promise = dynamoService.query(params).promise();
    promise
        .then(printOrders)
        .catch(print);
}
function printOrders(data){
    orders = data.Items
    numOrders = 0;
    console.log();
    orders.forEach(element => {
        console.log(`ORDER ID: ${element.pk.S}, DATE PLACED: ${element['date-placed'].S}\, STATUS: ${element['gsi1-sk'].S}`)
        numOrders++
    });
    console.log(`\nTotal Number of Orders:  ${numOrders}\n`)
}
module.exports.getAllOrdersByCust = getAllOrdersByCust

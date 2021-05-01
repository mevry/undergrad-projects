//https://docs.aws.amazon.com/sdk-for-javascript/v2/developer-guide/dynamodb-example-query-scan.html
var AWS = require('aws-sdk');
var print = require('../helpers').printPretty;
AWS.config.update({region: 'us-west-2'});

var dynamoService = new AWS.DynamoDB({apiVersion: '2012-08-10'});

var params = {
    "TableName": "dwf",
    "IndexName":"order-priority",
    "KeyConditionExpression":"#pk = :val",
    "ExpressionAttributeNames":{"#pk":"gsi1-sk"},
    "ExpressionAttributeValues":{
        ":val":{"S":"UNFILLED"}
    },
    "ReturnConsumedCapacity":"TOTAL"
};

var promise = dynamoService.query(params).promise();
promise
    .then(printUnfilledOrders)
    .catch(print);

function printUnfilledOrders(data){
    orders = data.Items
    numOrders = 0;
    console.log();
    orders.forEach(element => {
        console.log(`ORDER ID: ${element.pk.S}, DATE PLACED: ${element['date-placed'].S}\, STATUS: ${element['gsi1-sk'].S}, CUSTOMER: ${element.sk.S}`)
        numOrders++
    });
    console.log(`\nTotal Number of Orders:  ${numOrders}\n`)
}
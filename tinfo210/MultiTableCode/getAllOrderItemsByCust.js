//https://docs.aws.amazon.com/sdk-for-javascript/v2/developer-guide/dynamodb-example-query-scan.html
var AWS = require('aws-sdk');
var print = require('../helpers').printPretty;
AWS.config.update({region: 'us-west-2'});

var dynamoService = new AWS.DynamoDB({apiVersion: '2012-08-10'});

var params = {
    "TableName": "orderitems",
    "IndexName": "custid-prodid-index",
    "KeyConditionExpression":"custid = :cust ",
    "ExpressionAttributeValues":{
        ":cust":{"S":"7732"}
    }
};

var promise = dynamoService.query(params).promise();
promise
    .then(print)
    .catch(print);
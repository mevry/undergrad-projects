var AWS = require('aws-sdk');
AWS.config.update({region:"us-west-2"});
var print = require('../helpers').printPretty;
var dyn = new AWS.DynamoDB();


var params = {
    "TableName":"orders",
    "Key":{
        "orderid":{
            "S":"1234"
        },
        "custid":{
            "S":"7732"
        }
    },
    "ReturnConsumedCapacity":"TOTAL"
};

var promise = dyn.getItem(params).promise();

promise
    .then(print)
    .catch(print);
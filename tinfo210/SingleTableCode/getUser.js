var AWS = require('aws-sdk');
AWS.config.update({region:"us-west-2"});
var print = require('../helpers').printPretty;
var dyn = new AWS.DynamoDB();


var params = {
    "TableName":"dwf",
    "Key":{
        "pk":{
            "S":"cust-7732"
        },
        "sk":{
            "S":"d28@uw.edu"
        }
    },
    "ReturnConsumedCapacity":"TOTAL"
};

var promise = dyn.getItem(params).promise();

promise
    .then(print)
    .catch(print);
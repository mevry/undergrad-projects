var AWS = require('aws-sdk');
AWS.config.update({region:"us-west-2"});
var print = require('../helpers').printPretty;
var dyn = new AWS.DynamoDB();
var uuidv4 = require('uuid/v4');
var dateFormat = require('dateformat');
//Create An Individual User
var today = new Date();
let userId = 'd28@uw.edu';
let first = 'Derek';
let last = 'Miller';
//This Address format is recommended because it can help support
//queries that are interested in aggregating hierarchical data
let region = 'USA|WA|Seattle|123 Main St';
let zip = '98109'
let joinDate = dateFormat(today,"isoDate");

var params = {
    "TableName":"dwf",
    "Item":{
        "pk":{"S":`cust-${userId}`},
        "sk":{"S":joinDate},
        "first":{"S":first},
        "last":{"S":last},
        "region":{"S":region},
        "zip":{"S":zip}
    },
    "ReturnConsumedCapacity":"TOTAL"
};

var promise = dyn.putItem(params).promise();

promise
    .then(print)
    .catch(print);



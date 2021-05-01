var AWS = require('aws-sdk');
AWS.config.update({region: 'us-west-2'});
var print = require('../helpers').printPretty;
var dyn = new AWS.DynamoDB();

var listPromise = dyn.listTables({}).promise();
listPromise
   .then(print);


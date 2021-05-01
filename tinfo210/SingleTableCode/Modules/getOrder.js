
var AWS = require('aws-sdk');
AWS.config.update({region:"us-west-2"});
var print = require('../../helpers').printPretty;
var dyn = new AWS.DynamoDB();

function getOrder(orderId, custId){
    var params = {
        "TableName":"dwf",
        "Key":{
            "pk":{
                "S":"order-6257"
            },
            "sk":{
                "S":"cust-7732"
            }
        },
        "ReturnConsumedCapacity":"TOTAL"
    };

    var promise = dyn.getItem(params).promise();

    promise
        .then(print)
        .catch(print);
}
module.exports.getOrder = getOrder

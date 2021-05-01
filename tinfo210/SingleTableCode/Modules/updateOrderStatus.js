var AWS = require('aws-sdk');
AWS.config.update({region:"us-west-2"});
var print = require('../../helpers').printPretty;
var dyn = new AWS.DynamoDB();

function updateOrderStatus(orderId, custId, newStatus){
    var params = {
        "TableName":"dwf",
        "Key":{
            "pk":{
                "S":orderId
            },
            "sk":{
                "S":custId
            }
        },
        "ExpressionAttributeNames":{
            "#attr1":"gsi1-sk"
        },
        "ExpressionAttributeValues":{
            ":val1":{S:newStatus}
        },
        "UpdateExpression":"SET #attr1 = :val1",
        "ReturnValues":"ALL_NEW",
        "ReturnConsumedCapacity":"TOTAL"
    };

    var promise = dyn.updateItem(params).promise();

    promise
        .then(print)
        .catch(print);

}
module.exports.updateOrderStatus = updateOrderStatus
updateOrderStatus('order-17bdb5c9-4e66-41b0-ba41-84e61d4a4fd2', 'cust-d28@uw.edu', 'FILLED')
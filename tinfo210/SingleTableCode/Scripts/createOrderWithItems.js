//Use this script to run multiple create orders
var createOrderWithItems = require("../Modules/createOrderWithItems").createOrderWithItems

//Pending Promise Array
let allQueries = []

//Start timer for all queries
console.time('ALL_QUERIES')

//Run each query async
let totalTime1 = createOrderWithItems('cust-d28@uw.edu', 1);
allQueries.push(totalTime1)
// let totalTime2 = createOrderWithItems('cust-d28@uw.edu', 10);
// allQueries.push(totalTime2)
// let totalTime3 = createOrderWithItems('cust-d28@uw.edu', 100);
// allQueries.push(totalTime3)
// let totalTime4 = createOrderWithItems('cust-d28@uw.edu', 1000);
// allQueries.push(totalTime4)

// Once all queries have completed,
// stop timer
Promise.all(allQueries).then(
    function(){
        console.timeEnd('ALL_QUERIES')
    }
);

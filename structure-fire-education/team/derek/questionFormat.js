//For True/False Questions:
{
  type: "tf",
  question: "Your question here.",
  answer:[true]//must be true or false (lowercase) in brackets
}

//for multiple choice
{
  type:"multi",
  question: "Question goes here."
  answer:[1],//pick the number that matches the key of the answer below
  //You can have as many choices as you want, but four is a good standard
  //Make sure the key of the correct choice matches the answer key above.
  options:[
    {
      key:0,
      value:"Choice 1"
    },
    {
      key:1,
      value:"Choice 2"

    },
    {
      key:2,
      value:"Choice 3"
    },
    {
      key:3,
      value:"Choice 4"
    }
  ]
}
//Fill in the blank (only supports one blank)
{
  type:"fill",
  question:{
    partOne:"The first part of the question goes here",
    partTwo:"The second part goes here"
  },
  answer:["correct answers here", "because maybe different answers are also correct", 15]
}

//Question bank:
//Split into five columns (which are just arrays)
//position in the array determines point value
//ie columnOne[0] worth 100 points, columnOne[4] worth 500 points
{
  columnOne:[
  {
    type:"tf",
    question:"Your home should have a smoke detector to warn you in case of a smoke emergency.",
    answer:[true],
  },
  {
    type:"multi",
    question:"This will allow you to escape from 2nd story houses.",
    answer:[3],
    options:[
      {
        key:0,
        value:"Trampoline"
      },
      {
        key:1,
        value:"Parachute"

      },
      {
        key:2,
        value:"Giant Drone"
      },
      {
        key:3,
        value:"Rope Ladder"
      }
    ]
  },
  {
    type:"tf",
    question:"You should have less than two escape routes per room.",
    answer:[false]
  },
  {
    type:"fill",
    question:{
      partOne:"You should practice a family escape plan",
      partTwo:"times per year.",
    },
    answer:["two", 2]
  },
  {
    type:"multi",
    question:"Your family should use this to gather together after a home fire.",
    answer:[0],
    options:[
      {
        key:0,
        value:"A Meeting Place"
      },
      {
        key:1,
        value:"Sushi"

      },
      {
        key:2,
        value:"Smoke Detector"
      },
      {
        key:3,
        value:"Rope Ladder"
      }
    ]
  }
],
columnTwo:[

],
columnThree:[

],
columnFour:[

],
columnFive:[

]
}

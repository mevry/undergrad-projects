let questionBank = {
    columnOne:[
      {
        type:"tf",
        question:"Your home should have a smoke detector to warn you in case of a smoke emergency.",
        answer:[true],
      },
      {
        type:"multi",
        question:"This will allow you to escape from the 2nd story of a building.",
        answer:[3],
        options:[
          {
            key:0,
            value:"Trampoline",
            selected:false
          },
          {
            key:1,
            value:"Parachute",
            selected:false

          },
          {
            key:2,
            value:"Giant Drone",
            selected:false
          },
          {
            key:3,
            value:"Rope Ladder",
            selected:false
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
        answer:["two", "2"]
      },
      {
        type:"multi",
        question:"Your family should use this to gather together after a home fire.",
        answer:[0],
        options:[
          {
            key:0,
            value:"A Meeting Place",
            selected:false
          },
          {
            key:1,
            value:"Sushi",
            selected:false

          },
          {
            key:2,
            value:"Smoke Detector",
            selected:false
          },
          {
            key:3,
            value:"Rope Ladder",
            selected:false
          }
        ]
      }
    ],
    columnTwo:[
      {
        type:"tf",
        question:"Fire requires heat, fuel and air to continue burning. This referred to as the fire triangle in the US",
        answer:[true],
      },
      {
        type:"multi",
        question:"This is the most common type of fire - consisting of combustible materials",
        answer:[3],
        options:[
          {
            key:0,
            value:"Class B",
            selected:false
          },
          {
            key:1,
            value:"Class D",
            selected:false
          },
          {
            key:2,
            value:"Class F",
            selected:false
          },
          {
            key:3,
            value:"Class A",
            selected:false
          }
        ]
      },
      {
        type:"tf",
        question:"Smoke inhalation is a minor nuisance during fire scenarios.",
        answer:[false]
      },
      {
        type: "tf",
        question: "Fire is threat to very few people.",
        answer: [false]
      },
      {
        type:"multi",
        question:"This type of fire favors liquids and other combustible fluids.",
        answer:[0],
        options:[
          {
            key:0,
            value:"Class B",
            selected:false
          },
          {
            key:1,
            value:"Class C",
            selected:false

          },
          {
            key:2,
            value:"Class Z",
            selected:false
          },
          {
            key:3,
            value:"Class A",
            selected:false
          }
        ]
      }
    ],
    columnThree:[
      {
        type:"tf",
        question:"A lawnmower is best fueled outside a good distance away from any buildings.",
        answer:[true],
      },
      {
        type:"multi",
        question:"This is a good spot to pitch your tent in relation to your campfire.",
        answer:[3],
        options:[
          {
            key:0,
            value:"Upwind",
            selected:false
          },
          {
            key:1,
            value:"Parallel",
            selected:false

          },
          {
            key:2,
            value:"On top of the campfire",
            selected:false
          },
          {
            key:3,
            value:"Downwind",
            selected:false
          }
        ]
      },
      {
        type:"tf",
        question:"Instead of a lit flame, it'd be best to use a flashlight (or battery powered lantern) to light your tent at night",
        answer:[true]
      },
      {
        type:"fill",
        question:{
          partOne:"Propane or charcoal grills should only be used",
          partTwo:" and never used inside.",
        },
        answer:["outside"]
      },
      {
        type:"multi",
        question:"One of these should be present whenever an outdoor grill or fireplace is being used in your home",
        answer:[0],
        options:[
          {
            key:0,
            value:"An adult",
            selected:false
          },
          {
            key:1,
            value:"A dog",
            selected:false

          },
          {
            key:2,
            value:"A cellphone",
            selected:false
          },
          {
            key:3,
            value:"A police officer",
            selected:false
          }
        ]
      }
    ],
    columnFour:[
      {
        type:"tf",
        question:"A fire axe is a tool that can be used by firefighters to break down doors and windows that bar entry.",
        answer:[true],
      },
      {
        type:"multi",
        question:"A small tool that can be used by adults to fight, small contained fires after everyone has evacuated the building",
        answer:[3],
        options:[
          {
            key:0,
            value:"An open soda",
            selected:false
          },
          {
            key:1,
            value:"Dirt",
            selected:false

          },
          {
            key:2,
            value:"Towel",
            selected:false
          },
          {
            key:3,
            value:"Fire extinguisher",
            selected:false
          }
        ]
      },
      {
        type:"tf",
        question:"When a fire alarms sounds, you should quickly and calmly find the nearest exit and evacuate",
        answer:[true]
      },
      {
        type:"fill",
        question:{
          partOne:"A fire",
          partTwo:"is a long hollow tube capped with a nozzle that allows water to be shot onto fires",
        },
        answer:["hose"]
      },
      {
        type:"multi",
        question:"These are automatic firefighting tools that are supposed to trigger automatically in event of a fire",
        answer:[0],
        options:[
          {
            key:0,
            value:"Indoor Sprinkler system",
            selected:false
          },
          {
            key:1,
            value:"Air Conditioning",
            selected:false

          },
          {
            key:2,
            value:"Automatic blast doors",
            selected:false
          },
          {
            key:3,
            value:"Strobe lights",
            selected:false
          }
        ]
      }
    ],
    columnFive: [
      {
        type: "tf",
        question: "The kitchen is the most common space in the home for fires.",
        answer: [true]
      },
      {
        type: "fill",
        question: {
          partOne: "When in public, you should be aware of all the possible",
          partTwo: "of the buildings you enter.",
        },
        answer: ["exits", "exit"]
      },
      {
        type: "multi",
        question: "If your clothes catch fire, this is a good response.",
        answer: [0],
        options: [
          {
            key: 0,
            value: "Stop, drop, and roll.",
            selected:false
          },
          {
            key: 1,
            value: "Drink Mountain Dew.",
            selected:false

          },
          {
            key: 2,
            value: "Dab",
            selected:false
          },
          {
            key: 3,
            value: "Read a book",
            selected:false
          }
        ]
      },
      {
        type:"tf",
        question:"The front of your hand is the best way to test for heat when opening a door during fire.",
        answer:[false],
      },
      {
        type:"multi",
        question:"This is the best time to re-enter a burning building",
        answer:[3],
        options:[
          {
            key:0,
            value:"Any time on Tuesdays",
            selected:false
          },
          {
            key:1,
            value:"Before Sundown",
            selected:false

          },
          {
            key:2,
            value:"12pm",
            selected:false
          },
          {
            key:3,
            value:"Never",
            selected:false
          }
        ]
      }
    ]
 };




export default questionBank;
<template>
  <div id="rootContainer" class="container-fluid text-center h-100" >
    <div id="stopDropRollMatch" >
      <h1 class="neon-yellow">Drag &amp; Match</h1>
      <p>Rearrange the elements below to earn a badge!</p>
      <h3 class="mt-5">What should you do if you are on fire?</h3>
      <draggable
      v-model="stopDropRollAnswers"
      @start="drag=true"
      @end="checkStopDropRollAnswers"
      
      class="row">
        <div  class="col" v-for="item in stopDropRollAnswers" :key="item.id" >
          <h2 :class="[{win : stopDropRollComplete}]" class="drag-item" :style="{ backgroundColor: item.color }">{{item.val}}</h2>
        </div>
      </draggable>
    </div><!--stopDropRollMatch-->

      <div id="fireClassMatch">
        <h3 class="mt-5">Match the fire types with their class.</h3>
        <div class="d-flex justify-content-around">
          <div class="col mx-3" v-for="item in fireClassQuestions" :key="item.id">
            <h1>{{item.val}}</h1>
          </div>
        </div>


      <div class="d-flex justify-content-around">
        <!--Drop Zone 1-->
        <div tag="div"  class="drop-zone-container ">
          <draggable
            v-model="fireClassDropZone.one"
            @add="checkIfSlotFull('one')"
            @remove="checkIfSlotFull('one')"
            @end="checkFireClassAnswers"
            :options="dropZoneOptions.one"
            id="dropZoneOne" 
            class="drop-zone"
            :class="[{win : fireClassComplete}]">
              <div  v-for="item in fireClassDropZone.one" :key="item.id">
                <img class="img-fluid" :src="item.url" />
                <h6>{{item.desc}}</h6>
              </div>
          </draggable>

        </div>

        <!--Drop Zone 2-->
        <div class="drop-zone-container">
          <draggable
            v-model="fireClassDropZone.two"
            @add="checkIfSlotFull('two')"
            @remove="checkIfSlotFull('two')"
            @end="checkFireClassAnswers"
            :options="dropZoneOptions.two"
            id="dropZoneTwo"
            class="drop-zone"
            :class="[{win : fireClassComplete}]">
              <div  v-for="item in fireClassDropZone.two" :key="item.id">
                <img class="img-fluid" :src="item.url" />
                <h6>{{item.desc}}</h6>
              </div>
            </draggable>
        </div>

        <!--Drop Zone 3-->
        <div class="drop-zone-container">
          <draggable
            v-model="fireClassDropZone.three"
            @add="checkIfSlotFull('three')"
            @remove="checkIfSlotFull('three')"
            @end="checkFireClassAnswers"
            :options="dropZoneOptions.three"
            id="dropZoneThree"
            class="drop-zone"
            :class="[{win : fireClassComplete}]">
              <div  v-for="item in fireClassDropZone.three" :key="item.id">
                <img class="img-fluid" :src="item.url" />
                <h6>{{item.desc}}</h6>
              </div>
            </draggable>
        </div>

        <!--Drop Zone 4-->
        <div class="drop-zone-container">
          <draggable
            v-model="fireClassDropZone.four"
            @add="checkIfSlotFull('four')"
            @remove="checkIfSlotFull('four')"
            @end="checkFireClassAnswers"
            :options="dropZoneOptions.four"
            id="dropZoneFour"
            class="drop-zone"
            :class="[{win : fireClassComplete}]">
              <div  v-for="item in fireClassDropZone.four" :key="item.id">
                <img class="img-fluid" :src="item.url" />
                <h6>{{item.desc}}</h6>
              </div>
            </draggable>
        </div>

        <!--Drop Zone 5-->
        <div class="drop-zone-container">
          <draggable
            v-model="fireClassDropZone.five"
            @add="checkIfSlotFull('five')"
            @remove="checkIfSlotFull('five')"
            @end="checkFireClassAnswers"
            :options="dropZoneOptions.five"
            id="dropZoneFive"
            class="drop-zone"
            :class="[{win : fireClassComplete}]">
              <div v-for="item in fireClassDropZone.five" :key="item.id">
                <img class="img-fluid" :src="item.url" />
                <h6>{{item.desc}}</h6>
              </div>
            </draggable>
        </div>
      </div>


      <!--Pull From List-->
      <draggable
      v-model="fireClassAnswers"
      @remove="checkFireClassAnswers"
      :options="{group:'fire-class'}"
      id="sourceZone"
      class="d-flex justify-content-around mt-3 py-3">
        <div class="col" v-for="item in fireClassAnswers" :key="item.id">
          <img class="drag-image" :src="item.url" />
          <h6>{{item.desc}}</h6>
        </div>
      </draggable>
    </div><!--fireClassMatch-->
</div><!--container-->
</template>
<script>
import draggable from 'vuedraggable'
import store from '../store'
import EventBus from '../event-bus'
//import BadgeModal from '../components/BadgeEarned'
import ClassA from '../img/dragA.png'
import ClassB from '../img/dragB.png'
import ClassC from '../img/dragC.png'
import ClassD from '../img/dragD.png'
import ClassK from '../img/dragK.png'
export default {
  name: 'drag-drop',
  data(){
    return{
      stopDropRollAnswers:[
        {id:3,val:"Roll",color:"#d81167"},
        {id:1,val:"Stop",color:"#0d41db"},
        {id:2,val:"Drop",color:"#0ed3c8"}
      ],
      fireClassQuestions:[
        {id:1,val:"A"},
        {id:2,val:"B"},
        {id:3,val:"C"},
        {id:4,val:"D"},
        {id:5,val:"K"},
      ],
      fireClassDropZone:{
        one:[],
        two:[],
        three:[],
        four:[],
        five:[]
      },
      fireClassAnswers:[
        {id:3,url:ClassC,desc:""},
        {id:4,url:ClassD,desc:""},
        {id:5,url:ClassK,desc:""},
        {id:1,url:ClassA,desc:""},
        {id:2,url:ClassB,desc:""}
      ],
      stopDropRollComplete:false,
      fireClassComplete:false,
      sharedState:store.state,
      dropZoneOptions:{
        one:{
          group:{
            name:'fire-class',
            put:true
          },
          animation:150
        },
        two:{
          group:{
            name:'fire-class',
            put:true
          }
        },
        three:{
          group:{
            name:'fire-class',
            put:true
          }
        },
        four:{
          group:{
            name:'fire-class',
            put:true
          }
        },
        five:{
          group:{
            name:'fire-class',
            put:true
          }
        }
      }
    }
  },
  components:{
    draggable
  },
  computed:{
    DragDropComplete(){
      return this.sharedState.DragDropPass
    }
  },
  methods:{
    emitMethod(evt,payload){
      EventBus.$emit(evt, payload);
    },
    checkDragAndDropComplete(){
      if(this.stopDropRollComplete && this.fireClassComplete){
        this.sharedState.DragDropPass = true;
        this.emitMethod('activity-completed', {activity:"Drag & Match", completed:true});
        console.log('Drag & Drop Completed');
      }
    },
    checkStopDropRollAnswers(){
      if(this.stopDropRollAnswers[0].id == 1 &&
         this.stopDropRollAnswers[1].id == 2 &&
         this.stopDropRollAnswers[2].id == 3){
        this.stopDropRollComplete = true;
        console.log("Stop, Drop, & Roll Drag & Drop Completed");
        this.checkDragAndDropComplete();
      }
    },
    checkFireClassAnswers(){
      console.log("checkFireClassAnswers fired.")
      if(!this.fireClassAnswers.length){
        if(this.fireClassDropZone.one[0].id == 1 &&
          this.fireClassDropZone.two[0].id == 2 &&
          this.fireClassDropZone.three[0].id == 3 &&
          this.fireClassDropZone.four[0].id == 4 &&
          this.fireClassDropZone.five[0].id == 5){
          this.fireClassComplete = true;
          console.log("Fire Class Drag & Drop Completed");
          this.checkDragAndDropComplete();
        }
      }
    },
    checkIfSlotFull(zoneNumber){
      if(this.fireClassDropZone[zoneNumber].length > 0){
        this.dropZoneOptions[zoneNumber].group.put = false;
        this.$emit('zone-drop',{})
      }else{
        this.dropZoneOptions[zoneNumber].group.put = true;
      }
    }
  }
};
</script>
<style lang="scss" scoped>
  #rootContainer{
    font-family: 'Century Gothic', sans-serif;
    color: white;
  }
  .drag-item{
    border: 1px solid rgba(80,80,80, .4);
    box-shadow: 1px 1px 2px rgba(40,40,40, .4);
    padding: 1em;
    border-radius: 24px;
    text-shadow: 1px 1px 1px rgba(0, 0, 0, 0.5);

  }
  .drag-item:hover,.drag-image:hover{
    cursor: all-scroll;
  }
  .win{
    box-shadow: 0 0 16px 6px #0ee42a !important;
  }
  .drop-zone-container{
    height: 150px;
    width: 150px;
  }
  .drop-zone{
    min-height: 150px;
   background-color:white;

   border-radius: 50%;
    padding: 0;
    box-shadow: inset 1px 1px 2px black;

  }
  #sourceZone{
    min-height: 150px;
  }
  .drag-image{
    width:150px;
  }
</style>

<template>
  <div class="container-fluid">
      <jeopardy-modal v-if="showJeopardyModal" :questionObject="currentQuestion" :pointValue="currentQuestionPV" @submission="showJeopardyModal = false">

      </jeopardy-modal>
      <div class="col-8 offset-2">
        <h1 class="text-center neon-yellow">Jeopardy</h1>
        <p class="text-center white-font">Select the tiles below and answer the question. You will get points for a correct answer. Get 6000 points to earn a badge!</p>
      </div>

      <div id="jeopardyBody" class="p-4">
        <div id="jeopardyHeaderRow" class="row text-center pb-1 mb-3">
          <div class="jeopardy-header col"><h5>Home<br> Safety</h5></div>
          <div class="jeopardy-header col"><h5>Fire<br> Concepts</h5></div>
          <div class="jeopardy-header col"><h5>Outdoor<br> Safety</h5></div>
          <div class="jeopardy-header col"><h5>Firefighting<br> Methods</h5></div>
          <div class="jeopardy-header col"><h5>Emergency<br> Cases</h5></div>
        </div>
        <div class="row">
          <div class="col">
            <div v-for="(question,index) in questionBank.columnOne"
                :key="question[index]"
                class="jeopardy-cell col py-3 mb-2 h2"
                :class="{'correct': questionBank.columnOne[index].correct, 'incorrect':questionBank.columnOne[index].incorrect}"
                @click="!questionBank.columnOne[index].clickState && renderJeopardyModal('columnOne',index)">
                {{(index+1)*100}}
            </div>
          </div>
          <div class="col">
            <div v-for="(question,index) in questionBank.columnTwo"
                :key="question[index]"
                class="jeopardy-cell col py-3 mb-2 h2"
                :class="{'correct': questionBank.columnTwo[index].correct, 'incorrect':questionBank.columnTwo[index].incorrect}"
                @click="!questionBank.columnTwo[index].clickState && renderJeopardyModal('columnTwo',index)">
                {{(index+1)*100}}
            </div>
          </div>
          <div class="col">
            <div v-for="(question,index) in questionBank.columnThree"
                :key="question[index]"
                class="jeopardy-cell col py-3 mb-2 h2"
                :class="{'correct': questionBank.columnThree[index].correct, 'incorrect':questionBank.columnThree[index].incorrect}"
                @click="!questionBank.columnThree[index].clickState && renderJeopardyModal('columnThree',index)">
                {{(index+1)*100}}
            </div>
          </div>
          <div class="col">
            <div v-for="(question,index) in questionBank.columnFour"
                :key="question[index]"
                class="jeopardy-cell col py-3 mb-2 h2"
                :class="{'correct': questionBank.columnFour[index].correct, 'incorrect':questionBank.columnFour[index].incorrect}"
                @click="!questionBank.columnFour[index].clickState && renderJeopardyModal('columnFour',index)">
                {{(index+1)*100}}
            </div>
          </div>
          <div class="col">
            <div v-for="(question,index) in questionBank.columnFive"
                :key="question[index]"
                class="jeopardy-cell col py-3 mb-2 h2"
                :class="{'correct': questionBank.columnFive[index].correct, 'incorrect':questionBank.columnFive[index].incorrect}"
                @click="!questionBank.columnFive[index].clickState && renderJeopardyModal('columnFive',index)">
                {{(index+1)*100}}
            </div>
          </div>
        </div><!--End row-->
        <div class="row align-items-center px-3"><h4 class="mb-0" @submission="updatePoints()"><strong>Current Points:</strong> {{score}}</h4>
        <div v-if="attemptedQuestions >= 25" class="ml-auto"><button @click="resetJeopardy()" class="btn btn-warning">Reset Activity</button></div></div>      
      </div><!--End jeopardyBody-->
  </div>
</template>
<script>
import JeopardyModal from './JeopardyModal.vue'
import EventBus from '../event-bus'
import store from '../store'
import QuestionBank from '../questionBank.js'
export default {
  name: 'jeopardy',
  data(){
    return{
      showJeopardyModal:false,
      currentQuestion:{},
      currentQuestionPV:0,
      score:0,
      attemptedQuestions: 0,
      sharedState:store.state,
      questionBank:QuestionBank,
    }
  },
  methods:{
    renderJeopardyModal(col,pos){
      this.currentQuestion = this.questionBank[col][pos];
      this.currentQuestion.clickState = true;
      this.attemptedQuestions++;
      this.updateQuestionPV(pos);
      this.showJeopardyModal = true;
    },
    updateQuestionPV(position){
     this.currentQuestionPV = (position+1)*100;
    },
    updatePoints(correct){
      this.showJeopardyModal = false
      console.log("current point val: " + this.currentQuestionPV)
      if(correct){
        this.score += this.currentQuestionPV;
        this.currentQuestion.correct = correct
      }else{
        this.currentQuestion.incorrect = true
      }
      this.checkJeopardyComplete();
    },
    checkJeopardyComplete(){
      if(this.attemptedQuestions >= 25){
        if(this.score / 7500 >= .75){
          this.sharedState.JeopardyScore = this.score;
          this.emitMethod('activity-completed', {activity:"Jeopardy", completed:true});
          console.log('Jeopardy Completed');
        }else{
          this.emitMethod('activity-completed', {activity:"Jeopardy", completed:false});
          console.log('Jeopardy Incomplete')
        }
      }
    },
    resetJeopardy(){

      for (var column in this.questionBank){
        let currentColumn = this.questionBank[column]
        for(var i = 0; i < currentColumn.length;i++){
          this.$delete(currentColumn[i], 'clickState')
          this.$delete(currentColumn[i], 'correct')
          this.$delete(currentColumn[i], 'incorrect')
        }
        this.sharedState.JeopardyScore = 0;
        this.score = 0;
        this.currentQuestion = null;
        this.attemptedQuestions = 0;
        this.currentQuestionPV = null;
      }
    },
    emitMethod(evt,payload){
      EventBus.$emit(evt,payload);
    }
  },
  components:{
    'jeopardy-modal':JeopardyModal
  },
  mounted(){
    EventBus.$on('submission', this.updatePoints);
  }
};
</script>
<style lang="scss" scoped>
#jeopardyBody{
   background-color: rgba(255,255,255,.8);
   border-radius: 4px;
   box-shadow: 1px 1px 3px rgba(41, 38, 80, .5);
 }
 .jeopardy-cell{
   background-color: white;
   text-align: center;
   cursor: pointer;
   border: 1px solid rgba(180, 180, 180, 0.75);
    border-radius: 3px;
 }
 .clicked{
   cursor: default;
   background-color: lightgray;
 }
 #jeopardyHeaderRow{
   border-bottom: 1px solid gray;
 }
 .jeopardy-header{
   >h5{
     font-weight: bold;
   }
 }
 .correct{
   background-color: #eaffec;
   box-shadow: inset 0 0 20px #0ee42a;
   color:#8ea991;
   cursor: default;
 }
.incorrect{
  background-color: #ffeaea;
  box-shadow: inset 0 0 20px #e40e0e;
  color:#a98e8e;
  cursor: default;
}
</style>

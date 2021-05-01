<template>
  <transition name="modal">
    <div class="modal-mask">
      <div class="modal-wrapper">
        <div class="modal-container">

            <form @submit.prevent>
                <div class="true-false" v-if="questionObject.type == 'tf'">
                    <div class="modal-header d-flex justify-content-between">
                        <h3>True / False</h3><br>
                        <h3>{{pointValue}} Points</h3>
                    </div>
                    <div class="modal-body">
                        <h4>{{questionObject.question}}</h4><br>

                        <div class="d-flex justify-content-center text-center">
                            <div class="tf-selection col py-3 mx-1" @click="toggleTf(1)" :class="{'selected':trueSelect}">
                                <h3>True</h3>
                            </div>
                            <div class="tf-selection col py-3 mx-1" @click="toggleTf(0)" :class="{'selected':falseSelect}"><h3>False</h3></div>
                        </div>
                    </div>
                </div><!--End true-false-->
                <div class="multi" v-else-if="questionObject.type == 'multi'">
                    <div class="modal-header d-flex justify-content-between">
                        <h3>Multiple Choice</h3><br>
                        <h3>{{pointValue}} Points</h3>
                    </div>
                    <div class="modal-body">
                        <h4>{{questionObject.question}}</h4><br>
                        <div class="form-group">
                            <div class="d-flex flex-wrap">
                              <div v-for="option in questionObject.options" :key="option.key" class="col-6 mt-2 text-center px-1">
                                  <div @click="toggleMulti(option.key)" class="multi-selection py-3"  :class="{'selected':option.selected}" style="height:100%;"><h4>{{option.value}}</h4></div>
                              </div>
                            </div>

                        </div>
                    </div>

                </div><!--End multi-->
                <div class="fill" v-else-if="questionObject.type == 'fill'">
                    <div class="modal-header d-flex justify-content-between">
                        <h3>Fill In The Blank</h3><br>
                        <h3>{{pointValue}} Points</h3>
                    </div>
                    <div class="modal-body">
                        <h4>{{questionObject.question.partOne}} <input type="text" name="fill" v-model.lazy="fillAnswer" style="width:150px; padding-left: 6px;"> {{questionObject.question.partTwo}}</h4>
                    </div>
                </div><!--End fill-->

                <div class="d-flex justify-content-between">

                    <slot name="footer">
                        <button class="btn btn-primary" @click="checkAnswer">
                        <strong>SUBMIT</strong>
                        </button>
                    </slot>
                    <h2 id="feedback" v-if="answerCorrect == 'Correct!'" style="color:rgb(0, 136, 107)"><strong>{{answerCorrect}}</strong></h2>
                    <h2 id="feedback" v-else-if="answerCorrect == 'Incorrect'" style="color:red"><strong>{{answerCorrect}}</strong></h2>
                    <h4 id="feedback" v-else-if="answerCorrect == 'Please answer the question'">{{answerCorrect}}</h4>
                </div>
            </form>

        </div><!--modal-container-->
      </div><!--modal-wrapper-->
    </div><!--modal-mask-->
  </transition>
</template>
<script>
import EventBus from '../event-bus'
export default {
  name:"jeopardy-modal",
  props:['questionObject', 'pointValue'],
  data(){
      return{
          tfAnswer:null,
          multiAnswer:null,
          fillAnswer:'',
          trueSelect:null,
          falseSelect:null,
          answerCorrect:'',
          selectedAnswer:false
      }
  },
  computed:{
      boolAnswer(){
          if(this.tfAnswer == 0){
              return false;
          }else{
              return true;
          }
      },
      fillAnswerLower(){
        return this.fillAnswer.toLowerCase();
      }
  },
  methods:{
      toggleTf(answer){
          this.selectedAnswer = true;
          if(answer == 0){
              this.trueSelect = false;
              this.falseSelect = true;
              this.tfAnswer = 0;
          }else{
              this.trueSelect = true;
              this.falseSelect = false;
              this.tfAnswer = 1;
          }
      },
      toggleMulti(val){
        this.selectedAnswer = true;
        let questionArray = this.$props.questionObject.options;
        for(let i = 0; i < questionArray.length; i++){
          if(questionArray[i].key != val){
            questionArray[i].selected = false;
          }else{
            questionArray[i].selected = true;
            this.multiAnswer = questionArray[i].key;
          }

        }
      },
      checkAnswer(){
        if(this.selectedAnswer == true || this.fillAnswer.length > 0){
            let correctAnswer = this.$props.questionObject.answer;
            let questionType = this.$props.questionObject.type;
                let userAnswer;
            if(questionType == 'tf'){
                userAnswer = this.boolAnswer
            }else if(questionType == 'multi'){
                userAnswer = this.multiAnswer
            }else{
                userAnswer = this.fillAnswerLower
            }

            let found = correctAnswer.includes(
                userAnswer
            );
            if(found){
                this.answerCorrect = "Correct!"
            }else{
                this.answerCorrect = "Incorrect"
            }
        this.selectedAnswer = false;

           let self = this;
           setTimeout(function(){
                self.emitMethod('submission',found);
                if(questionType == 'tf'){
                    self.trueSelect = false;
                    self.falseSelect = false;
                }else if(questionType == 'multi'){
                    let questionArray = self.$props.questionObject.options;
                    for(let i = 0; i < questionArray.length; i++){
                        questionArray[i].selected = false;
                    }
                }else{
                    self.fillAnswer = '';
                }
            }, 750);
        }else{
          this.answerCorrect = "Please answer the question";
        }
      },
      emitMethod(evt,payload){
          EventBus.$emit(evt,payload);
      }
  }
}
</script>
<style lang="scss" scoped>
  .modal-mask {
  position: fixed;
  z-index: 9998;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;
  background-color: rgba(0, 0, 0, .5);
  display: table;
  transition: opacity .3s ease;
}

.modal-wrapper {
  display: table-cell;
  vertical-align: middle;
}

.modal-container {
  width: 60%;
  margin: 0px auto;
  padding: 20px 30px;
  background-color: #fff;
  border-radius: 2px;
  box-shadow: 0 2px 8px rgba(0, 0, 0, .33);
  transition: all .3s ease;

}

.modal-header h3 {
  margin-top: 0;
  color:  rgb(0, 53, 42);
}

.modal-body {
  margin: 20px 0;
}



/*
 * The following styles are auto-applied to elements with
 * transition="modal" when their visibility is toggled
 * by Vue.js.
 *
 * You can easily play with the modal transition by editing
 * these styles.
 */

.modal-enter {
  opacity: 0;
}

.modal-leave-active {
  opacity: 0;
}

.modal-enter .modal-container,
.modal-leave-active .modal-container {
  -webkit-transform: scale(1.1);
  transform: scale(1.1);
}
.tf-selection, .multi-selection{
    padding: 5px;
    border: 1px solid gray;
    border-radius: 5px;
    cursor: pointer;
}
.selected{
    border-color: rgb(0, 136, 107);
    background-color: rgb(103, 255, 222);
    color: rgb(0, 53, 42)
}
#feedback{
    color:rgb(149, 0, 255);
}
</style>

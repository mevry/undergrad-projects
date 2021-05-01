<template>
  <transition name="modal">
    <div class="modal-mask">
      <div class="modal-wrapper">
        <div class="modal-container text-center">

          <div class="">
            <h3>
              {{activity}} {{completionStatus}}
            </h3>
          </div>


            <div>
              <h4 name="body">
                {{returnMessage}}
                </h4>

                  <img class="badge-img" :src="badgeUrl" alt="Badge Earned">

            </div>



          <div class="">

              <div><h5>You have {{badgeQuantity}} of 3 badges.</h5></div>
              <button class="btn btn-lg btn-success" @click="closeBadgeModal">
                OK
              </button>

          </div>

        </div><!--modal-container-->
      </div><!--modal-wrapper-->
    </div><!--modal-mask-->
  </transition>
</template>
<script>
import store from '../store'
import EventBus from '../event-bus'
import badgeDrag from '../img/badgeDrag.png'
import badgeMemory from '../img/badgeMemory.png'
import badgeJepGold from '../img/badgeJepGold.png'
import badgeJepSilver from '../img/badgeJepSilver.png'
import badgeJepBronze from '../img/badgeJepBronze.png'

export default {
  name:"badge-earned-modal",
  props:['completed','activity'],
  data(){
    return{
      sharedState:store.state,
    }
  },
  computed:{
    propsObject(){
      return JSON.stringify(this.activity)
    },
    returnMessage(){
      if(this.completed){
        return "You earned a badge!"
      }else{
        return "Please reset the activity and try again."
      }
    },
    completionStatus(){
      if(this.completed){
        return "Completed"
      }else{
        return "Incomplete"
      }
    },
    badgeUrl(){
      if(this.activity == "Drag & Match"){
        return badgeDrag
      }else if(this.activity == "Memory"){
        return badgeMemory
      }else if(this.activity == "Jeopardy"){
        if((this.sharedState.JeopardyScore / 7500) >= .9 ){
            return badgeJepGold
        }else if((this.sharedState.JeopardyScore / 7500) > .8){
            return badgeJepSilver
        }else if((this.sharedState.JeopardyScore / 7500) > .75 ){
            return badgeJepBronze
        }
      }
    },
    badgeQuantity(){
      let qty = 0;
      if((this.sharedState.JeopardyScore / 7500) >= .75 ){
        qty++
      }
      if(this.sharedState.DragDropPass){
        qty++
      }
      if(this.sharedState.MemoryPass){
        qty++
      }

      return qty;

    },
  },
  methods:{
    closeBadgeModal(){
      this.$emit('close');
      this.$router.push('/');
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
  width: 300px;
  margin: 0px auto;
  padding: 20px 30px;
  background-color: #fff;
  border-radius: 2px;
  box-shadow: 0 2px 8px rgba(0, 0, 0, .33);
  transition: all .3s ease;
  font-family: Helvetica, Arial, sans-serif;
}
.badge-img{
  transition: all 1s ease;
  transition-delay: 5s;
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
</style>

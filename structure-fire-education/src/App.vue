<template>
  <div class="container" style="height:80%;">
    <badge-modal v-if="showModal" :completed="completed" :activity="activity" @close="showModal = false"></badge-modal>
    <site-header class="d-print-none"></site-header>
    <detail-bar class="d-print-none"></detail-bar>
      <transition name="fade" mode="out-in">
        <keep-alive>
          <router-view></router-view>
        </keep-alive>
      </transition>
  </div>
</template>

<script>
import Header from './components/SiteHeader.vue'
import store from './store.js'
import DetailBar from './components/DetailBar.vue'
import BadgeModal from './components/BadgeModal.vue'
import EventBus from './event-bus'
import background from './img/bg1.png'
export default {
  name: 'app',
  data () {
    return {
      sharedState: store.state,
      showModal:false,
      completed:false,
      activity:'',
      enterInfo:false
    }
  },
  components:{
    'site-header':Header,
    'detail-bar':DetailBar,
    'badge-modal':BadgeModal
  },
  mounted(){

    let self = this;
    EventBus.$on('activity-completed', function(payload){
      console.log('ACTIVITY COMPLETED')
      self.completed = payload.completed;
      self.activity = payload.activity;
      setTimeout(function(){
        self.showModal = true;
      }, 700);
      
    });
  }
}
</script>

<style lang="scss">
@import '../node_modules/bootstrap/scss/bootstrap.scss';
body{
    font-family: 'Century Gothic', Helvetica, serif;
    background: url('./img/bg1.png') no-repeat;
    background-size: cover;
     background-color: #1217ad;
     color:rgb(0, 0, 0);
}

//component transitions
.fade-enter-active, .fade-leave-active{
  transition: all .4s ease;
}
.fade-enter, .fade-leave-to{
  opacity: 0;
}
@page {
  size:auto
}
.white-font{
  color:white;
}
.neon-yellow{
  color: #e3ff2c;
}
  .btn-warning{
    background-color: #e3ff2c;
    &:hover{
      background-color: darken(#e3ff2c,15%);
    }
    border-color: darken(#e3ff2c,15%);
  }
</style>

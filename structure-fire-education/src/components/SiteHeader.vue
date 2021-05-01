<template>
  <header>
    <nav class="d-flex justify-content-between">
      <router-link to="/" class="nav-item nav-link"><img class="img-fluid" src="../img/iconGame.png" /> Activities</router-link>
      <router-link to="/resources" class="nav-item nav-link"><img class="img-fluid" src="../img/iconRes.png" /> Resources</router-link>
      <router-link to="/about" class="nav-item nav-link"><img src="../img/iconAbout.png" /> About</router-link>
      <router-link to="/certificate" :class="{disabled : certificateClass}" class="nav-item nav-link"><img :src="CertificateIcon" /> Certificate</router-link>
    </nav>
  </header>
</template>

<script>
import store from '../store'
import EventBus from '../event-bus'
export default {
  data(){
    return{
      sharedState:store.state,
      certificateNotReady:true
    }
  },
  computed:{
    certificateClass(){
      console.log("certificate ready fired")
      if(this.sharedState.JeopardyScore >= (.75 * 7500) && this.sharedState.DragDropPass == true && this.sharedState.MemoryPass == true){
        console.log("certificate ready is true")
        return false
      }else{
        console.log("certificate ready is false")
        return true
      }
    },
    CertificateIcon(){
      if(this.sharedState.JeopardyScore >= (.75 * 7500) && this.sharedState.DragDropPass == true && this.sharedState.MemoryPass == true){
        return require("../img/iconCert2.png")
      }else{
        return require("../img/iconCert.png")
      }
    }
  }

}
</script>
<style scoped>
  a{
    color:#8affff;

    font-size: x-large;
  }
  img{
    height: 40px;
  }
  .nav-link{
    padding: .5rem 0;
  }
</style>

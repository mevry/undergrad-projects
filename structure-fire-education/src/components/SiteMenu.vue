<template>
<div class="container-fluid text-center py-3">
<h3 class="neon-yellow">Choose from one of the activities below.</h3>
    <div class="d-flex justify-content-around mt-3 pt-3 white-font">

        <div class="mx-2">
            <router-link to="/drag-drop" tag="div" class="activity-link mx-1">
                <!-- <h1>Drag &amp; Match</h1> -->
                <img class="img-fluid rounded shadow" style="border:4px solid #cead49;" src="../img/dragattempt.gif" />
                
            </router-link>
            <br><p>Rearrange items in the correct order.</p>
        </div>
        <div class="mx-2">
            <router-link to="/memory" tag="div" class="activity-link mx-1">
                <!-- <h1>Memory</h1> -->
                <img class="img-fluid rounded shadow" style="border:4px solid #689f4b;" src="../img/memoryattempt.gif" />
                
            </router-link>
            <br><p>Can you find the matching card?</p>
        </div>
        <div class="mx-2">
            <router-link to="/jeopardy" tag="div" class="activity-link mx-1" >
                <!-- <h1>Jeopardy</h1> -->
                <img class="img-fluid rounded shadow" style="border:4px solid #8c52c6;" src="../img/jeopardyattempt.gif" />
                
            </router-link>
            <br><p>Test your fire safety knowledge in this Jeopardy-like quiz.</p>
        </div>
    </div>
    <div class="d-flex justify-content-center">
        <div v-if="certificateReady" id="certificateReady" class="p-5 mt-3">
            <h1>Congratulations! </h1><br><p>You completed all the activities.<br/> Click the link below to view your certificate.</p><br>
            <router-link tag="button" to="/certificate" class="btn btn-warning">
                <h3 class="mb-0"><img src="../img/iconCert2.png" alt="certificate icon" /> Certificate</h3>
            </router-link>
        </div>
    </div>

</div>
</template>
<script>
import store from '../store'

export default {
  name: 'site-menu',
    data(){
        return{
            sharedState:store.state

        }
    },
  computed:{
    certificateReady(){
      console.log("certificate ready fired")
      if(this.sharedState.JeopardyScore >= (.75 * 7500) && this.sharedState.DragDropPass == true && this.sharedState.MemoryPass == true){
        return true
      }else{
        return false
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
};
</script>
<style lang="scss" scoped>
.activity-link {
    cursor: pointer;
}
h1{
    color: white;
    margin-bottom: 0;
}
#certificateReady{
   background-color: rgba(255,255,255,.8);
   border-radius: 4px;
   box-shadow: 1px 1px 3px rgba(41, 38, 80, .5);
   >h1{
       color:rgb(149, 0, 255);
   }
 }
</style>



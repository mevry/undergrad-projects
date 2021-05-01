<template>
    <div class="white-font d-flex my-2">
        <span v-if="FirstName">Hey, {{ FirstName }}</span>
        <span class="ml-auto"><strong>Badges Earned: </strong> {{badgeQuantity()}} / 3</span>
    </div>
</template>
<script>
import store from '../store.js'
import EventBus from '../event-bus.js'
export default {
  name:"detail-bar",
  data (){
    return {
      sharedState: store.state
    }
  },
  computed:{
      FirstName(){ 
        return this.sharedState.FirstName
      }
  },
  methods:{
    badgeQuantity(){
      console.log("badgeQuantity fired")
      let qty = 0;
      if(this.sharedState.JeopardyScore >= (.75 * 7500)){
        qty++
      }
      if(this.sharedState.DragDropPass){
        qty++
      }
      if(this.sharedState.MemoryPass){
        qty++
      }
      return qty
    }
  },
  mounted(){
    EventBus.$on('activity-completed', this.badgeQuantity);
  }

}
</script>
<style lang="scss">

</style>




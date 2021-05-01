<template>
  <div class="container-fluid">
    <h1 class="text-center text-white">Resources</h1>
    <div class="text-center my-3 py-5">
      <a class="btn btn-primary btn-lg" target="_blank" id="survey" href="https://www.surveymonkey.com/r/XGDJPSK">
        <h1>Take Our Survey!</h1>
      </a>
    </div>
    <printables class="p-3"></printables>
    <br />

    <div class="resource_container p-3">
      <h1>Further Information</h1>
      <ul class="list-unstyled">
        <li><a href="https://www.usfa.fema.gov/">U.S. Fire Administration Home Page</a></li>  
        <li><a href="http://depts.washington.edu/learncpr/quickcpr.html">U.W. Basic CPR Instruction</a></li>  
        <li><a href="https://www.cityoftacoma.org/government/city_departments/fire/divisions/emergency_medical_services/c_p_r">City of Tacoma CPR Class Schedule</a></li>  
        <li><a href="https://www.cityoftacoma.org/government/city_departments/fire">Tacoma Fire Dept Home Page</a></li>   
        <li><a href="https://www.piercecountywa.org/980/Fire-Prevention-Bureau">Pierce County Fire Prevention Bureau</a></li>
      </ul>

    </div>
  </div>
</template>
<script>
import Printables from './Printables.vue'
export default {
  name: 'resources',
  components:{
    'printables':Printables
  },

};

</script>
<style scoped>
  #survey{

  }
  .resource_container {
    background-color: rgba(255,255,255,.8);
    border-radius: 4px;
    box-shadow: 1px 1px 3px rgba(41, 38, 80, .5);
  }
</style>

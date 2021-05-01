<template>
  <div class="container-fluid pt-3">
    <h1 class="text-center">Enter Your Name &amp; School</h1>
    <div class="row">
      <div class="col">
        <img class="img-fluid" src="../img/fireman.png" alt="">
      </div>
      <div class="col">
        <div id="firemanDialog" class="p-4">
          <p>Hey there student. Welcome to the Tacoma Fire Department online fire safety activities. Here you will test the fire safety knowledge you have learned in class.</p>
          <p>Tell me your name, your school's name, and your teacher's name so I can print it on your certificate when you complete all the activities! Check your spelling because you can't change this later.</p>
          <div class="error-list" v-if="FormErrors.length">
          <p>I need the following information from you before you can continue: <span v-for="(item,index) in FormErrors" :key="item[index]">{{item}}<span v-if="index+1 < FormErrors.length">, </span></span> </p>
        </div>
        </div>
        
      </div>
    </div>

      <form class="white-font">
        <div class="form-row">
          <div class="form-group col">
            <label class="form-control-label" for="firstname">First Name</label>
            <input v-model.lazy="sharedState.FirstName" class="form-control form-control-lg" type="text" id="firstname">
            <div class="invalid-feedback">Please Enter First Name</div>
          </div>
          <div class="form-group col">
            <label class="form-control-label" for="lastname">Last Name</label>
            <input v-model.lazy="sharedState.LastName" class="form-control form-control-lg" type="text" id="lastname">
          </div>
        </div><!--End form-row-->
        <div class="form-row">
          <div class="form-group col">
            <label class="form-control-label" for="school">School Name</label>
            <input v-model.lazy="sharedState.School" class="form-control form-control-lg" type="text" id="school">
          </div>
          <div class="form-group col">
            <label class="form-control-label" for="teachername">Teacher's Name</label>
            <input v-model.lazy="sharedState.Teacher" class="form-control form-control-lg" type="text" id="teacher">
          </div>
        </div><!--End form-row-->
        <div class="form-row">
          <div class="col">
            <button @click="checkForm" type="button" class="btn btn-warning">Save</button>
          </div>
        </div><!--End form-row-->
      </form>
      

    </div><!--end container-fluid-->
</template>
<script>
import store from '../store.js'
export default {
  
  data(){
    return {
      sharedState: store.state,
      FormErrors:[]
    }
  },
  methods:{
    checkForm(){
      console.log("checkForm");
      if(this.sharedState.FirstName && this.sharedState.LastName && this.sharedState.School && this.sharedState.Teacher){
        this.sharedState.CompletedInfo = true;
        this.$router.push('/');
      }
      this.FormErrors = [];
      if(!this.sharedState.FirstName) this.FormErrors.push("First Name");
      if(!this.sharedState.LastName) this.FormErrors.push("Last Name");
      if(!this.sharedState.School) this.FormErrors.push("School");
      if(!this.sharedState.Teacher) this.FormErrors.push("Teacher");
      
    }
  }
};
</script>
<style lang="scss" scoped>
  #firemanDialog{
    background-color: white;
    border-radius: 20px;
  }
  h1{
    color: #e3ff2c;
  }

  .error-list{
    color: red;
  }
</style>

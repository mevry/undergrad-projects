<template>
<div id="rootContainer">
    <div id="certificate" class="text-center p-2 visible-print-block">
        <div class="d-flex justify-content-between">
            <div><img src="../img/TFDlogo_150h.png" alt="Tacoma Fire Department Logo" style="width:150px"></div>
            <h1 class="align-self-end" style="">Certificate of Completion</h1>
            <div><img src="../img/UWLogoPurple_150h.png" alt="Tacoma Fire Department Logo" style="width:150px"></div>
        </div>
        <h1 class="display-3">{{sharedStore.FirstName}} {{sharedStore.LastName}}</h1>
        <h2>has successfully completed the online <br>Tacoma Fire Department Safety Activities.</h2>
        <div class="row py-5">
            <div class="col-6 offset-3">
                <div class="row">
                    <div class="col">
                        <img class="img-fluid" :src="JeopardyCertificate" alt="150 placeholder">
                        <span>Jeopardy</span><br>
                        <span>{{sharedStore.JeopardyScore}} pts. ({{JeopardyPercentage}}%)</span>
                    </div>
                    <div class="col">
                        <img class="img-fluid" src="../img/badgeDrag.png" alt="150 placeholder">
                        <span>Drag &amp; Match</span>
                    </div>
                    <div class="col">
                        <img class="img-fluid" src="../img/badgeMemory.png" alt="150 placeholder">
                        <span>Memory</span>
                    </div>
                </div>
            </div>
        </div>
        <div class="d-flex justify-content-between">
            <span><strong>School:</strong> {{sharedStore.School}}</span>
            <span><strong>Date: </strong>{{new Date().getMonth()+1}}/{{new Date().getDate()}}/{{new Date().getFullYear()}}</span>
            <span class=""><strong>Teacher:</strong> {{sharedStore.Teacher}}</span>
        </div>
    </div>
    <div class="d-print-none d-flex justify-content-center my-3">
        <button @click="printCertificate()" class="btn btn-warning">Print Certificate</button>
    </div>
</div><!--rootContainer-->

</template>
<script>
import store from '../store'
export default {
    data(){
        return{
            name: 'certificate',
            sharedStore:store.state
        }
    },
    computed:{
        JeopardyCertificate(){

            if((this.sharedStore.JeopardyScore / 7500) >= .9 ){
                return require('../img/badgeJepGold.png')
            }else if((this.sharedStore.JeopardyScore / 7500) >= .8){
                return require('../img/badgeJepSilver.png')
            }else if((this.sharedStore.JeopardyScore / 7500) >= .75 ){
                return require('../img/badgeJepBronze.png')
            }
        },
        JeopardyPercentage(){
            return Math.round(this.sharedStore.JeopardyScore/7500 * 100)
        }
    },
    methods:{
        printCertificate(){
            window.print();
            console.log("Print Certificate fired.")
        }
    }
};
</script>
<style scoped>
    #certificate{
        border: solid 2px rgb(196, 15, 15);
        background-color: rgba(255,255,255,.9);
    }

</style>

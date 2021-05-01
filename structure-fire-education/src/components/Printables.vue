<template>
  <div class="container-fluid">
    <h1>Cross Words</h1>
    <a :href="EasyCross" target="_blank">Easy Difficulty Crossword</a>
    <br />
    <a :href="MedCross" target="_blank">Medium Difficulty Crossword</a>
    <br />
    <a :href="HardCross" target="_blank">Hard Difficulty Crossword</a>
    <br />
    <br />
    <h2>Coloring Pages</h2>
    <a :href="ColorTruck" target="_blank">Fire Truck</a>
    <br />
    <a :href="ColorClass" target="_blank">Fire Classes</a>
    <br />
    <a :href="FireFriend" target="_blank">Fire Friend</a>
    <br />
  </div>
</template>
<script>
  import easyDemo from '../assets/easy_demo.pdf'
  import easyCross from '../assets/easy_cross.pdf'
  import medCross from '../assets/medium_cross.pdf'
  import hardCross from '../assets/hard_cross.pdf'
  import colorTruck from '../assets/coloringTruck.pdf'
  import colorEmblem from '../assets/coloringTruck.pdf'
  import colorFire from '../assets/fire.pdf'
export default {
  name: 'coloring',
  data(){
    return{
      EasyDemo: easyDemo,
      MedCross: medCross,
      EasyCross: easyCross,
      HardCross: hardCross,
      FireFriend: colorFire,
      ColorClass: colorEmblem,
      ColorTruck: colorTruck
    }
  }
};
</script>
<style scoped>
 .container-fluid{
   background-color: rgba(255,255,255,.8);
   border-radius: 4px;
   box-shadow: 1px 1px 3px rgba(41, 38, 80, .5);
 }
</style>

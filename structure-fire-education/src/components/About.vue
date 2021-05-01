<template>
  <div class="container-fluid p-4">
    <h1 class="text-center pb-2">About</h1>
    <div class="row">
      <div class="col">
        <p>
          Established in 1881, the Tacoma Fire Department has sustained to service their community by continually developing advanced and approachable safety to the public.
        </p>  
        <p>  
          This application was developed by the IT students of the University of Washington Tacoma, James Andrews (Developer), Derek Miller (Lead Developer), and Jessica Singo (Project Manager).
          The purpose of this application is to create a web-based product that will bring engagement, awareness, and knowledge to the community on preventable structural fires through learning activities. With our efforts, we hope to bring the youth’s community connected to our local fire departments to continue their knowledge in fire safety and structural fire awareness.
        </p>
      </div>
      <div class="col">
        <img class="img-fluid" src="../img/tfd-firetruck.jpg" alt="Tacoma Fire Department Firetruck">
      </div>
    </div>
    <h2 class="text-center pb-2">Contact Information</h2>
    <div class="row">
      <div class="col">
        <iframe src="https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d2708.047948540409!2d-122.44519238438163!3d47.254765679162965!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x5490550a71de05bf%3A0xb48bd5a2ec2f9d92!2s901+Fawcett+Ave%2C+Tacoma%2C+WA+98402!5e0!3m2!1sen!2sus!4v1527590081326"
                width="400" height="300" frameborder="0" style="border:0" allowfullscreen></iframe>
      </div>
      <br />
      <div class="col">
        Tacoma Fire Department<br />
        901 Fawcett Avenue<br />
        Tacoma, WA 98402<br /><br>
        Phone: (253) 591-5737<br />
        FAX: (253) 591-5746<br />
        Business Hours<br />
        Monday - Friday<br />
        8 AM - 5 PM
      </div>
    </div>
    <br />
  </div>
</template>
<script>

export default {
  name: 'about'
};
</script>
<style scoped>
  .container-fluid {
    background-color: rgba(255,255,255,.8);
    border-radius: 4px;
    box-shadow: 1px 1px 3px rgba(41, 38, 80, .5);
  }

</style>

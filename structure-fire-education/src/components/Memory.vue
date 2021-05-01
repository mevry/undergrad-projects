<template>
 <div class="text-center h-100 inline-block">
	 <h1 class="neon-yellow">Memory Game</h1>
	 <p class="white-font">Match the cards to win a badge.</p>
 	 <div id="rootContainer" class=" h-100 inline-block">
		<link rel="stylesheet" href="./dist/memory.bundle.css">
	    <div class="wrap">
	      <div class="game">

		  </div>
	      <div class="modal-overlay">
	        <div class="modal">
	          <h2 class="winner">Wonderful Job!</h2>
	          <button class="restart">Want to try again?</button>
	        </div>
	      </div>

	    </div><!-- End Wrap -->

	  </div><!--Container-->
 </div>


</template>
<script>
import $ from 'jquery'
import bbq from '../img/memBbq.png'
import candle from '../img/mem/candle.png'
import classA from '../img/memClassA.png'
import classB from '../img/memClassB.png'
import classc from '../img/memClassC.png'
import classD from '../img/memClassD.png'
import classK from '../img/memClassK.png'
import fire from '../img/mem/fire.png'
import fireman from '../img/mem/fireman.png'
import firetruck from '../img/mem/firetruck.png'
import matches from '../img/mem/matches.png'
import smokedetector from '../img/mem/smokedetector.png'
import stove from '../img/mem/stove.png'
import EventBus from '../event-bus'
import store from '../store'

export default {
// Memory Game
// © 2014 Nate Wiley
// License -- MIT

  name: 'memory',
  data(){
	  return {
		sharedState:store.state,
		fireman
	  }
  },
  methods:{
	emitMethod(evt,payload){
		EventBus.$emit(evt,payload)
	}
  },
  mounted (){
	let self = this;
    var Memory = {

		init: function(cards){
			this.$game = $(".game");
			this.$modal = $(".modal");
			this.$overlay = $(".modal-overlay");
			this.$restartButton = $("button.restart");
			this.cardsArray = $.merge(cards,cards);
			this.shuffleCards(this.cardsArray);
			this.setup();
		},

		shuffleCards: function(cardsArray){
			this.$cards = $(this.shuffle(this.cardsArray));
		},

		setup: function(){
			this.html = this.buildHTML();
			this.$game.html(this.html);
			this.$memoryCards = $(".mem-card");
			this.paused = false;
     		this.guess = null;
			this.binding();
		},

		binding: function(){
			this.$memoryCards.on("click", this.cardClicked);
			this.$restartButton.on("click", $.proxy(this.reset, this));
		},
		// kinda messy but hey
		cardClicked: function(){
			console.log("cardClicked fired")
			var _ = Memory;
			var $card = $(this);
			if(!_.paused && !$card.find(".inside").hasClass("matched") && !$card.find(".inside").hasClass("picked")){
				$card.find(".inside").addClass("picked");
				if(!_.guess){
					_.guess = $(this).attr("data-id");
				} else if(_.guess == $(this).attr("data-id") && !$(this).hasClass("picked")){
					$(".picked").addClass("matched");
					_.guess = null;
				} else {
					_.guess = null;
					_.paused = true;
					setTimeout(function(){
						$(".picked").removeClass("picked");
						Memory.paused = false;
					}, 600);
				}
				if($(".matched").length == $(".mem-card").length){
					_.win();
				}
			}
		},

		win: function(){
			this.paused = true;
			console.log("win fired");
			self.sharedState.MemoryPass = true;
			self.emitMethod('activity-completed', {activity:"Memory", completed:true});
		},

		showModal: function(){
			this.$overlay.show();
			this.$modal.fadeIn("slow");
		},

		hideModal: function(){
			this.$overlay.hide();
			this.$modal.hide();
		},

		reset: function(){
			this.hideModal();
			this.shuffleCards(this.cardsArray);
			this.setup();
			this.$game.show("slow");
		},

		// Fisher--Yates Algorithm -- https://bost.ocks.org/mike/shuffle/
		shuffle: function(array){
			var counter = array.length, temp, index;
	   	// While there are elements in the array
	   	while (counter > 0) {
        	// Pick a random index
        	index = Math.floor(Math.random() * counter);
        	// Decrease counter by 1
        	counter--;
        	// And swap the last element with it
        	temp = array[counter];
        	array[counter] = array[index];
        	array[index] = temp;
	    	}
	    	return array;
		},

		buildHTML: function(){
			var frag = '';
			this.$cards.each(function(k, v){
				frag += '<div class="mem-card" data-id="'+ v.id +'"><div class="inside">\
				<div class="front"><img src="'+ v.img +'"\
				alt="'+ v.name +'" /></div>\
				<div class="back"><img src='+ fireman + '\
				alt="firefighter" /></div></div>\
				</div>';
			});

			return frag;
		}
	};

	var cards = [
		{
			name: "classa",
			img: classA,
			id: 1,
		},
		{
			name: "classb",
			img: classB,
			id: 2
		},
		{
			name: "classc",
			img: classc,
			id: 3
		},
		{
			name: "classd",
			img: classD,
			id: 4
		},
		{
			name: "classK",
			img: classK,
			id: 5
		},
		{
			name: "bbq",
			img: bbq,
			id: 6
		},
		{
			name: "candle",
			img: candle,
			id: 7
		},
		{
			name: "fire",
			img: fire,
			id: 8
		},
		{
			name: "firetruck",
			img: firetruck,
			id: 9
		},
		{
			name: "matches",
			img: matches,
			id: 10
		},
		{
			name: "smokedetector",
			img: smokedetector,
			id: 11
		},
		{
			name: "stove",
			img: stove,
			id: 12
		},
	];

	Memory.init(cards);
  }

};
</script>
<style lang="scss" scoped>

</style>

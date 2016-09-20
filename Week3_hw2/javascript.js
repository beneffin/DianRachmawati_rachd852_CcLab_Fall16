

var box=$('#display')[0];
var api ='http://api.giphy.com/v1/gifs/search?';
var apiKey = "&api_key=dc6zaTOxFJmzC&q=";
var query = "rainbow"


//Trending Here ya


function setup() {
  noCanvas();
  var url = 'http://api.giphy.com/v1/gifs/trending?api_key=dc6zaTOxFJmzC';
  loadJSON(url, gotData);
}

function gotData(giphy) {
  for (var i = 0; i < giphy.data.length; i++) {
    createImg(giphy.data[i].images.original.url);
  }
}

//Search Function Here ya

function addtoscreen(x)
{
    box.value += x;

    if (x=='clear')
    {
        box.value ='';
    }
}

function answer(){
  	var answerBox = $('#display').value;
	  console.log(answerBox);
	
}


//onclick function
$("#Searchbtn").click(function(){
	query = $("#display").val();
  console.log (query);

  var link = api+apiKey+query;


  $.get(api+apiKey+query, function(res){    

    for (var i = 0; i < 9; i++) {
      $("#gambar-"+i).append("<img src='" +res.data[i].images.fixed_height.url + "'></img>");  
      console.log (res);
      }
    }

  );
})







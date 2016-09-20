

var box=$('#display')[0];
var api ='http://api.giphy.com/v1/gifs/search?';
var apiKey = "&api_key=dc6zaTOxFJmzC&";
var query = "&q=rainbow"


function addtoscreen(x)
{
    box.value += x;

    if (x=='clear')
    {
        box.value ='';
        console.log(addvalue);
    }
}


function setup() {
  noCanvas();
  var url = api + apiKey + query;
  loadJSON(url, gotData);
}

function gotData(giphy) {
  for (var i = 0; i < giphy.data.length; i++) {
    createImg(giphy.data[i].images.original.url);
  }
}



$.get('http://api.giphy.com/v1/gifs/trending?api_key=dc6zaTOxFJmzC', function(res){    

	for (var i = 0; i < 9; i++) {
		$("#gambar-"+i).append("<img src='" +res.data[i].images.fixed_height.url + "'></img>");  
		}
	}

);


//fallback function adalah fungsi yang dipanggil setelah melakukan satu fungsi


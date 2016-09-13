//$("#gambar").append("<img src='grand-suite.jpg'></img>");

$.get('https://api.instagram.com/v1/users/self/media/recent?access_token=19187433.2b7ad1e.2a5843af5216402caf229226d0dfdb34', function(res){    

//res= object yang akan dikembaliin setelah manggil api instagram


	for (var i = 0; i < 9; i++) {
		$("#gambar-"+i).append("<img src='" +res.data[i].images.low_resolution.url + "'></img>");
		$(".caption-"+i).append( res.data[i].caption.text  );  
		}
	}

);


//fallback function adalah fungsi yang dipanggil setelah melakukan satu fungsi


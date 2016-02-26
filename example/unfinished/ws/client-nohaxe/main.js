window.onload = function() {
	console.log("___")
	var exampleSocket = new WebSocket("ws://127.0.0.1:8000/");

	exampleSocket.onopen = function (event) {
		exampleSocket.send(JSON.stringify({
			t: "Hello",
			data:"data"
		}));
	};

	exampleSocket.onmessage = function (event) {
		console.log(event.data);
	}
};

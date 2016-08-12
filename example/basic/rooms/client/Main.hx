package;


class Main
{
	var clientSocket:mphx.client.Client;
	public function new () {

		var ip = "127.0.0.1";
		if (Sys.args()[0] != null) ip = Sys.args()[0];
		clientSocket = new mphx.client.Client(ip,8000);

		clientSocket.connect();

		var rooms = ["A","B","C"];
		var random = Math.floor(Math.random()*3);
		var room = rooms[random]; //Room now contains A B or C.

		trace("Requesting to join room "+room); //Outputs which room the client wishes to join.

		clientSocket.send("MoveIntoRoom",room); //Requesting to join the room.

		//Now the server sends a message (in each room) that says
		//'Someone was put into room [Room Letter]'

		clientSocket.events.on("RoomBroadcast",function (data){
			trace("Recieved message: " + data);
		});

		//This just creates an 'update loop' so that the program won't close in
		//terminal. On JS, it uses websockets and is in a browser, so doesn't
		//Need a runloop.
		#if !js
		var quit = false;
		while (quit == false){
			clientSocket.update();
			Sys.sleep(0.01); // wait for 1 ms

		}
		#end

	}
	public static function main () {
		new Main();
	}
}

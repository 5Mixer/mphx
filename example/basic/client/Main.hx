package;


class Main
{
	var clientSocket:mphx.client.Client;
	public function new () {

		var ip = "127.0.0.1";
		if (Sys.args()[0] != null) ip = Sys.args()[0];
		clientSocket = new mphx.client.Client(ip,8000);

		clientSocket.connect();


		clientSocket.send("Hello",123);

		clientSocket.events.on("Direct Message",function (data){
			trace("Server sent a 'Direct message' with data " +data);
		});

		clientSocket.events.on("Server wide broadcast",function (data){
			trace("server broadcasted a server wide message. Data was "+data);
		});

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

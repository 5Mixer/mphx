package;


class Main
{
	var clientSocket:mphx.client.IClient;
	public function new () {

		clientSocket = mphx.client.Client.start("127.0.0.1",8000);

		clientSocket.connect();

		clientSocket.send("Hello",123);

		clientSocket.events.on("DM",function (data,sender){
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
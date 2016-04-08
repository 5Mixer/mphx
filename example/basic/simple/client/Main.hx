package;


class Main
{
	var clientSocket:mphx.client.Client;
	public function new () {

		var ip = "127.0.0.1";
		if (Sys.args()[0] != null) ip = Sys.args()[0];
		clientSocket = new mphx.client.Client(ip,8000);

		clientSocket.connect();

		var connectionAbstraction = new mphx.client.ConnectionAbstraction(clientSocket);

		connectionAbstraction.send("Hello",123);

		connectionAbstraction.events.on("DM",function (data){
			trace("Server sent a 'Direct message' with data " +data);
		});

		connectionAbstraction.events.on("Server wide broadcast",function (data){
			trace("server broadcasted a server wide message. Data was "+data);
		});

		clientSocket.abstraction = connectionAbstraction;

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

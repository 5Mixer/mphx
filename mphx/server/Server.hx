package mphx.server;

class Server {

	var server:mphx.tcp.Server;
	public var events:mphx.core.EventManager;

	public function new (ip:String,port:Int){

		events = new mphx.core.EventManager();

		server = new mphx.tcp.Server(port,ip,events);


	}
	public function start () {

		trace("Server active. Anycode after this point will not run, your app will hang.");
		trace("You can instead call 'update' frequently, and run your code along side it.");

		server.listen();
		while (true) {
			server.update();
			Sys.sleep(0.01); // wait for 1 ms
		}
	}

	public function broadcast (event:String,data:Dynamic) {
		server.broadcast(event,data);
	}


}

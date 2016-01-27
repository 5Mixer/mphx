package mphx.server;

class Server {

	var server:mphx.tcp.Server;
	var eventMap:Map<String,Dynamic->Void>;

	public function new (ip:String,port:Int){
		server = new mphx.tcp.Server(port,ip);


		eventMap = new Map<String,Dynamic->Void>();
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

	public function on (eventName,event:Dynamic->Void){
		eventMap.set(eventName,event);
	}
	private function callEvent (eventName,data:Dynamic){
		eventMap.get(eventName)(data);
	}
}

package mphx.server;

class Server {

	var server:mphx.tcp.Server;

	public function new (ip:String,port:Int){
		server = new mphx.tcp.Server(port,ip);
	}
	public function start () {
		server.start();
		trace("Server active");

	}
}

package ;

typedef Player = {
	x: Int,
	y: Int,
	id: String
}

class Main {
	public var players:Map<mphx.tcp.IConnection,Player>;

	public function new (){
		players = new Map<mphx.tcp.IConnection,Player>();

		var s = new mphx.server.Server("127.0.0.1",8000);

		s.events.on("clientMessage",function(data:Dynamic,sender:mphx.tcp.IConnection){

			//Add a whole second of thinking to the server, to kind of simulate a terrible connection!
			//Sys.sleep(1);

			sender.send("serverMessage",data);
		});


		s.start();
	}

	public static function main (){
		new Main();
	}
}

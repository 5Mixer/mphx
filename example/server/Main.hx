package ;

class Main {
	public function new (){
		var s = new mphx.server.Server("127.0.0.1",8000);

		s.events.on("Hello",function(data:Dynamic,sender:mphx.tcp.Connection){
			//throw "up";
			trace("Client said hello");
			s.broadcast("BROADCAST",null);
			sender.send("DM","Hello ya'll!!!");
		});

		s.start();
	}
	public static function main (){
		new Main();
	}
}

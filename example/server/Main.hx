package ;

class Main {
	public function new (){
		var s = new mphx.server.Server("127.0.0.1",8000);

		var room = new mphx.server.Room();
		s.rooms.push(room);

		s.events.on("Hello",function(data:Dynamic,sender:mphx.tcp.Connection){
			//throw "up";
			trace("Client said hello");
			sender.send("DM","Hello ya'll!!!");
			sender.send("DM","Hello ya'll!!!");
			s.broadcast("BROADCAST",null);
			s.broadcast("BROADCAST",null);
			sender.putInRoom(room);
			room.broadcast("This is a room wide broadcast!",null);
		});


		s.start();
	}
	public static function main (){
		new Main();
	}
}

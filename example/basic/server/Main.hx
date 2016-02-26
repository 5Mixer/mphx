package ;

class Main {
	public function new (){
		var s = new mphx.server.Server("127.0.0.1",8000);

		var room = new mphx.server.Room();
		s.rooms.push(room);

		s.events.on("Hello",function(data:Dynamic,sender:mphx.tcp.IConnection){
			trace("The client sent 'Hello' with data " +data+ " . Replying back a number of ways.");

			//sender.send("Direct Message","This is a direct reply to your 'Hello' message!");
			sender.send("DM","Hello ya'll!!!");
			s.broadcast("Server wide broadcast","BEEPBOOP.");
			//s.broadcast("BROADCAST",null);
			//sender.putInRoom(room);
			//room.broadcast("This is a room wide broadcast!",null);
		});

		s.events.on("Player Move",function (data,connection){

		});


		s.start();
	}
	public static function main (){
		new Main();
	}
}

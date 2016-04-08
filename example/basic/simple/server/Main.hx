package ;

class Main {
	public function new (){
		var ip = "127.0.0.1";
		if (Sys.args()[0] != null) ip = Sys.args()[0];

		var s = new mphx.server.Server(ip,8000);

		var room = new mphx.server.Room();
		s.rooms.push(room);

		var connectionFactory = function (connection){

			//Makes an abstract connection with an event preconfigured.
			//This means all events will be created like this.
			var c = new mphx.tcp.ConnectionAbstraction(connection);

			c.events.on("Hello",function(data:Dynamic,sender:mphx.tcp.ConnectionAbstraction){
				trace("The client sent 'Hello' with data " +data+ " . Replying back a number of ways.");

				//sender.send("Direct Message","This is a direct reply to your 'Hello' message!");
				sender.send("DM","Hello ya'll!!!");
				for (client in s.clients){
					cast(client.socket.custom, mphx.tcp.IConnection).abstraction.send("Server wide broadcast","BEEPBOOP.");
				}
				//s.broadcast("BROADCAST",null);
				//sender.putInRoom(room);
				//room.broadcast("This is a room wide broadcast!",null);
			});

			c.events.on("Player Move",function (data,connection){

			});
			return c;
		}

		s.abstractConnectionFactory = connectionFactory;
		trace("Starting");
		s.start();
	}
	public static function main (){
		new Main();
	}
}

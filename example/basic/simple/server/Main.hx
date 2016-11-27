package ;
import mphx.connection.IConnection;
import mphx.server.impl.FlashServer; //Use if hosting flash policy files.
import mphx.server.impl.Server;
import mphx.server.room.Room;

class Main {
	public function new (){
		//Allow the changing of the server host IP through a command line argument.
		var ip = "127.0.0.1";
		if (Sys.args()[0] != null) ip = Sys.args()[0];

		//var s = new FlashServer(ip, 8000); // use this if you use a flash connection (using an policy files servers for flash socket)
		var s = new FlashServer(ip, 8000);

		s.onConnectionAccepted = onConnectOrDisconnect;
		s.onConnectionClose = onConnectOrDisconnect;

		//Room allow grouping of connections to allow for group specific messaging. Useful for chat room/game seperation.
		var room = new Room();
		//Register the room with the server.
		s.rooms.push(room);

		s.events.on("Hello",function(data:Dynamic,sender:mphx.connection.IConnection){
			trace("The client sent 'Hello' with data " +data+ " . Replying back a number of ways.");

			sender.send("DM","This is a direct response to the message sender");
			s.broadcast("Server wide broadcast","This is a message sent to all connections.");

			//sender.putInRoom(room);
			//room.broadcast("This is a room wide broadcast!",null);
		});

		s.onConnectionClose = function (reason, connection:IConnection){
			trace("A client disconnected from the game.");
			s.broadcast("SomeoneDisconnected");
		}


		//Start the server. Connections won't actually be accepted until start is called.
		s.start();
	}

	private function onConnectOrDisconnect(info : String, cnx : IConnection) : Void
	{
		trace(info);
	}

	public static function main (){
		new Main();
	}
}

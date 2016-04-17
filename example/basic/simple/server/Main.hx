package ;
import mphx.connection.IConnection;
import mphx.server.impl.FlashServer;
import mphx.server.impl.Server;
import mphx.server.room.Room;

class Main {
	public function new (){
		var ip = "127.0.0.1";
		if (Sys.args()[0] != null) ip = Sys.args()[0];

		//var s = new FlashServer(ip, 8000); // use this if you use a Flash connexion (using an Policy files servers for flash socket)
		var s = new Server(ip, 8000);
		
		s.onConnectionAccepted = onConnectOrDisconnect;
		s.onConnectionClose = onConnectOrDisconnect;

		var room = new Room();
		s.rooms.push(room);

		s.events.on("Hello",function(data:Dynamic,sender:mphx.connection.IConnection){
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
	
	private function onConnectOrDisconnect(infos : String, cnx : IConnection) : Void
	{
		trace(infos);
	}
	
	public static function main (){
		new Main();
	}
}

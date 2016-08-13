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
		var s = new Server(ip, 8000);

		s.onConnectionAccepted = onConnectOrDisconnect;
		s.onConnectionClose = onConnectOrDisconnect;

		var pings = 0;
		var expectedPings = 1000;

		s.events.on("Ping",function(data:Dynamic,sender:mphx.connection.IConnection){
			if (pings % 100 == 0)
				trace("Ping "+pings);

			pings++;
			sender.send("Pong");
		});

		s.events.on("Player Move",function (data,connection){
			//A connection sent a "Player Move" event.
		});

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

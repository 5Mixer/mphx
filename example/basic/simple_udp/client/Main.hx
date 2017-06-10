package;
import mphx.client.impl.UdpClient;

#if flash
import flash.events.Event;
import flash.Lib;
#end

class Main
{
	var clientSocket:UdpClient;

	public function new ()
	{
		var ip = "127.0.0.1";

		#if !flash
		if (Sys.args()[0] != null) ip = Sys.args()[0];
		#end

		clientSocket = new UdpClient(ip, 8001);

		var serverAddress = new sys.net.Address();
		serverAddress.host = dot2num(ip);
		serverAddress.port = 8000;//64756;

		clientSocket.connect(serverAddress);
		//clientSocket.send("Hello",123);

		clientSocket.events.on("Direct Message",function (data){
			trace("Server sent a 'Direct message' with data " +data);
		});

		clientSocket.events.on("Server wide broadcast",function (data){
			trace("server broadcasted a server wide message. Data was "+data);
		});

		#if js
		//nothingSpecial
		#elseif flash
		Lib.current.stage.addEventListener(Event.ENTER_FRAME, function(e: Event)
		{
			clientSocket.update();
		});

		#else
		trace("Starting");

		//clientSocket.send("Hello",123);

		var quit = false;
		while (quit == false){
			clientSocket.update();

			try {
				clientSocket.send("Thx for sending me msg!");
			} catch(e:Dynamic) {
				trace(e);
			}

			//trace("Update "+clientSocket.address);

			//clientSocket.send("Hello",123);
			Sys.sleep(0.01); // wait for 1 ms

		}
		#end

	}

	function dot2num(dot:String)
	{
	    var parts = dot.split(".");
		return ((16777216 * Std.parseInt(parts[0])) + (65536 *  Std.parseInt(parts[1])) + (256 *  Std.parseInt(parts[2])) +  Std.parseInt(parts[3]));
	}

	public static function main () {
		new Main();
	}
}

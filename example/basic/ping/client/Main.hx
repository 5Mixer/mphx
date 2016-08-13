package;
import mphx.client.Client;

#if flash
import flash.events.Event;
import flash.Lib;
#end

class Main
{
	var clientSocket:Client;

	public function new ()
	{
		var ip = "127.0.0.1";

		#if !flash
		if (Sys.args()[0] != null) ip = Sys.args()[0];
		#end

		clientSocket = new Client(ip, 8000);
		clientSocket.connect();
		clientSocket.send("Ping");

		var pings = 1;

		var pongs = 0;
		var expectedPongs = 1000;

		var startTime:Float = haxe.Timer.stamp();

		clientSocket.events.on("Pong",function (data){
			if (pongs % 200 == 0){
				trace("Pong " + pongs);
			}

			pongs++;

			if (pongs <= expectedPongs){
				clientSocket.send("Ping",{id:"some setoooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo amount of data here."});
			}else{
				trace("Completed "+expectedPongs+" pings, with a ping taking "+((haxe.Timer.stamp()-startTime)/expectedPongs)+" seconds on average.");
			}
		});

		#if flash
		Lib.current.stage.addEventListener(Event.ENTER_FRAME, function(e: Event)
		{
			clientSocket.update();
		});

		#else
		var quit = false;
		while (quit == false){
			clientSocket.update();
			Sys.sleep(0.01); // wait for 1 ms

		}
		#end

	}
	public static function main () {
		new Main();
	}
}

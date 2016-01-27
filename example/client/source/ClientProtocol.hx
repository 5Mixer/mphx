package ;

import hxnet.interfaces.Connection;
import haxe.io.Input;
import haxe.io.Bytes;

typedef Player = {
	x: Int,
	y: Int,
	id: Int
}
typedef PlayerList = {
	packetType: String,
	data: Array<Player>
}

class ClientProtocol extends hxnet.base.Protocol {
	var main:PlayState;
	public function new (_main:PlayState){
		super();
		main = _main;
	}
	override public function onConnect(cnx:Connection){
		super.onConnect(cnx);
		trace("Connected");
	}
	public function writeLine(data:String):Void
	{
		cnx.writeBytes(Bytes.ofString(data + "\r\n"));
	}
	override public function dataReceived(input:Input){
		var line = input.readLine();


		trace(line);

		var data:PlayerList = haxe.Json.parse(line);



		if (data.packetType == "Player List"){

			main.allPlayers.clear();

			for (player in data.data){
				var p  = new flixel.FlxSprite(player.x,player.y);
				p.makeGraphic(60,60);
				main.allPlayers.add(p);
			}
		}

	}
}

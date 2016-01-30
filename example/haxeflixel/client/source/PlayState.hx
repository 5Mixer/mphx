package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.text.FlxText;
import flixel.ui.FlxButton;
import flixel.util.FlxMath;
import flixel.group.FlxGroup;
import org.msgpack.MsgPack;

/**
 * A FlxState which can be used for the actual gameplay.
 */
class PlayState extends FlxState
{
	var clientSocket:mphx.client.Client;
	var ownPlayer:FlxSprite;
	public var allPlayers:FlxGroup;
	override public function create():Void
	{
		super.create();




		clientSocket = new mphx.client.Client("127.0.0.1",8000);

		clientSocket.connect();

		clientSocket.send("Hello",null);


		clientSocket.events.on("BROADCAST",function (data){
			trace("server broadcasted!");
		});
		clientSocket.events.on("Direct Message",function (data,sender){
			trace(data +" ... was sent only to I.");
		});










		allPlayers = new FlxGroup();

		var playerID = Math.floor(Math.random()*100000);
		var playerData = {
			x: FlxG.width*Math.random(),
			y: FlxG.height*Math.random(),
			id: playerID
		}


		ownPlayer = new FlxSprite(FlxG.width*Math.random(),FlxG.height*Math.random());
		ownPlayer.makeGraphic(60,60);
		allPlayers.add(ownPlayer);

		add(allPlayers);
	}


	/**
	 * Function that is called once every frame.
	 */
	 var i = 0;
	override public function update():Void
	{
		super.update();

		clientSocket.update();

		i++;
		if (i%15 == 0){
			clientSocket.send("Hello",null);
		}

	}
}

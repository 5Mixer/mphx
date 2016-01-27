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
	var clientConnection:mphx.client.Client;
	var ownPlayer:FlxSprite;
	public var allPlayers:FlxGroup;
	override public function create():Void
	{
		super.create();

		clientConnection = new mphx.client.Client("127.0.0.1",8000);

		clientConnection.connect();

		clientConnection.send("Hello",null);

		allPlayers = new FlxGroup();

		var playerID = Math.floor(Math.random()*100000);
		var playerData = {
			x: FlxG.width*Math.random(),
			y: FlxG.height*Math.random(),
			id: playerID
		}

		var newPlayerPacket = {
			packetType: "New Player",
			data: playerData
		}

		ownPlayer = new FlxSprite(FlxG.width*Math.random(),FlxG.height*Math.random());
		ownPlayer.makeGraphic(60,60);
		allPlayers.add(ownPlayer);

		add(allPlayers);

		//protocol.writeLine( haxe.Json.stringify(newPlayerPacket) );
	}

	/**
	 * Function that is called when this state is destroyed - you might want to
	 * consider setting all objects this state uses to null to help garbage collection.
	 */
	override public function destroy():Void
	{
		super.destroy();
	}

	/**
	 * Function that is called once every frame.
	 */
	override public function update():Void
	{
		super.update();

		clientConnection.update();


	}
}

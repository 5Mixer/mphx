package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.text.FlxText;
import flixel.ui.FlxButton;
import flixel.util.FlxMath;
import flixel.group.FlxGroup;
import org.msgpack.MsgPack;

class PlayState extends FlxState
{
	var clientSocket:mphx.client.Client;

	var messageType = "MyNumbers";
	var messageContents = "9584320958,4259854320";

	var startTime:Float;

	override public function create():Void
	{
		super.create();

		FlxG.autoPause = false;

		clientSocket = new mphx.client.Client("127.0.0.1",8000);
		clientSocket.connect();

		//clientSocket.send(messageType,messageContents);


		clientSocket.events.on("serverMessage", function (data) {
			//var totalTime = haxe.Timer.stamp()-startTime;
			var totalTime = haxe.Timer.stamp()-data;
			trace(totalTime + "s roundtrip.");
		});
	}

	public function testRoundtrip ()
	{
		startTime = haxe.Timer.stamp();
		clientSocket.send("clientMessage",startTime);

	}

	var testTimer:Float=0;
	override public function update():Void
	{
		super.update();

		testTimer += FlxG.elapsed;

		if (testTimer > 0.0001)
		{
			//Every 5 seconds do roundtrip
			testRoundtrip();
			testTimer=0;
		}

		clientSocket.update();


	}
}

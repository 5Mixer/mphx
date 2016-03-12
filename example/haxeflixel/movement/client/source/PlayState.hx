package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.text.FlxText;
import flixel.ui.FlxButton;
import flixel.math.FlxMath;
import flixel.group.FlxGroup;
import org.msgpack.MsgPack;

import Player;


/**
 * A FlxState which can be used for the actual gameplay.
 */
class PlayState extends FlxState
{
	var clientSocket:mphx.client.Client;
	var ownPlayer:FlxSprite;
	public var allPlayers:FlxGroup;

	var player:Player;

	var players = new Map<String,Player>();
	override public function create():Void
	{
		super.create();

		trace("Start of playstate");

		FlxG.autoPause = false;

		allPlayers = new FlxGroup();
		add(allPlayers);

		try{
			clientSocket = new mphx.client.Client(GameData.ip,GameData.port);
			clientSocket.connect();
		}catch(e:Dynamic){
			trace(e);
		}


		var playerData:PlayerData = {
			x: Math.floor(FlxG.width*Math.random()),
			y: Math.floor(FlxG.height*Math.random()),
			id: "player"+Math.random()*10000
		};

		player = new Player(playerData);
		allPlayers.add(player);
		players.set(playerData.id,player);


		clientSocket.send("Join",playerData);

		clientSocket.events.on("New Player", function (data) {

			if (players.exists(data.id)) return;

			var player = new Player(data);
			allPlayers.add(player);

			players.set(data.id,player);

		});

		clientSocket.events.on("Player Move",function (data){
			//trace(data);
			if (data.id == player.data.id) return;

			if (players.exists(data.id) == false){
				var player = new Player(data);
				allPlayers.add(player);

				players.set(data.id,player);
			}

			var player = players.get(data.id);
			player.data = data;

			player.x = player.data.x;
			player.y = player.data.y;
		});
	}


	/**
	 * Function that is called once every frame.
	 */
	 var i = 0;
	override public function update(elapsed:Float):Void
	{
		super.update(elapsed);

		clientSocket.update();

		if (FlxG.keys.pressed.UP)
		{
			player.y -= 5;
			clientSocket.send("Player Move",player.data);
		}
		if (FlxG.keys.pressed.DOWN)
		{
			player.y += 5;
			clientSocket.send("Player Move",player.data);
		}
		if (FlxG.keys.pressed.LEFT)
		{
			player.x -= 5;
			clientSocket.send("Player Move",player.data);
		}
		if (FlxG.keys.pressed.RIGHT)
		{
			player.x += 5;
			clientSocket.send("Player Move",player.data);
		}
	}
}

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

		var error = false;



		try{
			clientSocket = new mphx.client.Client(GameData.ip,GameData.port);

			clientSocket.onConnectionError = function (s){
				error = true;
			}

			clientSocket.connect();
		}catch(e:Dynamic){
			trace(e);
			error = true;
		}

		if (error){
			FlxG.switchState(new MenuState());
			return;
		}


		var playerData:PlayerData = {
			x: Math.floor(FlxG.width*Math.random()),
			y: Math.floor(FlxG.height*Math.random()),
			id: "player"+Math.random()*10000
		};

		player = new Player(playerData, true);
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
			if (data.id == player.data.id) return;

			if (players.exists(data.id) == false){
				var player = new Player(data);
				allPlayers.add(player);

				players.set(data.id,player);
			}

			var player = players.get(data.id);
			player.data = data;

			player.targetx = player.data.x;
			player.targety = player.data.y;
		});
	}


	/**
	 * Function that is called once every frame.
	 */
	var i = 0;
	var needsUpdating = false;
	override public function update(elapsed:Float):Void
	{
		super.update(elapsed);
		i++;

		clientSocket.update();

		if (FlxG.keys.pressed.UP)
		{
			player.y -= 5;
			needsUpdating = true;
		}
		if (FlxG.keys.pressed.DOWN)
		{
			player.y += 5;
			needsUpdating = true;
		}
		if (FlxG.keys.pressed.LEFT)
		{
			player.x -= 5;
			needsUpdating = true;
		}
		if (FlxG.keys.pressed.RIGHT)
		{
			player.x += 5;
			needsUpdating = true;
		}

		if (i%3 == 0 && needsUpdating){ //Once every three frames
			clientSocket.send("Player Move",player.data);

		}
	}
}

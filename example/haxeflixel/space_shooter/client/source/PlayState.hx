package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.text.FlxText;
import flixel.ui.FlxButton;
import flixel.math.FlxMath;
import flixel.group.FlxGroup;

class PlayState extends FlxState
{
	var client:mphx.client.Client;
	var players:Map<String,Player>;
	var player:Player;

	override public function create():Void
	{
		super.create();

		FlxG.autoPause = false;

		client = new mphx.client.Client("127.0.0.1",8000);
		client.connect();

		players = new Map<String,Player>();

		player = new Player({
			x: Math.floor(Math.random()*600),
			y: Math.floor(Math.random()*600),
			dir: 0,
			speed: 0,
			id:"P"+Math.floor(Math.random()*1000)
		});
		players.set(player.clientData.id,player);
		add(player);

		client.send("Join",player.clientData);

		client.events.on("Error",function (data)
		{
			trace("Error "+data);
		});
		client.events.on("Update",function (data)
		{
			if (player.clientData.id != data.id){
				if (players.exists(data.id)){
					players.get(data.id).clientData = data;
				}else{
					//Unrecognised player, create them
					var newPlayer = new Player(data);
					players.set(data.id,newPlayer);
					add(newPlayer);
				}
			}
		});
		client.events.on("Join",function (data)
		{
			if (players.exists(data.id) == false){
				//Unrecognised player, create them
				var newPlayer = new Player(data);
				add(newPlayer);
			}
		});
	}

	override public function update(elapsed:Float):Void
	{
		super.update(elapsed);
		client.update();


	    if (FlxG.keys.pressed.UP)
	    {
	        // The up arrow key is currently pressed
			player.clientData.speed = 150;
			client.send("Update",player.clientData);
	    }
		if (FlxG.keys.pressed.LEFT)
	    {
	        // The up arrow key is currently pressed
			player.clientData.dir -= 150*elapsed;
			client.send("Update",player.clientData);
	    }
		if (FlxG.keys.pressed.RIGHT)
	    {
	        // The up arrow key is currently pressed
			player.clientData.dir += 150*elapsed;
			client.send("Update",player.clientData);
	    }

	}
}

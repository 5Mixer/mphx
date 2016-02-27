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
	var bullets:Map<String,Bullet>;
	var bulletsGroup:FlxTypedGroup<Bullet>;
	var player:Player;

	//Server does no cheat detection, yet.
	var reload:Float = 0;

	override public function create():Void
	{
		super.create();

		FlxG.autoPause = false;

		client = new mphx.client.Client("127.0.0.1",8000);
		client.connect();

		players = new Map<String,Player>();
		bullets = new Map<String,Bullet>();
		bulletsGroup = new FlxTypedGroup<Bullet>();
		add(bulletsGroup);

		player = new Player({
			x: Math.floor(Math.random()*600),
			y: Math.floor(Math.random()*600),
			dir: 0,
			speed: 0,
			id:"P"+Math.floor(Math.random()*9999)
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
					players.get(data.id).recieveUpdate(data);
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
				players.set(data.id,newPlayer);
				add(newPlayer);
			}
		});

		/* NB means 'New Bullet' */
		client.events.on("NB",function (data)
		{
			if (bullets.exists(data.id) == false){
				//Unrecognised bullet, create them
				var newBullet = new Bullet(data);
				bullets.set(data.id,newBullet);
				add(newBullet);
			}
		});

		/* UB means 'Update Bullet'*/
		client.events.on("UB",function (data)
		{
			if (bullets.exists(data.id)){
				bullets.get(data.id).recieveUpdate(data);
			}else{
				//Unrecognised bullet, create it
				var newBullet = new Bullet(data);
				bullets.set(data.id,newBullet);
				add(newBullet);
			}

		});
	}

	override public function update(elapsed:Float):Void
	{
		super.update(elapsed);
		client.update();

		reload += elapsed;

		if (FlxG.keys.pressed.SPACE && reload > .2)
	    {
			reload = 0;
	        // The space key is pressed, shoot
			var bullet = new Bullet({
				x: Math.floor(player.getMidpoint().x),
				y: Math.floor(player.getMidpoint().y),
				dir: player.angle,
				id:"B"+Math.floor(Math.random()*9999),
				shooter: player.clientData.id
			});
			bullets.set(bullet.clientData.id,bullet);
			bulletsGroup.add(bullet);
			client.send("Shoot",bullet.clientData);
	    }

	    if (FlxG.keys.pressed.UP)
	    {
	        // The up arrow key is currently pressed, move
			player.clientData.speed = 150;
			client.send("Update",player.clientData);
	    }
		if (FlxG.keys.pressed.LEFT)
	    {
	        // The left arrow key is currently pressed, turn
			player.clientData.dir -= 150*elapsed;
			client.send("Update",player.clientData);
	    }
		if (FlxG.keys.pressed.RIGHT)
	    {
	        // The right arrow key is currently pressed, turn
			player.clientData.dir += 150*elapsed;
			client.send("Update",player.clientData);
	    }


	}
}

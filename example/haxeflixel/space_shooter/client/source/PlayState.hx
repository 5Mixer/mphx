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
	var playersGroup:FlxTypedGroup<Player>;
	var player:Player;

	//Server does no cheat detection, yet.
	var reload:Float = 0;

	override public function create():Void
	{
		super.create();

		FlxG.autoPause = false;

		client = new mphx.client.Client(GameData.ip,GameData.port);
		client.connect();

		add(new Stars());

		players = new Map<String,Player>();
		bullets = new Map<String,Bullet>();
		bulletsGroup = new FlxTypedGroup<Bullet>();
		playersGroup = new FlxTypedGroup<Player>();
		add(bulletsGroup);
		add(playersGroup);

		player = new Player({
			x: Math.floor(Math.random()*FlxG.width),
			y: Math.floor(Math.random()*FlxG.height),
			dir: 0,
			speed: 0,
			id:"P"+Math.floor(Math.random()*9999)
		});
		player.color = 0xffed5151;
		//FlxG.camera.follow(player);
		players.set(player.clientData.id,player);
		playersGroup.add(player);

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
					playersGroup.add(newPlayer);
				}
			}
		});
		client.events.on("Join",function (data)
		{
			if (players.exists(data.id) == false){
				//Unrecognised player, create them
				var newPlayer = new Player(data);
				players.set(data.id,newPlayer);
				playersGroup.add(newPlayer);
			}
		});

		/* NB means 'New Bullet' */
		client.events.on("NB",function (data)
		{
			if (bullets.exists(data.id) == false){
				//Unrecognised bullet, create them
				var newBullet = new Bullet(data);
				bullets.set(data.id,newBullet);
				bulletsGroup.add(newBullet);
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
				bulletsGroup.add(newBullet);
			}

		});
	}

	override public function update(elapsed:Float):Void
	{
		super.update(elapsed);
		client.update();

		/*FlxG.overlap(player,bulletsGroup,function (hitPlayer,hitBullet){
			if (hitBullet.clientData.shooter != player.clientData.id){
				player.clientData.x = 40;
				player.clientData.y = 40;
				client.send("Update",player.clientData);

				hitBullet.kill(); //This doesn't apply across the network?
			}
		});*/
		FlxG.overlap(playersGroup,bulletsGroup,function (hitPlayer,hitBullet){
			if (hitBullet.clientData.shooter != hitPlayer.clientData.id){
				hitPlayer.clientData.x = 40;
				hitPlayer.clientData.y = 40;
				hitPlayer.setPosition(40,40);

				hitBullet.kill(); //This doesn't apply across the network?
			}
		});

		reload += elapsed;

		if (FlxG.keys.pressed.SPACE && reload > .15)
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

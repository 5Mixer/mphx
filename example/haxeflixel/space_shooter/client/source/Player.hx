package ;

import flixel.FlxSprite;

typedef PlayerData = {
	x: Int,
	y: Int,
	dir: Float,
	speed: Float,
	id: String
};

class Player extends FlxSprite {

	public var clientData:PlayerData;

	public function new (data:PlayerData){
		super(data.x,data.y);

		clientData = data;

		loadGraphic("assets/images/Player.png",true,32,32);
	}

	override public function update (elapsed:Float){
		super.update(elapsed);

		velocity.set(clientData.speed*Math.cos((angle-90)* Math.PI / 180),clientData.speed*Math.sin((angle-90)* Math.PI / 180));
		clientData.speed *= elapsed * 0.99;

		//Acount for velocity moving the x and y.
		clientData.x = Math.floor(x);
		clientData.y = Math.floor(y);
		angle = clientData.dir;
	}

	public function recieveUpdate(data:PlayerData){
		clientData = data;

		setPosition(data.x,data.y);
		angle = data.dir;
	}
}

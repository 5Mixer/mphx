package ;

import flixel.FlxSprite;
import flixel.util.FlxColor;

typedef BulletData = {
	x: Int,
	y: Int,
	dir: Float,
	id: String,
	shooter: String
};

class Bullet extends FlxSprite {

	public var clientData:BulletData;
	var speed = 400;

	public function new (data:BulletData){
		super(data.x,data.y);

		clientData = data;
		angle = data.dir;

		makeGraphic(5,10,0xF5D23BFF);
	}

	override public function update (elapsed:Float){
		super.update(elapsed);

		velocity.set(speed*Math.cos((angle-90)* Math.PI / 180),speed*Math.sin((angle-90)* Math.PI / 180));

		//Acount for velocity moving the x and y.
		clientData.x = Math.floor(x);
		clientData.y = Math.floor(y);

		angle = clientData.dir;
	}

	public function recieveUpdate(data:BulletData){
		clientData = data;

		setPosition(data.x,data.y);
		angle = data.dir;
	}
}

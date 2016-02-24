package ;

import flixel.util.FlxColor;
import flixel.FlxSprite;
import flixel.util.FlxTimer;
import flixel.FlxG;

class Ball extends FlxSprite {
	public function new (X,Y){
		super(X,Y);

		makeGraphic(10,10,FlxColor.WHITE);

		velocity.x = 330;

		elasticity = 1;
	}

	override public function update (e){
		super.update(e);

		/*if (y < 0){
			velocity.y *= -1;
			FlxG.camera.shake(0.01,0.1);
			FlxG.sound.play("assets/sounds/pop.wav");
		}
		if (y+height > FlxG.height){
			velocity.y *= -1;
			FlxG.camera.shake(0.01,0.1);
			FlxG.sound.play("assets/sounds/pop.wav");
		}*/
	}

	public function resetBall () {
		x = FlxG.width/2;
		y = FlxG.height/2;

		velocity.set();

		//new FlxTimer(2, function (timer){
		//	velocity.x = 330;
		//} );
	}
}

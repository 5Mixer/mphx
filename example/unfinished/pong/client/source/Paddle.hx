package ;

import flixel.FlxSprite;
import flixel.util.FlxColor;
import flixel.FlxG;

class Paddle extends FlxSprite {

	public function new (X,Y) {
		super(X,Y);

		makeGraphic(10,50,FlxColor.WHITE);

		immovable = true;
	}

}

package ;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.util.FlxColor;
import flixel.util.FlxDestroyUtil;
import flixel.util.FlxGradient;
import flixel.math.FlxPoint;
import flixel.math.FlxRandom;
import flixel.addons.display.FlxStarField;

class Stars extends flixel.addons.display.FlxStarField2D
{
	private var lastCamX:Float =0;
	private var lastCamY:Float =0;

	public function new(X:Int = 0, Y:Int = 0, Width:Int = 0, Height:Int = 0, StarAmount:Int = 300)
	{
		super(X, Y, Width, Height, StarAmount);
		setStarDepthColors(5, 0xff585858, 0xffF4F4F4);

		lastCamX = FlxG.camera.scroll.x;
		lastCamY = FlxG.camera.scroll.y;

		for (star in _stars)
		{
			star.x = FlxG.random.int(0,FlxG.width);
			star.y = FlxG.random.int(0,FlxG.height);
		}

		scrollFactor.set(0,0);
	}

	override public function update(elapsed:Float):Void
	{
		for (star in _stars)
		{
			//These if statements need to make sure that the camera isn't at 0 because when we follow
			//A new target with camera.follow, for a single frame the camera is at 0,0, which can mess up
			//The star movement.
			if (FlxG.camera.scroll.x != 0 && lastCamX != 0 && FlxG.camera.scroll.y != 0 && lastCamY != 0){

				star.x -= (((FlxG.camera.scroll.x-lastCamX) *star.speed)* elapsed) /5;
				star.y -= (((FlxG.camera.scroll.y-lastCamY) *star.speed)* elapsed) /5;

			}
			// wrap the star
			if (star.x > width)
			{
				star.x = 0;
				star.y = FlxG.random.int(0,FlxG.height);
			}
			else if (star.x < 0)
			{
				star.x = FlxG.width;
				star.y = FlxG.random.int(0,FlxG.height);
			}

			if (star.y > height)
			{
				star.y = 0;
				star.x = FlxG.random.int(0,FlxG.width);
			}
			else if (star.y < 0)
			{
				star.y = FlxG.height;
				star.x = FlxG.random.int(0,FlxG.width);
			}
		}
		if (lastCamX != FlxG.camera.scroll.x) lastCamX = FlxG.camera.scroll.x;
		if (lastCamY != FlxG.camera.scroll.y) lastCamY = FlxG.camera.scroll.y;
	}
}

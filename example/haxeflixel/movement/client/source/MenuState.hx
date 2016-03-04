package ;

import flixel.addons.ui.FlxInputText;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;

class MenuState extends FlxState
{
	override public function create():Void
	{
		var title = new flixel.text.FlxText(0,35,"MPHX Movement Demo",32);
		title.x = FlxG.width/2 - title.width/2;
		add(title);

		var instructions = new flixel.text.FlxText(0,100,"Type the server IP below.",16);
		instructions.x = FlxG.width/2 - instructions.width/2;
		add(instructions);

		var ipInput = new FlxInputText(0,130,200,"",16);
		ipInput.x = FlxG.width/2 - ipInput.width/2;

		add(ipInput);

		ipInput.callback = function (text,action)
		{
			if (action == "enter"){
				GameData.ip = text;
				trace("Connection to IP: "+text);
				FlxG.switchState(new PlayState());
			}
		}
	}
}

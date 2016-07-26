package ;

typedef PlayerData = {
	x: Int,
	y: Int,
	id: String
}

class Player extends flixel.FlxSprite {
	public var data:PlayerData = null;

	public var targetx = 0;
	public var targety = 0;
	var localPlayer = false;

	public function new (_data:PlayerData,isLocalPlayer = false){
		super(_data.x,_data.y);
		makeGraphic(60,60);

		localPlayer = isLocalPlayer;

		targetx = Math.round(x);
		targety = Math.round(y);

		data = _data;
	}
	override public function update (elapsed:Float){
		super.update(elapsed);

		if (!localPlayer){
			x += (targetx-x)/3;
			y += (targety-y)/3;
		}

		data.x = Math.floor(x);
		data.y = Math.floor(y);
	}

}

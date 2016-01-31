package ;

typedef PlayerData = {
	x: Int,
	y: Int,
	id: String
}

class Player extends flixel.FlxSprite {
	public var data:PlayerData = null;

	public function new (_data:PlayerData){
		super(_data.x,_data.y);
		makeGraphic(60,60);

		data = _data;
	}
	override public function update (){
		super.update();
		data.x = Math.floor(x);
		data.y = Math.floor(y);
	}

}

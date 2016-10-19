package ;

import phoenix.Texture;

class Player extends luxe.Sprite {
	public var isLocal = false;
	public var data:PlayerData;

	public function new (isLocal = false,data){
		this.isLocal = isLocal;

		this.data = data;

		var image = Luxe.resources.texture('assets/car.png');
		image.filter_min = image.filter_mag = FilterType.nearest;

		super({
			name: 'player',
			name_unique: true,
			texture: image,
			pos: new luxe.Vector(data.x,data.y),
			size: new luxe.Vector(32,16)
		});

	}
	override public function init () {
		add(new CarMovement());
	}
	public function receiveData (data: PlayerData) {
		this.data = data;
		this.pos.x = data.x;
		this.pos.y = data.y;
		this.rotation_z = data.angle;
	}
	override function update (dt){
		super.update(dt);

		
	}
}

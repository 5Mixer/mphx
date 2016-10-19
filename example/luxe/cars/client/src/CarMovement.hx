package ;

class CarMovement extends luxe.Component {
	public var turningSpeed = 2;
	public var controls = {
		up : false,
		left : false,
		right : false
	};
	var player:Player;

	override public function new (){
		super ({
			name: 'car movement'
		});
	}
	override public function init () {
		player = cast entity;
	}
	override public function update(dt:Float){

		if(controls.left) {
			player.data.angle -= turningSpeed;
		}
		if(controls.right) {
			player.data.angle += turningSpeed;
		}
		if(controls.up) {
			player.data.speed = 200;
		}else{
			if (player.data.speed > 0)
				player.data.speed -= 20;
		}

		player.rotation_z = player.data.angle;
		player.pos.x += Math.cos(player.data.angle * Math.PI / 180) * player.data.speed * dt;
		player.pos.y += Math.sin(player.data.angle * Math.PI / 180) * player.data.speed * dt;
		player.data.x = Math.round(player.pos.x);
		player.data.y = Math.round(player.pos.y);




	}
}

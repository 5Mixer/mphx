package ;

import mphx.client.Client;

class LocalPlayer extends luxe.Component {
	var socket:Client;
	var player:Player;
	public function new (socket){
		this.socket = socket;
		super ({
			name: 'localPlayer'
		});
	}
	override function init () {
		player = cast entity;

		trace(player);
	}
	override function update (dt) {
		super.update(dt);

		var requiresUpdate = false;

		if(Luxe.input.inputdown('left')) {
			//this.socket.send("keydown","left");
			requiresUpdate = true;
		}
		if(Luxe.input.inputdown('right')) {
			//this.socket.send("keydown","right");
			requiresUpdate = true;
		}
		if(Luxe.input.inputdown('up')) {
			//this.socket.send("keydown","up");
			requiresUpdate = true;
		}

		cast(player.get('car movement'), CarMovement).controls.left = Luxe.input.inputdown('left');
		cast(player.get('car movement'), CarMovement).controls.right = Luxe.input.inputdown('right');
		cast(player.get('car movement'), CarMovement).controls.up = Luxe.input.inputdown('up');

		if(Luxe.input.inputreleased('up')){
			//this.socket.send("keyup","up");
			requiresUpdate = true;
		}
		if(Luxe.input.inputreleased('left')){
			//this.socket.send("keyup","left");
			requiresUpdate = true;
		}
		if(Luxe.input.inputreleased('right')){
			//this.socket.send("keyup","right");
			requiresUpdate = true;
		}

		if (requiresUpdate){
			//this.socket.send("update",player.data);
			this.socket.send('keydown',cast(player.get('car movement'), CarMovement).controls);
		}
	}
}

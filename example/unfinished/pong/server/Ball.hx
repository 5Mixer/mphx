package ;

class Ball {
	public var x:Int;
	public var y:Int;
	public var vx:Int; //Speed on x axis (velocity x)
	public var vy:Int; //Speed on y axis (velocity y)
	var width = 10;
	var height = 10;

	public function new (_x:Int,_y:Int,_vx,_vy){
		x=_x;
		y=_y;
		vx=_vx;
		vy=_vy;
	}

	public function update (elapsed:Float){
		x += Math.floor(vx*elapsed);
		y += Math.floor(vy*elapsed);

		if (y < 0){
			vy *= -1;
		}
		if (y+height > Main.clientWindowHeight){
			vy *= -1;
		}
	}

	public function collide(paddle) {

		if (x < paddle.x + 10 &&
		   x + width > paddle.x &&
		   y < paddle.y + 50 &&
		   height + y > paddle.y) {

			//Collision
			trace("COLLIDE!!!!!!!");
			vy = Math.floor(((y+height/2) - (paddle.y+paddle.height/2))*6);
			vx *= -1;
		}
	}
}

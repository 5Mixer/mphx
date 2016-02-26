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
			y=0;
		}
		if (y+height > Main.clientWindowHeight){
			vy *= -1;
			y=Main.clientWindowHeight-height;
		}
		if (x < -width){
			reset();
		}
		if (x>Main.clientWindowWidth){
			reset();
		}
	}
	public function reset(){
		vy=0;
		vx=-330;
		x=Math.floor(Main.clientWindowWidth/2);
		y=Math.floor(Main.clientWindowHeight/2);
	}

	public function collide(paddle:{x:Int,y:Int,width:Int,height:Int}) {

			if (x <= paddle.x + paddle.width &&
                paddle.x <= x + width &&
                y <= paddle.y + paddle.height &&
                paddle.y <= y + height){

				trace("Collision");

				//Collision
				vy = Math.floor(((y+(height/2)) - (paddle.y+(paddle.height/2)))*6);

				vx *= -1;

				if (x < Main.clientWindowWidth/2){
					x = 40;
				}else{
					x = Main.clientWindowWidth-50;
				}
		}
	}
}

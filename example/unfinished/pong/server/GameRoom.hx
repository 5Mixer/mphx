package ;

class GameRoom extends mphx.server.Room {

	public var ball:Ball;
	var server:Main; //This is bad. Rooms should easily be able to store player data

	public function new (main:Main){
		super();

		server = main;

		//Ball in the middle of the screen travelling to the right.
		ball = new Ball(Math.floor(Main.clientWindowWidth/2), Math.floor(Main.clientWindowHeight/2),0,0);
	}


	public function update (elapsed:Float){

		ball.update(elapsed);
		for (connection in connections){

			//IF GAMESTARTED - Fixit.
			//if (ball.vx != 0){
				//trace((server.players.get(connection).left) ? 30 : Main.clientWindowWidth - 40);

				ball.collide({
					width: 10,
					height: 50,
					x: (server.players.get(connection).left) ? 30 : Main.clientWindowWidth - 40,
					y: server.players.get(connection).y
				});
			//}

		}

		for (connection in connections){
			connection.send("updateBall",{
				x:ball.x,
				y:ball.y,
				vx:ball.vx,
				vy:ball.vy
			});
		}
	}
}

package ;

typedef PlayerData = {
	y:Int,
	left: Bool,
	id:String
}

class Main {
	public var players:Map<mphx.connection.IConnection,PlayerData>;

	public static var clientWindowWidth:Int = 640;
	public static var clientWindowHeight:Int = 480;

	var server:mphx.server.impl.Server;

	var time:Float=0;

	public function new () {
		server = new mphx.server.impl.Server("127.0.0.1",8000);

		players = new Map();

		server.events.on("Join",function(data:Dynamic,sender:mphx.connection.IConnection){
			trace("New player with id "+data.id);

			var lobbyRoom:mphx.server.room.Room = null;
			for (room in server.rooms){
				if (room.connections.length == 1){
					lobbyRoom = room;
					break;
				}
			}
			if (lobbyRoom != null){
				//There is a lobby room we can join - join it!
				sender.putInRoom(lobbyRoom);
				sender.send("playerSide","right");

				data.left = false;

				cast(sender.room,GameRoom).ball.vx = 330;
			}else{
				//There is not a lobby room - create one!
				var room = new GameRoom(this);
				server.rooms.push(room);
				sender.putInRoom(room);


				data.left = true;
			}

			players.set(sender,data);
		});

		server.events.on("Update Position",function(data:Dynamic,sender:mphx.connection.IConnection){
			//trace("Player with id "+data.id+" moved to Y: "+data.y+" in a room with "+sender.room.connections.length+" people in it.");
			var newData = players.get(sender);
			newData.y = data.y;
			players.set(sender,newData);
			sender.room.broadcast("Player Moved",newData);
		});

		server.listen();
		trace("Server started.");

		time = haxe.Timer.stamp();
		while (true) {

			server.update();
			update(haxe.Timer.stamp() - time);

			time = haxe.Timer.stamp();
			Sys.sleep(0.05); // wait for 1 ms to prevent full cpu usage. (0.01)
		}
	}

	public function update(elapsed:Float) {
		for (room in server.rooms){
			cast(room,GameRoom).update(elapsed);
		}
	}

	public static function main() {
		new Main();
	}
}

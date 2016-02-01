package ;

typedef PlayerData = {
	y:Int,
	id:String
}

class Main {

	var players:Map<mphx.tcp.Connection,PlayerData>;

	public function new () {
		var server = new mphx.server.Server("127.0.0.1",8000);

		players = new Map<mphx.tcp.Connection,PlayerData>();

		server.events.on("Join",function(data:Dynamic,sender:mphx.tcp.Connection){
			trace("New player with id "+data.id);

			var lobbyRoom:mphx.server.Room = null;
			for (room in server.rooms){
				if (room.connections.length == 1){
					lobbyRoom = room;
					break;
				}
			}
			if (lobbyRoom != null){
				//There is a lobby room we can join - join it!
				sender.putInRoom(lobbyRoom);

			}else{
				//There is not a lobby room - create one!
				var room = new mphx.server.Room();
				server.rooms.push(room);
				sender.putInRoom(room);
			}

			players.set(sender,data);
		});

		server.events.on("Update Position",function(data:Dynamic,sender:mphx.tcp.Connection){
			trace("Player with id "+data.id+" moved to Y: "+data.y+" in a room with "+sender.room.connections.length+" people in it.");
			players.set(sender,data);
			sender.room.broadcast("Player Moved",data);
		});

		server.start();
	}
	public static function main () {
		new Main();
	}
}

package;

import mphx.server.Server;
import mphx.tcp.IConnection;
import mphx.tcp.Connection;
// import GameRoom;

class Main {
    public static function main() {
        var rooms = new Map<String, GameRoom>();
		var server = new Server('127.0.0.1', 8000);

        server.events.on('join_game', function(data :Dynamic, client :IConnection) {
            for (room in rooms) {
                if (!room.started) {
                    trace('· Joining existing room; ${room.id}');
                    client.putInRoom(room);
                    return;
                }
            }

            trace('· No available room; creating a new room');
            var room = new GameRoom();
            rooms[room.id] = room;
			client.putInRoom(room);
		});

        server.events.on('move', function(data :Dynamic, client :IConnection) {
            var room_id = data.room_id;
            if (room_id == null) {
                trace('room_id undefined!');
                return;
            }
            if (!rooms.exists(room_id)) {
                trace('game room with id ${room_id} not found!');
                return;
            }
            var room = rooms[room_id];
            room.take_turn(data.move);
		});

		server.start();
	}
}

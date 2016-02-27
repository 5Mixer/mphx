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
                    // trace('· Joining existing room; ${room.id}');
                    client.putInRoom(room);
                    return;
                }
            }

            // trace('· No available room; creating a new room');
            var room = new GameRoom();
            rooms[room.id] = room;
			client.putInRoom(room);
		});

        function handle_action(room_id :String, action :String, ?data :Dynamic) {
            if (room_id == null) {
                trace('room_id undefined!');
                return;
            }
            if (!rooms.exists(room_id)) {
                trace('game room with id ${room_id} not found!');
                return;
            }
            var room = rooms[room_id];
            room.handle(action, data);
        }

        server.events.on('move', function(data :Dynamic, client :IConnection) {
            handle_action(data.room_id, 'move', data.pos);
		});

        server.events.on('remove', function(data :Dynamic, client :IConnection) {
            handle_action(data.room_id, 'remove', data.pos);
		});

		server.start();
	}
}

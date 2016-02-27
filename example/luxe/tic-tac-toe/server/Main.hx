package;

import mphx.server.*;
import mphx.tcp.IConnection;
import mphx.tcp.Connection;

class Main {
    public static function main() {
        var rooms = new Map<String, GameRoom>();
		var server = new Server('127.0.0.1', 8000);

        server.events.on('join_game', function(data :Dynamic, client :IConnection) {
            trace('join_game');
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
            trace('move');
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

class GameRoom extends Room {
    var required_players :Int = 2;
    public var started = false;
    static var counter :Int = 0;
    public var id :String;
    var current_player = 0;

    public function new() {
        super();
        id = 'room_' + (++counter);
    }

    override public function onLeave(client :Connection) {
		super.onLeave(client);
        if (started) {
            trace('game_stopped');
            broadcast('game_stopped');
        }
	}

	override public function onJoin(client :Connection) {
        if (!super.onJoin(client)) return false;

        trace('game_joined');
        broadcast('game_joined', { room_id: id });

		if (connections.length == required_players) {
            started = true;
            trace('game_started');
            broadcast('game_started');
            trace('start_turn');
            connections[current_player].send('start_turn');
        } else { // wait
            trace('game_waiting');
            broadcast('game_waiting', { players_missing: required_players - connections.length });
        }
        return true;
	}

    public function take_turn(pos :Dynamic) {
        var symbols = ['X', 'O'];
        trace('move');
        broadcast('move', { symbol: symbols[current_player], pos: pos });
        current_player = (current_player + 1) % required_players;
        trace('start_turn');
        connections[current_player].send('start_turn');
    }
}

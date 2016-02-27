package;

import mphx.server.Room;
import mphx.tcp.Connection;

class GameRoom extends Room {
    var required_players :Int = 2;
    public var started = false;
    static var counter :Int = 0;
    public var id :String;
    var current_player :Int;
    var turn :Int;
    var tiles :Array<Array<Int>>;

    public function new() {
        super();
        id = 'room_' + (++counter);
    }

    override public function onLeave(client :Connection) {
		super.onLeave(client);
        if (started) {
            broadcast('game_stopped');
            started = false;
        }
	}

	override public function onJoin(client :Connection) {
        if (!super.onJoin(client)) return false;

        broadcast('game_joined', { room_id: id });

		if (connections.length == required_players) {
            turn = 0;
            current_player = 0;
            tiles = [ for (y in 0 ... 3) [ for (x in 0 ... 3) -1 ] ];
            started = true;
            broadcast('game_started');
            connections[current_player].send('start_turn', { remove_symbol: '' });
        } else { // wait for required number of players
            broadcast('game_waiting', { players_missing: (required_players - connections.length) });
        }
        return true;
	}

    public function handle(action :String, pos :Dynamic) {
        var symbols = ['X', 'O'];
        if (action == 'remove') {
            tiles[pos.y][pos.x] = -1;
            broadcast('remove', { pos: pos });
        } else if (action == 'move') {
            tiles[pos.y][pos.x] = current_player;
            turn++;
            broadcast('move', { symbol: symbols[current_player], pos: pos });
            if (has_won(current_player)) {
                for (i in 0 ... connections.length) {
                    var client = connections[i];
                    client.send((i == current_player) ? 'won' : 'lost');
                }
            } else {
                current_player = (current_player + 1) % required_players;
                connections[current_player].send('start_turn', { remove_symbol: (turn >= 6 ? symbols[current_player] : '') });
            }
        }
    }

    function has_won(id :Int) :Bool {
        for (y in 0 ... 3) {
            var won = true;
            for (x in 0 ... 3) {
                if (tiles[y][x] != id) won = false;
            }
            if (won) return true;
        }

        for (x in 0 ... 3) {
            var won = true;
            for (y in 0 ... 3) {
                if (tiles[y][x] != id) won = false;
            }
            if (won) return true;
        }

        if (tiles[0][0] == id && tiles[1][1] == id && tiles[2][2] == id) return true;
        if (tiles[0][2] == id && tiles[1][1] == id && tiles[2][0] == id) return true;
        return false;
    }
}

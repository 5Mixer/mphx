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
            broadcast('remove', { pos: pos });
        } else if (action == 'move') {
            turn++;
            broadcast('move', { symbol: symbols[current_player], pos: pos });
            current_player = (current_player + 1) % required_players;
            connections[current_player].send('start_turn', { remove_symbol: (turn > 6 ? symbols[current_player] : '') });
        }
    }
}

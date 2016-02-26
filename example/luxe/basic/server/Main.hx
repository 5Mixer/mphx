package;

class Main {
    public static function main() {
        var players = 0;
		var socket = new mphx.server.Server('127.0.0.1', 8001);

        socket.events.on('join', function(data :Dynamic, sender :mphx.tcp.IConnection) {
            sender.send('accepted', { playerId: 'Player ' + (++players) });
		});

		socket.events.on('move', function(data :Dynamic, sender :mphx.tcp.IConnection) {
			socket.broadcast('moved', data);
		});

		socket.start();
	}
}

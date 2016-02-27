package;

class Main {
    public static function main() {
        var players = 0;
		var server = new mphx.server.Server('127.0.0.1', 8001);

        server.events.on('join', function(data :Dynamic, client :mphx.tcp.IConnection) {
            client.send('accepted', { playerId: 'Player ' + (++players) });
		});

		server.events.on('move', function(data :Dynamic, client :mphx.tcp.IConnection) {
			server.broadcast('moved', data);
		});

		server.start();
	}
}

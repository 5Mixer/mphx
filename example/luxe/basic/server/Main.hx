package;

class Main {
    public static function main() {
        var players = 0;
		var server = new mphx.server.impl.Server('127.0.0.1', 8001);

        server.events.on('join', function(data :Dynamic, client :mphx.connection.IConnection) {
            client.send('accepted', { playerId: 'Player ' + (++players) });
		});

		server.events.on('move', function(data :Dynamic, client :mphx.connection.IConnection) {
			server.broadcast('moved', data);
		});

		server.start();
	}
}

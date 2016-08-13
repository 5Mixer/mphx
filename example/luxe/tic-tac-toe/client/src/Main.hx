package;

import luxe.Input;
import luxe.Vector;

import mphx.client.Client;

class Main extends luxe.Game {
    var client :Client = null;
    var my_turn :Bool = false;
    var room_id :String;
    var boxes :Array<Box>;

    var statusText :luxe.Text;
    var hudScene :luxe.Scene;
    var removing :Bool;
    var symbol :String;
    var gameOver :Bool = false;

    override function config(config :luxe.GameConfig) {
        config.render.antialiasing = 2;
        return config;
    }

    override function ready() {
        hudScene = new luxe.Scene();
        statusText = new luxe.Text({
            pos: new Vector(Luxe.screen.mid.x, 50),
            text: '',
            point_size: 36,
            align: luxe.Text.TextAlign.center,
            align_vertical: luxe.Text.TextAlign.center,
            color: new luxe.Color(0.8, 0.8, 0.8),
            scene: hudScene
        });

        client = new Client('127.0.0.1', 8000);

        client.events.on('game_joined', function(data) {
            room_id = data.room_id;
        });

        client.events.on('game_started', function(_) {
            Luxe.scene.empty();
            boxes = [];
            gameOver = false;
            statusText.text = 'Opponent\'s turn';
            Luxe.renderer.clear_color.tween(0.3, { r: 0.25, b: 0.1 });

            for (y in 0 ... 3) {
                for (x in 0 ... 3) {
                    var box = new Box(x, y);
                    box.events.listen('click', function(_) {
                        click_box(box);
                    });
                    boxes.push(box);
                }
            }
        });

        client.events.on('game_waiting', function(data) {
            statusText.text = 'Waiting for ${data.players_missing} player(s)';
            Luxe.renderer.clear_color.tween(0.3, { r: 0.15, b: 0.15 });
        });

        client.events.on('start_turn', function(data) {
            removing = data.must_remove;
            symbol = data.symbol;
            if (removing) {
                statusText.text = 'Your turn; remove an "$symbol"';
            } else {
                statusText.text = 'Your turn; place an "$symbol"';
            }
            Luxe.renderer.clear_color.tween(0.3, { r: 0.1, b: 0.25 });
            my_turn = true;
        });

        client.events.on('remove', function(data) {
            set_box_symbol(data.pos.x, data.pos.y, '');
        });

        client.events.on('move', function(data) {
            Luxe.camera.shake(1);
            set_box_symbol(data.pos.x, data.pos.y, data.symbol);
        });

        client.events.on('won', function(data) {
            Luxe.renderer.clear_color.tween(0.6, { r: 0.2, b: 0.5 });
            gameOver = true;
            Luxe.camera.shake(3);
            statusText.text = 'You won!\nClick to play again';
        });

        client.events.on('lost', function(data) {
            Luxe.renderer.clear_color.tween(0.6, { r: 0.5, b: 0.2 });
            gameOver = true;
            Luxe.camera.shake(3);
            statusText.text = 'You lost!\nClick to play again';
        });

        client.events.on('game_stopped', function(data) {
            statusText.text = 'Game stopped';
        });

        var retry_timer = null;
        client.onConnectionError = function(reason :String) {
            var wait_seconds = 5;
            statusText.text = 'Connection error!\nRetrying in $wait_seconds... ';
            if (retry_timer != null) retry_timer.stop();
            retry_timer = Luxe.timer.schedule(1, function() {
                wait_seconds--;
                if (wait_seconds == 0) {
                    statusText.text = 'Connecting...';
                    client.connect();
                } else {
                    statusText.text += wait_seconds + '... ';
                }
            }, true);
        };

        client.onConnectionEstablished = function() {
            if (retry_timer != null) retry_timer.stop();
            client.send('join_game');
        };

        client.connect();
    }

    function set_box_symbol(x :Int, y :Int, symbol :String) {
        for (box in boxes) {
            if (box.x == x && box.y == y) {
                box.assign(symbol);
            }
        }
    }

    function click_box(box :Box) {
        if (!my_turn) return;
        if (removing) {
            if (box.get_symbol() == symbol) {
                client.send('remove', { room_id: room_id, pos: { x: box.x, y: box.y } });
                statusText.text = 'Your turn; place an "$symbol"';
                removing = false;
            }
        } else {
            if (box.has_symbol()) return;
            statusText.text = 'Opponent\'s turn';
            Luxe.renderer.clear_color.tween(0.3, { r: 0.25, b: 0.1 });
            client.send('move', { room_id: room_id, pos: { x: box.x, y: box.y } });
            my_turn = false;
        }
    }

    override function onmousedown(_) {
        if (gameOver) {
            client.close();
            client.connect();
        }
    }

    override function onrender() {
        #if cpp
        if (client != null) client.update();
        #end
    }

    override function onkeyup(e :KeyEvent) {
        if (e.keycode == Key.escape) {
            Luxe.shutdown();
        }
    }
}

import enet.ENet;
import org.msgpack.MsgPack;

class Server {

    static function main() {

        var event:ENetEvent = null;
        var eventStatus = 1;

        if (ENet.initialize() != 0) {
            trace("An error occurred while initializing ENet.");
            return;
        }

        var adr:ENetAddress = null;
        adr.host = ENet.ENET_HOST_ANY;
        adr.port = 1234;

        var server:ENetHost = ENet.host_create(cast adr, 32, 2, 0, 0);
        if (server == null) {
            trace("An error occurred while trying to create an ENet server host.");
            ENet.deinitialize();
            return;
        }

        trace("Server is listening on port " + adr.port);

        while(true) {
            eventStatus = ENet.host_service(server, cast event, 50);
            if (eventStatus > 0) {
                trace("event on server");
                
                var peer = event.peer;
                var adress = peer.address;
                var host = adress.host;

                switch(event.type) {
                    case ENetEventType.ENET_EVENT_TYPE_CONNECT:

                        trace('Server got a new connection from $host');

                    case ENetEventType.ENET_EVENT_TYPE_RECEIVE:

                        var b = event.packet.getDataBytes();
                        var payload = MsgPack.decode(b);
                        trace("Server received message from "+host+" - "+payload);

                        // broadcast to all connected clients
                        ENet.host_broadcast(server, 0, event.packet);

                    case ENetEventType.ENET_EVENT_TYPE_DISCONNECT:

                        trace('$host disconnected from Server');

                    default:
                }
            }
        }

        ENet.host_destroy(cast server);

        ENet.deinitialize();
    }
}

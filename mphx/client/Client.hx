package mphx.client;

typedef Client = #if js WebsocketClient; #else TcpClient; #end

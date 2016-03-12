package mphx.client;

typedef Client = #if js WebsocketClient; #elseif flash TcpFlashClient; #else TcpClient; #end

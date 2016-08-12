package mphx.client;

#if js
import mphx.client.impl.WebsocketClient;
typedef Client = WebsocketClient;
#elseif flash
import mphx.client.impl.TcpFlashClient;
typedef Client = TcpFlashClient;
#else
import mphx.client.impl.TcpClient;
typedef Client = TcpClient;
#end

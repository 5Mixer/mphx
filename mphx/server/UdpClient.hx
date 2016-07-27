package mphx.server;

// #if cpp
// import mphx.client.impl.WebsocketClient;
// typedef Client = WebsocketClient;
// #else
import mphx.client.impl.UdpNativeServer;
typedef UdpClient = UdpNativeServer;
// #end

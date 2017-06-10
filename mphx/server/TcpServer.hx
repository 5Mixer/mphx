package mphx.server;

#if js

#else
typedef TcpServer = mphx.server.impl.FlashServer;
#end
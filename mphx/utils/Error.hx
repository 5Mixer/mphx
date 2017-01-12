package mphx.utils;

enum ClientError {
	ServerUnavaliable;
	DroppedConnection;
	Other(reason:String);
}
enum ServerError {
	CorruptData;
	Other(reason:String);
}

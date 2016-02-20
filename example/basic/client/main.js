(function (console) { "use strict";
var HxOverrides = function() { };
HxOverrides.indexOf = function(a,obj,i) {
	var len = a.length;
	if(i < 0) {
		i += len;
		if(i < 0) i = 0;
	}
	while(i < len) {
		if(a[i] === obj) return i;
		i++;
	}
	return -1;
};
HxOverrides.remove = function(a,obj) {
	var i = HxOverrides.indexOf(a,obj,0);
	if(i == -1) return false;
	a.splice(i,1);
	return true;
};
var Main = function() {
	this.clientSocket = new mphx_client_WebsocketClient("127.0.0.1",8000);
	this.clientSocket.connect();
	this.clientSocket.send("Hello",123);
	this.clientSocket.events.on("Direct Message",function(data) {
		console.log("Server sent a 'Direct message' with data " + data);
	});
	this.clientSocket.events.on("Server wide broadcast",function(data1) {
		console.log("server broadcasted a server wide message. Data was " + data1);
	});
};
Main.main = function() {
	new Main();
};
var haxe_IMap = function() { };
var haxe_ds_StringMap = function() {
	this.h = { };
};
haxe_ds_StringMap.__interfaces__ = [haxe_IMap];
haxe_ds_StringMap.prototype = {
	set: function(key,value) {
		if(__map_reserved[key] != null) this.setReserved(key,value); else this.h[key] = value;
	}
	,get: function(key) {
		if(__map_reserved[key] != null) return this.getReserved(key);
		return this.h[key];
	}
	,exists: function(key) {
		if(__map_reserved[key] != null) return this.existsReserved(key);
		return this.h.hasOwnProperty(key);
	}
	,setReserved: function(key,value) {
		if(this.rh == null) this.rh = { };
		this.rh["$" + key] = value;
	}
	,getReserved: function(key) {
		if(this.rh == null) return null; else return this.rh["$" + key];
	}
	,existsReserved: function(key) {
		if(this.rh == null) return false;
		return this.rh.hasOwnProperty("$" + key);
	}
};
var mphx_client_EventManager = function() {
	this.eventMap = new haxe_ds_StringMap();
};
mphx_client_EventManager.prototype = {
	on: function(eventName,event) {
		this.eventMap.set(eventName,event);
	}
	,callEvent: function(eventName,data) {
		if(this.eventMap.exists(eventName) == true) this.eventMap.get(eventName)(data);
	}
};
var mphx_client_IClient = function() { };
var mphx_client_WebsocketClient = function(_ip,_port) {
	this.ready = false;
	this.events = new mphx_client_EventManager();
	this.ip = _ip;
	this.port = _port;
	this.messageQueue = [];
};
mphx_client_WebsocketClient.__interfaces__ = [mphx_client_IClient];
mphx_client_WebsocketClient.prototype = {
	connect: function() {
		var _g = this;
		this.websocket = new WebSocket("ws://" + this.ip + ":" + this.port);
		this.websocket.onopen = function() {
			_g.ready = true;
			var _g1 = 0;
			var _g2 = _g.messageQueue;
			while(_g1 < _g2.length) {
				var message = _g2[_g1];
				++_g1;
				_g.send(message.t,message.data);
				var x = message;
				HxOverrides.remove(_g.messageQueue,x);
			}
		};
		this.websocket.onmessage = function(line) {
			console.log(line.data);
			var msg = JSON.parse(line.data);
			console.log(msg.data);
			_g.events.callEvent(msg.t,msg.data);
		};
	}
	,send: function(event,data) {
		var object = { t : event, data : data};
		if(this.ready == true) {
			var serialiseObject = JSON.stringify(object);
			this.websocket.send(serialiseObject + "\r\n");
		} else this.messageQueue.push(object);
	}
	,update: function(timeout) {
		if(timeout == null) timeout = 0;
	}
	,close: function() {
		this.websocket.close(0,"Close requested");
	}
};
if(Array.prototype.indexOf) HxOverrides.indexOf = function(a,o,i) {
	return Array.prototype.indexOf.call(a,o,i);
};
var __map_reserved = {}
Main.main();
})(typeof console != "undefined" ? console : {log:function(){}});

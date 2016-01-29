#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_ds_ObjectMap
#include <haxe/ds/ObjectMap.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_BytesInput
#include <haxe/io/BytesInput.h>
#endif
#ifndef INCLUDED_haxe_io_Eof
#include <haxe/io/Eof.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_mphx_core_EventManager
#include <mphx/core/EventManager.h>
#endif
#ifndef INCLUDED_mphx_server_Server
#include <mphx/server/Server.h>
#endif
#ifndef INCLUDED_mphx_tcp_Connection
#include <mphx/tcp/Connection.h>
#endif
#ifndef INCLUDED_mphx_tcp_Protocol
#include <mphx/tcp/Protocol.h>
#endif
#ifndef INCLUDED_sys_net_Host
#include <sys/net/Host.h>
#endif
#ifndef INCLUDED_sys_net_Socket
#include <sys/net/Socket.h>
#endif
namespace mphx{
namespace server{

Void Server_obj::__construct(::String hostname,int port)
{
HX_STACK_FRAME("mphx.server.Server","new",0xe0209725,"mphx.server.Server.new","mphx/server/Server.hx",12,0x7ecb9dcb)
HX_STACK_THIS(this)
HX_STACK_ARG(hostname,"hostname")
HX_STACK_ARG(port,"port")
{
	HX_STACK_LINE(17)
	this->blocking = true;
	HX_STACK_LINE(23)
	::haxe::io::Bytes tmp = ::haxe::io::Bytes_obj::alloc((int)8192);		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(23)
	this->buffer = tmp;
	HX_STACK_LINE(25)
	bool tmp1 = (hostname == null());		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(25)
	if ((tmp1)){
		HX_STACK_LINE(25)
		::String tmp2 = ::sys::net::Host_obj::localhost();		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(25)
		hostname = tmp2;
	}
	HX_STACK_LINE(27)
	this->host = hostname;
	HX_STACK_LINE(28)
	this->port = port;
	HX_STACK_LINE(30)
	::mphx::core::EventManager tmp2 = ::mphx::core::EventManager_obj::__new();		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(30)
	this->events = tmp2;
	HX_STACK_LINE(32)
	::sys::net::Socket tmp3 = ::sys::net::Socket_obj::__new();		HX_STACK_VAR(tmp3,"tmp3");
	HX_STACK_LINE(32)
	this->listener = tmp3;
	HX_STACK_LINE(34)
	::sys::net::Socket tmp4 = this->listener;		HX_STACK_VAR(tmp4,"tmp4");
	HX_STACK_LINE(34)
	this->readSockets = Array_obj< ::Dynamic >::__new().Add(tmp4);
	HX_STACK_LINE(35)
	::haxe::ds::ObjectMap tmp5;		HX_STACK_VAR(tmp5,"tmp5");
	HX_STACK_LINE(35)
	{
		HX_STACK_LINE(35)
		::haxe::ds::ObjectMap tmp6 = ::haxe::ds::ObjectMap_obj::__new();		HX_STACK_VAR(tmp6,"tmp6");
		HX_STACK_LINE(35)
		::haxe::ds::ObjectMap tmp7 = tmp6;		HX_STACK_VAR(tmp7,"tmp7");
		HX_STACK_LINE(35)
		tmp5 = tmp7;
	}
	HX_STACK_LINE(35)
	this->clients = tmp5;
}
;
	return null();
}

//Server_obj::~Server_obj() { }

Dynamic Server_obj::__CreateEmpty() { return  new Server_obj; }
hx::ObjectPtr< Server_obj > Server_obj::__new(::String hostname,int port)
{  hx::ObjectPtr< Server_obj > _result_ = new Server_obj();
	_result_->__construct(hostname,port);
	return _result_;}

Dynamic Server_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Server_obj > _result_ = new Server_obj();
	_result_->__construct(inArgs[0],inArgs[1]);
	return _result_;}

Void Server_obj::listen( ){
{
		HX_STACK_FRAME("mphx.server.Server","listen",0x5a23caa2,"mphx.server.Server.listen","mphx/server/Server.hx",39,0x7ecb9dcb)
		HX_STACK_THIS(this)
		HX_STACK_LINE(40)
		::sys::net::Socket tmp = this->listener;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(40)
		::String tmp1 = this->host;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(40)
		::sys::net::Host tmp2 = ::sys::net::Host_obj::__new(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(40)
		int tmp3 = this->port;		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(40)
		tmp->bind(tmp2,tmp3);
		HX_STACK_LINE(41)
		::sys::net::Socket tmp4 = this->listener;		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(41)
		tmp4->listen((int)1);
		HX_STACK_LINE(42)
		::sys::net::Socket tmp5 = this->listener;		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(42)
		tmp5->setBlocking(false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Server_obj,listen,(void))

Void Server_obj::start( ){
{
		HX_STACK_FRAME("mphx.server.Server","start",0x85ab3667,"mphx.server.Server.start","mphx/server/Server.hx",45,0x7ecb9dcb)
		HX_STACK_THIS(this)
		HX_STACK_LINE(47)
		Dynamic tmp = hx::SourceInfo(HX_HCSTRING("Server.hx","\xbb","\xb3","\xcd","\x1a"),47,HX_HCSTRING("mphx.server.Server","\xb3","\x20","\x9b","\xf4"),HX_HCSTRING("start","\x62","\x74","\x0b","\x84"));		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(47)
		::haxe::Log_obj::trace(HX_HCSTRING("Server active. Anycode after this point will not run, your app will hang.","\x84","\x4c","\x3d","\x0a"),tmp);
		HX_STACK_LINE(48)
		Dynamic tmp1 = hx::SourceInfo(HX_HCSTRING("Server.hx","\xbb","\xb3","\xcd","\x1a"),48,HX_HCSTRING("mphx.server.Server","\xb3","\x20","\x9b","\xf4"),HX_HCSTRING("start","\x62","\x74","\x0b","\x84"));		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(48)
		::haxe::Log_obj::trace(HX_HCSTRING("You can instead call 'update' frequently, and run your code along side it.","\xc6","\xd7","\x08","\xaa"),tmp1);
		HX_STACK_LINE(50)
		this->listen();
		HX_STACK_LINE(51)
		while((true)){
			HX_STACK_LINE(52)
			this->update(null());
			HX_STACK_LINE(53)
			::Sys_obj::sleep(((Float)0.01));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Server_obj,start,(void))

Void Server_obj::update( hx::Null< Float >  __o_timeout){
Float timeout = __o_timeout.Default(0);
	HX_STACK_FRAME("mphx.server.Server","update",0xf12f8864,"mphx.server.Server.update","mphx/server/Server.hx",58,0x7ecb9dcb)
	HX_STACK_THIS(this)
	HX_STACK_ARG(timeout,"timeout")
{
		HX_STACK_LINE(60)
		::mphx::tcp::Protocol protocol;		HX_STACK_VAR(protocol,"protocol");
		HX_STACK_LINE(61)
		int bytesReceived;		HX_STACK_VAR(bytesReceived,"bytesReceived");
		HX_STACK_LINE(62)
		Float tmp = timeout;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(62)
		Dynamic tmp1 = ::sys::net::Socket_obj::select(this->readSockets,null(),null(),tmp);		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(62)
		Dynamic select = tmp1;		HX_STACK_VAR(select,"select");
		HX_STACK_LINE(64)
		{
			HX_STACK_LINE(64)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(64)
			Array< ::Dynamic > _g1 = select->__Field(HX_HCSTRING("read","\x56","\x4b","\xa7","\x4b"), hx::paccDynamic );		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(64)
			while((true)){
				HX_STACK_LINE(64)
				bool tmp2 = (_g < _g1->length);		HX_STACK_VAR(tmp2,"tmp2");
				HX_STACK_LINE(64)
				bool tmp3 = !(tmp2);		HX_STACK_VAR(tmp3,"tmp3");
				HX_STACK_LINE(64)
				if ((tmp3)){
					HX_STACK_LINE(64)
					break;
				}
				HX_STACK_LINE(64)
				::sys::net::Socket tmp4 = _g1->__get(_g).StaticCast< ::sys::net::Socket >();		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(64)
				::sys::net::Socket socket = tmp4;		HX_STACK_VAR(socket,"socket");
				HX_STACK_LINE(64)
				++(_g);
				HX_STACK_LINE(66)
				::sys::net::Socket tmp5 = socket;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(66)
				::sys::net::Socket tmp6 = this->listener;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(66)
				bool tmp7 = (tmp5 == tmp6);		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(66)
				if ((tmp7)){
					HX_STACK_LINE(68)
					::sys::net::Socket tmp8 = this->listener;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(68)
					::sys::net::Socket tmp9 = tmp8->accept();		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(68)
					::sys::net::Socket client = tmp9;		HX_STACK_VAR(client,"client");
					HX_STACK_LINE(69)
					::mphx::tcp::Connection tmp10 = ::mphx::tcp::Connection_obj::__new(client);		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(69)
					::mphx::tcp::Connection connection = tmp10;		HX_STACK_VAR(connection,"connection");
					HX_STACK_LINE(71)
					::sys::net::Socket tmp11 = client;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(71)
					this->readSockets->push(tmp11);
					HX_STACK_LINE(72)
					::haxe::ds::ObjectMap tmp12 = this->clients;		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(72)
					::sys::net::Socket tmp13 = client;		HX_STACK_VAR(tmp13,"tmp13");
					HX_STACK_LINE(72)
					::mphx::tcp::Connection tmp14 = connection;		HX_STACK_VAR(tmp14,"tmp14");
					HX_STACK_LINE(72)
					tmp12->set(tmp13,tmp14);
					HX_STACK_LINE(74)
					client->setBlocking(false);
					HX_STACK_LINE(75)
					::mphx::core::EventManager tmp15 = this->events;		HX_STACK_VAR(tmp15,"tmp15");
					HX_STACK_LINE(75)
					::mphx::tcp::Protocol tmp16 = ::mphx::tcp::Protocol_obj::__new(tmp15);		HX_STACK_VAR(tmp16,"tmp16");
					HX_STACK_LINE(75)
					::mphx::tcp::Protocol tmp17 = protocol = tmp16;		HX_STACK_VAR(tmp17,"tmp17");
					HX_STACK_LINE(75)
					client->custom = tmp17;
					HX_STACK_LINE(76)
					::mphx::tcp::Connection tmp18 = connection;		HX_STACK_VAR(tmp18,"tmp18");
					HX_STACK_LINE(76)
					protocol->onAccept(tmp18);
				}
				else{
					HX_STACK_LINE(81)
					protocol = socket->custom;
					HX_STACK_LINE(83)
					int byte = (int)0;		HX_STACK_VAR(byte,"byte");
					HX_STACK_LINE(84)
					int bytesReceived1 = (int)0;		HX_STACK_VAR(bytesReceived1,"bytesReceived1");
					HX_STACK_LINE(85)
					::haxe::io::Bytes tmp8 = this->buffer;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(85)
					int len = tmp8->length;		HX_STACK_VAR(len,"len");
					HX_STACK_LINE(86)
					while((true)){
						HX_STACK_LINE(86)
						bool tmp9 = (bytesReceived1 < len);		HX_STACK_VAR(tmp9,"tmp9");
						HX_STACK_LINE(86)
						bool tmp10 = !(tmp9);		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(86)
						if ((tmp10)){
							HX_STACK_LINE(86)
							break;
						}
						HX_STACK_LINE(88)
						try
						{
						HX_STACK_CATCHABLE(Dynamic, 0);
						{
							HX_STACK_LINE(91)
							int tmp11 = socket->input->readByte();		HX_STACK_VAR(tmp11,"tmp11");
							HX_STACK_LINE(91)
							byte = tmp11;
						}
						}
						catch(Dynamic __e){
							{
								HX_STACK_BEGIN_CATCH
								Dynamic e = __e;{
									HX_STACK_LINE(96)
									Dynamic tmp11 = e;		HX_STACK_VAR(tmp11,"tmp11");
									HX_STACK_LINE(96)
									Dynamic tmp12 = tmp11;		HX_STACK_VAR(tmp12,"tmp12");
									HX_STACK_LINE(96)
									bool tmp13 = ::Std_obj::is(tmp12,hx::ClassOf< ::haxe::io::Eof >());		HX_STACK_VAR(tmp13,"tmp13");
									HX_STACK_LINE(96)
									bool tmp14 = !(tmp13);		HX_STACK_VAR(tmp14,"tmp14");
									HX_STACK_LINE(96)
									bool tmp15;		HX_STACK_VAR(tmp15,"tmp15");
									HX_STACK_LINE(96)
									if ((tmp14)){
										HX_STACK_LINE(96)
										tmp15 = (e == hx::ClassOf< ::haxe::io::Eof >());
									}
									else{
										HX_STACK_LINE(96)
										tmp15 = true;
									}
									HX_STACK_LINE(96)
									if ((tmp15)){
										HX_STACK_LINE(103)
										break;
									}
									else{
										HX_STACK_LINE(104)
										bool tmp16 = (e == ::haxe::io::Error_obj::Blocked);		HX_STACK_VAR(tmp16,"tmp16");
										HX_STACK_LINE(104)
										if ((tmp16)){
											HX_STACK_LINE(110)
											break;
										}
										else{
											HX_STACK_LINE(112)
											Dynamic tmp17 = e;		HX_STACK_VAR(tmp17,"tmp17");
											HX_STACK_LINE(112)
											Dynamic tmp18 = hx::SourceInfo(HX_HCSTRING("Server.hx","\xbb","\xb3","\xcd","\x1a"),112,HX_HCSTRING("mphx.server.Server","\xb3","\x20","\x9b","\xf4"),HX_HCSTRING("update","\x09","\x86","\x05","\x87"));		HX_STACK_VAR(tmp18,"tmp18");
											HX_STACK_LINE(112)
											::haxe::Log_obj::trace(tmp17,tmp18);
										}
									}
								}
							}
						}
						HX_STACK_LINE(116)
						{
							HX_STACK_LINE(116)
							::haxe::io::Bytes tmp11 = this->buffer;		HX_STACK_VAR(tmp11,"tmp11");
							HX_STACK_LINE(116)
							int tmp12 = byte;		HX_STACK_VAR(tmp12,"tmp12");
							HX_STACK_LINE(116)
							tmp11->b[bytesReceived1] = tmp12;
						}
						HX_STACK_LINE(117)
						hx::AddEq(bytesReceived1,(int)1);
					}
					HX_STACK_LINE(121)
					bool tmp9 = (bytesReceived1 > (int)0);		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(121)
					if ((tmp9)){
						HX_STACK_LINE(123)
						::haxe::io::Bytes tmp10 = this->buffer;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(123)
						int tmp11 = bytesReceived1;		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(123)
						::haxe::io::BytesInput tmp12 = ::haxe::io::BytesInput_obj::__new(tmp10,(int)0,tmp11);		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(123)
						protocol->dataReceived(tmp12);
					}
					HX_STACK_LINE(125)
					bool tmp10 = protocol->isConnected();		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(125)
					bool tmp11 = !(tmp10);		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(125)
					if ((tmp11)){
						HX_STACK_LINE(127)
						Dynamic tmp12 = hx::SourceInfo(HX_HCSTRING("Server.hx","\xbb","\xb3","\xcd","\x1a"),127,HX_HCSTRING("mphx.server.Server","\xb3","\x20","\x9b","\xf4"),HX_HCSTRING("update","\x09","\x86","\x05","\x87"));		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(127)
						::haxe::Log_obj::trace(HX_HCSTRING("NOT CONNECTED","\x3c","\x91","\x52","\x7b"),tmp12);
						HX_STACK_LINE(128)
						::sys::net::Socket tmp13 = socket;		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(128)
						this->readSockets->remove(tmp13);
						HX_STACK_LINE(129)
						::haxe::ds::ObjectMap tmp14 = this->clients;		HX_STACK_VAR(tmp14,"tmp14");
						HX_STACK_LINE(129)
						::sys::net::Socket tmp15 = socket;		HX_STACK_VAR(tmp15,"tmp15");
						HX_STACK_LINE(129)
						tmp14->remove(tmp15);
						HX_STACK_LINE(130)
						break;
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Server_obj,update,(void))

bool Server_obj::broadcast( ::String event,Dynamic data){
	HX_STACK_FRAME("mphx.server.Server","broadcast",0x39c34b86,"mphx.server.Server.broadcast","mphx/server/Server.hx",138,0x7ecb9dcb)
	HX_STACK_THIS(this)
	HX_STACK_ARG(event,"event")
	HX_STACK_ARG(data,"data")
	HX_STACK_LINE(139)
	bool success = true;		HX_STACK_VAR(success,"success");
	HX_STACK_LINE(140)
	::haxe::ds::ObjectMap tmp = this->clients;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(140)
	Dynamic tmp1 = tmp->iterator();		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(140)
	for(::cpp::FastIterator_obj< ::mphx::tcp::Connection > *__it = ::cpp::CreateFastIterator< ::mphx::tcp::Connection >(tmp1);  __it->hasNext(); ){
		::mphx::tcp::Connection client = __it->next();
		{
			HX_STACK_LINE(142)
			Dynamic tmp2 = client->socket->custom;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(142)
			::mphx::tcp::Protocol tmp3;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(142)
			tmp3 = hx::TCast< ::mphx::tcp::Protocol >::cast(tmp2);
			HX_STACK_LINE(142)
			::String tmp4 = event;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(142)
			Dynamic tmp5 = data;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(142)
			bool tmp6 = tmp3->send(tmp4,tmp5);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(142)
			bool tmp7 = !(tmp6);		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(142)
			if ((tmp7)){
				HX_STACK_LINE(144)
				success = false;
			}
		}
;
	}
	HX_STACK_LINE(147)
	bool tmp2 = success;		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(147)
	return tmp2;
}


HX_DEFINE_DYNAMIC_FUNC2(Server_obj,broadcast,return )

Void Server_obj::close( ){
{
		HX_STACK_FRAME("mphx.server.Server","close",0x4a02d9bd,"mphx.server.Server.close","mphx/server/Server.hx",151,0x7ecb9dcb)
		HX_STACK_THIS(this)
		HX_STACK_LINE(152)
		::sys::net::Socket tmp = this->listener;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(152)
		tmp->close();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Server_obj,close,(void))

bool Server_obj::set_blocking( bool value){
	HX_STACK_FRAME("mphx.server.Server","set_blocking",0x3c7bb5cd,"mphx.server.Server.set_blocking","mphx/server/Server.hx",156,0x7ecb9dcb)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(157)
	bool tmp = this->blocking;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(157)
	bool tmp1 = value;		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(157)
	bool tmp2 = (tmp == tmp1);		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(157)
	if ((tmp2)){
		HX_STACK_LINE(157)
		bool tmp3 = value;		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(157)
		return tmp3;
	}
	HX_STACK_LINE(158)
	::sys::net::Socket tmp3 = this->listener;		HX_STACK_VAR(tmp3,"tmp3");
	HX_STACK_LINE(158)
	bool tmp4 = (tmp3 != null());		HX_STACK_VAR(tmp4,"tmp4");
	HX_STACK_LINE(158)
	if ((tmp4)){
		HX_STACK_LINE(158)
		::sys::net::Socket tmp5 = this->listener;		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(158)
		bool tmp6 = value;		HX_STACK_VAR(tmp6,"tmp6");
		HX_STACK_LINE(158)
		tmp5->setBlocking(tmp6);
	}
	HX_STACK_LINE(159)
	bool tmp5 = this->blocking = value;		HX_STACK_VAR(tmp5,"tmp5");
	HX_STACK_LINE(159)
	return tmp5;
}


HX_DEFINE_DYNAMIC_FUNC1(Server_obj,set_blocking,return )


Server_obj::Server_obj()
{
}

void Server_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Server);
	HX_MARK_MEMBER_NAME(host,"host");
	HX_MARK_MEMBER_NAME(port,"port");
	HX_MARK_MEMBER_NAME(blocking,"blocking");
	HX_MARK_MEMBER_NAME(events,"events");
	HX_MARK_MEMBER_NAME(readSockets,"readSockets");
	HX_MARK_MEMBER_NAME(clients,"clients");
	HX_MARK_MEMBER_NAME(listener,"listener");
	HX_MARK_MEMBER_NAME(buffer,"buffer");
	HX_MARK_END_CLASS();
}

void Server_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(host,"host");
	HX_VISIT_MEMBER_NAME(port,"port");
	HX_VISIT_MEMBER_NAME(blocking,"blocking");
	HX_VISIT_MEMBER_NAME(events,"events");
	HX_VISIT_MEMBER_NAME(readSockets,"readSockets");
	HX_VISIT_MEMBER_NAME(clients,"clients");
	HX_VISIT_MEMBER_NAME(listener,"listener");
	HX_VISIT_MEMBER_NAME(buffer,"buffer");
}

Dynamic Server_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"host") ) { return host; }
		if (HX_FIELD_EQ(inName,"port") ) { return port; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"start") ) { return start_dyn(); }
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"events") ) { return events; }
		if (HX_FIELD_EQ(inName,"listen") ) { return listen_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"buffer") ) { return buffer; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"clients") ) { return clients; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"blocking") ) { return blocking; }
		if (HX_FIELD_EQ(inName,"listener") ) { return listener; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"broadcast") ) { return broadcast_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"readSockets") ) { return readSockets; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"set_blocking") ) { return set_blocking_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Server_obj::__SetField(const ::String &inName,const Dynamic &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"host") ) { host=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"port") ) { port=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"events") ) { events=inValue.Cast< ::mphx::core::EventManager >(); return inValue; }
		if (HX_FIELD_EQ(inName,"buffer") ) { buffer=inValue.Cast< ::haxe::io::Bytes >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"clients") ) { clients=inValue.Cast< ::haxe::ds::ObjectMap >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"blocking") ) { if (inCallProp == hx::paccAlways) return set_blocking(inValue);blocking=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"listener") ) { listener=inValue.Cast< ::sys::net::Socket >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"readSockets") ) { readSockets=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool Server_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,hx::PropertyAccess inCallProp)
{
	return false;
}

void Server_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("host","\x68","\xcf","\x12","\x45"));
	outFields->push(HX_HCSTRING("port","\x81","\x83","\x5c","\x4a"));
	outFields->push(HX_HCSTRING("blocking","\xb5","\x25","\xb0","\x19"));
	outFields->push(HX_HCSTRING("events","\x19","\x4f","\x6a","\x96"));
	outFields->push(HX_HCSTRING("readSockets","\xaa","\x44","\x5f","\xaa"));
	outFields->push(HX_HCSTRING("clients","\xc8","\x37","\x81","\xfb"));
	outFields->push(HX_HCSTRING("listener","\x74","\x00","\x32","\x38"));
	outFields->push(HX_HCSTRING("buffer","\x00","\xbd","\x94","\xd0"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(Server_obj,host),HX_HCSTRING("host","\x68","\xcf","\x12","\x45")},
	{hx::fsInt,(int)offsetof(Server_obj,port),HX_HCSTRING("port","\x81","\x83","\x5c","\x4a")},
	{hx::fsBool,(int)offsetof(Server_obj,blocking),HX_HCSTRING("blocking","\xb5","\x25","\xb0","\x19")},
	{hx::fsObject /*::mphx::core::EventManager*/ ,(int)offsetof(Server_obj,events),HX_HCSTRING("events","\x19","\x4f","\x6a","\x96")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Server_obj,readSockets),HX_HCSTRING("readSockets","\xaa","\x44","\x5f","\xaa")},
	{hx::fsObject /*::haxe::ds::ObjectMap*/ ,(int)offsetof(Server_obj,clients),HX_HCSTRING("clients","\xc8","\x37","\x81","\xfb")},
	{hx::fsObject /*::sys::net::Socket*/ ,(int)offsetof(Server_obj,listener),HX_HCSTRING("listener","\x74","\x00","\x32","\x38")},
	{hx::fsObject /*::haxe::io::Bytes*/ ,(int)offsetof(Server_obj,buffer),HX_HCSTRING("buffer","\x00","\xbd","\x94","\xd0")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("host","\x68","\xcf","\x12","\x45"),
	HX_HCSTRING("port","\x81","\x83","\x5c","\x4a"),
	HX_HCSTRING("blocking","\xb5","\x25","\xb0","\x19"),
	HX_HCSTRING("events","\x19","\x4f","\x6a","\x96"),
	HX_HCSTRING("listen","\x47","\xc8","\xf9","\xef"),
	HX_HCSTRING("start","\x62","\x74","\x0b","\x84"),
	HX_HCSTRING("update","\x09","\x86","\x05","\x87"),
	HX_HCSTRING("broadcast","\x01","\xa3","\x19","\xdf"),
	HX_HCSTRING("close","\xb8","\x17","\x63","\x48"),
	HX_HCSTRING("set_blocking","\x32","\xfd","\xc2","\xe3"),
	HX_HCSTRING("readSockets","\xaa","\x44","\x5f","\xaa"),
	HX_HCSTRING("clients","\xc8","\x37","\x81","\xfb"),
	HX_HCSTRING("listener","\x74","\x00","\x32","\x38"),
	HX_HCSTRING("buffer","\x00","\xbd","\x94","\xd0"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Server_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Server_obj::__mClass,"__mClass");
};

#endif

hx::Class Server_obj::__mClass;

void Server_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("mphx.server.Server","\xb3","\x20","\x9b","\xf4");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &Server_obj::__SetStatic;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< Server_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = sStaticStorageInfo;
#endif
	hx::RegisterClass(__mClass->mName, __mClass);
}

} // end namespace mphx
} // end namespace server

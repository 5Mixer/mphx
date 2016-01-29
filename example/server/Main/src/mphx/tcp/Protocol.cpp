#include <hxcpp.h>

#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_format_JsonParser
#include <haxe/format/JsonParser.h>
#endif
#ifndef INCLUDED_haxe_format_JsonPrinter
#include <haxe/format/JsonPrinter.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_mphx_core_EventManager
#include <mphx/core/EventManager.h>
#endif
#ifndef INCLUDED_mphx_tcp_Connection
#include <mphx/tcp/Connection.h>
#endif
#ifndef INCLUDED_mphx_tcp_Protocol
#include <mphx/tcp/Protocol.h>
#endif
namespace mphx{
namespace tcp{

Void Protocol_obj::__construct(::mphx::core::EventManager _events)
{
HX_STACK_FRAME("mphx.tcp.Protocol","new",0x2f5e5972,"mphx.tcp.Protocol.new","mphx/tcp/Protocol.hx",10,0xb30cb0fc)
HX_STACK_THIS(this)
HX_STACK_ARG(_events,"_events")
{
	HX_STACK_LINE(10)
	this->events = _events;
}
;
	return null();
}

//Protocol_obj::~Protocol_obj() { }

Dynamic Protocol_obj::__CreateEmpty() { return  new Protocol_obj; }
hx::ObjectPtr< Protocol_obj > Protocol_obj::__new(::mphx::core::EventManager _events)
{  hx::ObjectPtr< Protocol_obj > _result_ = new Protocol_obj();
	_result_->__construct(_events);
	return _result_;}

Dynamic Protocol_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Protocol_obj > _result_ = new Protocol_obj();
	_result_->__construct(inArgs[0]);
	return _result_;}

Void Protocol_obj::onConnect( ::mphx::tcp::Connection cnx){
{
		HX_STACK_FRAME("mphx.tcp.Protocol","onConnect",0xe8c4971d,"mphx.tcp.Protocol.onConnect","mphx/tcp/Protocol.hx",13,0xb30cb0fc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cnx,"cnx")
		HX_STACK_LINE(13)
		this->cnx = cnx;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Protocol_obj,onConnect,(void))

Void Protocol_obj::onAccept( ::mphx::tcp::Connection cnx){
{
		HX_STACK_FRAME("mphx.tcp.Protocol","onAccept",0x0e44df35,"mphx.tcp.Protocol.onAccept","mphx/tcp/Protocol.hx",14,0xb30cb0fc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cnx,"cnx")
		HX_STACK_LINE(14)
		this->cnx = cnx;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Protocol_obj,onAccept,(void))

Void Protocol_obj::loseConnection( ::String reason){
{
		HX_STACK_FRAME("mphx.tcp.Protocol","loseConnection",0x366d9681,"mphx.tcp.Protocol.loseConnection","mphx/tcp/Protocol.hx",16,0xb30cb0fc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(reason,"reason")
		HX_STACK_LINE(16)
		this->cnx = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Protocol_obj,loseConnection,(void))

bool Protocol_obj::isConnected( ){
	HX_STACK_FRAME("mphx.tcp.Protocol","isConnected",0xd0ac8491,"mphx.tcp.Protocol.isConnected","mphx/tcp/Protocol.hx",21,0xb30cb0fc)
	HX_STACK_THIS(this)
	HX_STACK_LINE(21)
	::mphx::tcp::Connection tmp = this->cnx;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(21)
	bool tmp1 = (tmp != null());		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(21)
	bool tmp2;		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(21)
	if ((tmp1)){
		HX_STACK_LINE(21)
		::mphx::tcp::Connection tmp3 = this->cnx;		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(21)
		::mphx::tcp::Connection tmp4 = tmp3;		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(21)
		tmp2 = tmp4->isOpen();
	}
	else{
		HX_STACK_LINE(21)
		tmp2 = false;
	}
	HX_STACK_LINE(21)
	return tmp2;
}


HX_DEFINE_DYNAMIC_FUNC0(Protocol_obj,isConnected,return )

bool Protocol_obj::send( ::String event,Dynamic data){
	HX_STACK_FRAME("mphx.tcp.Protocol","send",0x467df3f6,"mphx.tcp.Protocol.send","mphx/tcp/Protocol.hx",24,0xb30cb0fc)
	HX_STACK_THIS(this)
	HX_STACK_ARG(event,"event")
	HX_STACK_ARG(data,"data")
	HX_STACK_LINE(25)
	::String tmp = (HX_HCSTRING("Sending event: ","\x9a","\x27","\xb7","\x4a") + event);		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(25)
	Dynamic tmp1 = hx::SourceInfo(HX_HCSTRING("Protocol.hx","\x46","\x0b","\x57","\x16"),25,HX_HCSTRING("mphx.tcp.Protocol","\x80","\x78","\xbc","\xb9"),HX_HCSTRING("send","\x48","\x8d","\x50","\x4c"));		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(25)
	::haxe::Log_obj::trace(tmp,tmp1);
	struct _Function_1_1{
		inline static Dynamic Block( ::String &event,Dynamic &data){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","mphx/tcp/Protocol.hx",26,0xb30cb0fc)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_HCSTRING("t","\x74","\x00","\x00","\x00") , event,false);
				__result->Add(HX_HCSTRING("data","\x2a","\x56","\x63","\x42") , data,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(26)
	Dynamic tmp2 = _Function_1_1::Block(event,data);		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(26)
	Dynamic object = tmp2;		HX_STACK_VAR(object,"object");
	HX_STACK_LINE(30)
	Dynamic tmp3 = object;		HX_STACK_VAR(tmp3,"tmp3");
	HX_STACK_LINE(30)
	::String tmp4 = ::haxe::format::JsonPrinter_obj::print(tmp3,null(),null());		HX_STACK_VAR(tmp4,"tmp4");
	HX_STACK_LINE(30)
	::String serialiseObject = tmp4;		HX_STACK_VAR(serialiseObject,"serialiseObject");
	HX_STACK_LINE(32)
	::mphx::tcp::Connection tmp5 = this->cnx;		HX_STACK_VAR(tmp5,"tmp5");
	HX_STACK_LINE(32)
	::String tmp6 = (serialiseObject + HX_HCSTRING("\r\n","\x5d","\x0b","\x00","\x00"));		HX_STACK_VAR(tmp6,"tmp6");
	HX_STACK_LINE(32)
	::haxe::io::Bytes tmp7 = ::haxe::io::Bytes_obj::ofString(tmp6);		HX_STACK_VAR(tmp7,"tmp7");
	HX_STACK_LINE(32)
	bool tmp8 = tmp5->writeBytes(tmp7);		HX_STACK_VAR(tmp8,"tmp8");
	HX_STACK_LINE(32)
	return tmp8;
}


HX_DEFINE_DYNAMIC_FUNC2(Protocol_obj,send,return )

Void Protocol_obj::dataReceived( ::haxe::io::Input input){
{
		HX_STACK_FRAME("mphx.tcp.Protocol","dataReceived",0x4e0c5619,"mphx.tcp.Protocol.dataReceived","mphx/tcp/Protocol.hx",35,0xb30cb0fc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(input,"input")
		HX_STACK_LINE(37)
		::String tmp = input->readLine();		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(37)
		::String line = tmp;		HX_STACK_VAR(line,"line");
		HX_STACK_LINE(39)
		::haxe::format::JsonParser tmp1 = ::haxe::format::JsonParser_obj::__new(line);		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(39)
		Dynamic tmp2 = tmp1->parseRec();		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(39)
		Dynamic msg = tmp2;		HX_STACK_VAR(msg,"msg");
		HX_STACK_LINE(49)
		::mphx::core::EventManager tmp3 = this->events;		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(49)
		::String tmp4 = msg->__Field(HX_HCSTRING("t","\x74","\x00","\x00","\x00"), hx::paccDynamic );		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(49)
		Dynamic tmp5 = msg->__Field(HX_HCSTRING("data","\x2a","\x56","\x63","\x42"), hx::paccDynamic );		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(49)
		tmp3->callEvent(tmp4,tmp5,hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Protocol_obj,dataReceived,(void))


Protocol_obj::Protocol_obj()
{
}

void Protocol_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Protocol);
	HX_MARK_MEMBER_NAME(events,"events");
	HX_MARK_MEMBER_NAME(cnx,"cnx");
	HX_MARK_END_CLASS();
}

void Protocol_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(events,"events");
	HX_VISIT_MEMBER_NAME(cnx,"cnx");
}

Dynamic Protocol_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"cnx") ) { return cnx; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"send") ) { return send_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"events") ) { return events; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"onAccept") ) { return onAccept_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onConnect") ) { return onConnect_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"isConnected") ) { return isConnected_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"dataReceived") ) { return dataReceived_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"loseConnection") ) { return loseConnection_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Protocol_obj::__SetField(const ::String &inName,const Dynamic &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"cnx") ) { cnx=inValue.Cast< ::mphx::tcp::Connection >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"events") ) { events=inValue.Cast< ::mphx::core::EventManager >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool Protocol_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,hx::PropertyAccess inCallProp)
{
	return false;
}

void Protocol_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("events","\x19","\x4f","\x6a","\x96"));
	outFields->push(HX_HCSTRING("cnx","\x6d","\x7f","\x4b","\x00"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::mphx::core::EventManager*/ ,(int)offsetof(Protocol_obj,events),HX_HCSTRING("events","\x19","\x4f","\x6a","\x96")},
	{hx::fsObject /*::mphx::tcp::Connection*/ ,(int)offsetof(Protocol_obj,cnx),HX_HCSTRING("cnx","\x6d","\x7f","\x4b","\x00")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("events","\x19","\x4f","\x6a","\x96"),
	HX_HCSTRING("onConnect","\x8b","\xf4","\x2a","\xed"),
	HX_HCSTRING("onAccept","\x87","\x89","\xb3","\xea"),
	HX_HCSTRING("loseConnection","\x53","\xca","\x17","\xac"),
	HX_HCSTRING("cnx","\x6d","\x7f","\x4b","\x00"),
	HX_HCSTRING("isConnected","\x7f","\x99","\x77","\x81"),
	HX_HCSTRING("send","\x48","\x8d","\x50","\x4c"),
	HX_HCSTRING("dataReceived","\x6b","\x91","\xf3","\x4e"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Protocol_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Protocol_obj::__mClass,"__mClass");
};

#endif

hx::Class Protocol_obj::__mClass;

void Protocol_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("mphx.tcp.Protocol","\x80","\x78","\xbc","\xb9");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &Protocol_obj::__SetStatic;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< Protocol_obj >;
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
} // end namespace tcp

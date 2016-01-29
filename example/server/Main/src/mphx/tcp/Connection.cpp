#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_mphx_tcp_Connection
#include <mphx/tcp/Connection.h>
#endif
#ifndef INCLUDED_sys_net_Socket
#include <sys/net/Socket.h>
#endif
namespace mphx{
namespace tcp{

Void Connection_obj::__construct(::sys::net::Socket socket)
{
HX_STACK_FRAME("mphx.tcp.Connection","new",0x82dcd838,"mphx.tcp.Connection.new","mphx/tcp/Connection.hx",15,0x91ec5876)
HX_STACK_THIS(this)
HX_STACK_ARG(socket,"socket")
{
	HX_STACK_LINE(15)
	this->socket = socket;
}
;
	return null();
}

//Connection_obj::~Connection_obj() { }

Dynamic Connection_obj::__CreateEmpty() { return  new Connection_obj; }
hx::ObjectPtr< Connection_obj > Connection_obj::__new(::sys::net::Socket socket)
{  hx::ObjectPtr< Connection_obj > _result_ = new Connection_obj();
	_result_->__construct(socket);
	return _result_;}

Dynamic Connection_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Connection_obj > _result_ = new Connection_obj();
	_result_->__construct(inArgs[0]);
	return _result_;}

bool Connection_obj::isOpen( ){
	HX_STACK_FRAME("mphx.tcp.Connection","isOpen",0x8f7637fc,"mphx.tcp.Connection.isOpen","mphx/tcp/Connection.hx",19,0x91ec5876)
	HX_STACK_THIS(this)
	HX_STACK_LINE(20)
	::sys::net::Socket tmp = this->socket;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(20)
	bool tmp1 = (tmp != null());		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(20)
	return tmp1;
}


HX_DEFINE_DYNAMIC_FUNC0(Connection_obj,isOpen,return )

bool Connection_obj::writeBytes( ::haxe::io::Bytes bytes){
	HX_STACK_FRAME("mphx.tcp.Connection","writeBytes",0xc6a02634,"mphx.tcp.Connection.writeBytes","mphx/tcp/Connection.hx",24,0x91ec5876)
	HX_STACK_THIS(this)
	HX_STACK_ARG(bytes,"bytes")
	HX_STACK_LINE(25)
	try
	{
	HX_STACK_CATCHABLE(Dynamic, 0);
	{
		HX_STACK_LINE(35)
		::sys::net::Socket tmp = this->socket;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(35)
		::haxe::io::Bytes tmp1 = bytes;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(35)
		int tmp2 = bytes->length;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(35)
		tmp->output->writeBytes(tmp1,(int)0,tmp2);
	}
	}
	catch(Dynamic __e){
		{
			HX_STACK_BEGIN_CATCH
			Dynamic e = __e;{
				HX_STACK_LINE(41)
				Dynamic tmp = e;		HX_STACK_VAR(tmp,"tmp");
				HX_STACK_LINE(41)
				::String tmp1 = ::Std_obj::string(tmp);		HX_STACK_VAR(tmp1,"tmp1");
				HX_STACK_LINE(41)
				::String tmp2 = (HX_HCSTRING("Error writing to socket: ","\xa2","\xb1","\x04","\x9e") + tmp1);		HX_STACK_VAR(tmp2,"tmp2");
				HX_STACK_LINE(41)
				Dynamic tmp3 = hx::SourceInfo(HX_HCSTRING("Connection.hx","\x40","\x59","\x39","\x20"),41,HX_HCSTRING("mphx.tcp.Connection","\x46","\x9c","\x96","\x90"),HX_HCSTRING("writeBytes","\x0c","\x03","\x5a","\x52"));		HX_STACK_VAR(tmp3,"tmp3");
				HX_STACK_LINE(41)
				::haxe::Log_obj::trace(tmp2,tmp3);
				HX_STACK_LINE(43)
				return false;
			}
		}
	}
	HX_STACK_LINE(45)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(Connection_obj,writeBytes,return )

Void Connection_obj::close( ){
{
		HX_STACK_FRAME("mphx.tcp.Connection","close",0x451fc590,"mphx.tcp.Connection.close","mphx/tcp/Connection.hx",49,0x91ec5876)
		HX_STACK_THIS(this)
		HX_STACK_LINE(50)
		::sys::net::Socket tmp = this->socket;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(50)
		tmp->close();
		HX_STACK_LINE(51)
		this->socket = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Connection_obj,close,(void))


Connection_obj::Connection_obj()
{
}

void Connection_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Connection);
	HX_MARK_MEMBER_NAME(socket,"socket");
	HX_MARK_END_CLASS();
}

void Connection_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(socket,"socket");
}

Dynamic Connection_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"isOpen") ) { return isOpen_dyn(); }
		if (HX_FIELD_EQ(inName,"socket") ) { return socket; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"writeBytes") ) { return writeBytes_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Connection_obj::__SetField(const ::String &inName,const Dynamic &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"socket") ) { socket=inValue.Cast< ::sys::net::Socket >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool Connection_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,hx::PropertyAccess inCallProp)
{
	return false;
}

void Connection_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("socket","\xb3","\x8b","\x46","\x26"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::sys::net::Socket*/ ,(int)offsetof(Connection_obj,socket),HX_HCSTRING("socket","\xb3","\x8b","\x46","\x26")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("isOpen","\xd4","\xc8","\x1a","\x67"),
	HX_HCSTRING("writeBytes","\x0c","\x03","\x5a","\x52"),
	HX_HCSTRING("close","\xb8","\x17","\x63","\x48"),
	HX_HCSTRING("socket","\xb3","\x8b","\x46","\x26"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Connection_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Connection_obj::__mClass,"__mClass");
};

#endif

hx::Class Connection_obj::__mClass;

void Connection_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("mphx.tcp.Connection","\x46","\x9c","\x96","\x90");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &Connection_obj::__SetStatic;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< Connection_obj >;
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

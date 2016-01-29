#include <hxcpp.h>

#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_sys_net_Host
#include <sys/net/Host.h>
#endif
#ifndef INCLUDED_sys_net_Socket
#include <sys/net/Socket.h>
#endif
#ifndef INCLUDED_sys_net__Socket_SocketInput
#include <sys/net/_Socket/SocketInput.h>
#endif
#ifndef INCLUDED_sys_net__Socket_SocketOutput
#include <sys/net/_Socket/SocketOutput.h>
#endif
namespace sys{
namespace net{

Void Socket_obj::__construct()
{
HX_STACK_FRAME("sys.net.Socket","new",0x202a8cf7,"sys.net.Socket.new","C:\\HaxeToolkit\\haxe\\std/cpp/_std/sys/net/Socket.hx",127,0xa375f0f1)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(128)
	Dynamic tmp = ::sys::net::Socket_obj::socket_new(false);		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(128)
	this->__s = tmp;
	HX_STACK_LINE(129)
	Dynamic tmp1 = this->__s;		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(129)
	::sys::net::_Socket::SocketInput tmp2 = ::sys::net::_Socket::SocketInput_obj::__new(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(129)
	this->input = tmp2;
	HX_STACK_LINE(130)
	Dynamic tmp3 = this->__s;		HX_STACK_VAR(tmp3,"tmp3");
	HX_STACK_LINE(130)
	::sys::net::_Socket::SocketOutput tmp4 = ::sys::net::_Socket::SocketOutput_obj::__new(tmp3);		HX_STACK_VAR(tmp4,"tmp4");
	HX_STACK_LINE(130)
	this->output = tmp4;
}
;
	return null();
}

//Socket_obj::~Socket_obj() { }

Dynamic Socket_obj::__CreateEmpty() { return  new Socket_obj; }
hx::ObjectPtr< Socket_obj > Socket_obj::__new()
{  hx::ObjectPtr< Socket_obj > _result_ = new Socket_obj();
	_result_->__construct();
	return _result_;}

Dynamic Socket_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Socket_obj > _result_ = new Socket_obj();
	_result_->__construct();
	return _result_;}

Void Socket_obj::close( ){
{
		HX_STACK_FRAME("sys.net.Socket","close",0x18d3680f,"sys.net.Socket.close","C:\\HaxeToolkit\\haxe\\std/cpp/_std/sys/net/Socket.hx",133,0xa375f0f1)
		HX_STACK_THIS(this)
		HX_STACK_LINE(134)
		Dynamic tmp = this->__s;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(134)
		::sys::net::Socket_obj::socket_close(tmp);
		HX_STACK_LINE(135)
		{
			HX_STACK_LINE(136)
			::haxe::io::Input tmp1 = this->input;		HX_STACK_VAR(tmp1,"tmp1");
			HX_STACK_LINE(136)
			::sys::net::_Socket::SocketInput input = ((::sys::net::_Socket::SocketInput)(tmp1));		HX_STACK_VAR(input,"input");
			HX_STACK_LINE(137)
			::haxe::io::Output tmp2 = this->output;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(137)
			::sys::net::_Socket::SocketOutput output = ((::sys::net::_Socket::SocketOutput)(tmp2));		HX_STACK_VAR(output,"output");
			HX_STACK_LINE(138)
			input->__s = null();
			HX_STACK_LINE(139)
			output->__s = null();
		}
		HX_STACK_LINE(141)
		::haxe::io::Input tmp1 = this->input;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(141)
		tmp1->close();
		HX_STACK_LINE(142)
		::haxe::io::Output tmp2 = this->output;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(142)
		tmp2->close();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,close,(void))

Void Socket_obj::listen( int connections){
{
		HX_STACK_FRAME("sys.net.Socket","listen",0x81cfc410,"sys.net.Socket.listen","C:\\HaxeToolkit\\haxe\\std/cpp/_std/sys/net/Socket.hx",166,0xa375f0f1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(connections,"connections")
		HX_STACK_LINE(167)
		Dynamic tmp = this->__s;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(167)
		int tmp1 = connections;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(167)
		::sys::net::Socket_obj::socket_listen(tmp,tmp1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,listen,(void))

Void Socket_obj::bind( ::sys::net::Host host,int port){
{
		HX_STACK_FRAME("sys.net.Socket","bind",0xfd253d46,"sys.net.Socket.bind","C:\\HaxeToolkit\\haxe\\std/cpp/_std/sys/net/Socket.hx",174,0xa375f0f1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(host,"host")
		HX_STACK_ARG(port,"port")
		HX_STACK_LINE(175)
		Dynamic tmp = this->__s;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(175)
		int tmp1 = host->ip;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(175)
		int tmp2 = port;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(175)
		::sys::net::Socket_obj::socket_bind(tmp,tmp1,tmp2);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Socket_obj,bind,(void))

::sys::net::Socket Socket_obj::accept( ){
	HX_STACK_FRAME("sys.net.Socket","accept",0x9cdc8ed1,"sys.net.Socket.accept","C:\\HaxeToolkit\\haxe\\std/cpp/_std/sys/net/Socket.hx",178,0xa375f0f1)
	HX_STACK_THIS(this)
	HX_STACK_LINE(179)
	Dynamic tmp = this->__s;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(179)
	Dynamic tmp1 = ::sys::net::Socket_obj::socket_accept(tmp);		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(179)
	Dynamic c = tmp1;		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(180)
	::sys::net::Socket tmp2 = ::Type_obj::createEmptyInstance(hx::ClassOf< ::sys::net::Socket >());		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(180)
	::sys::net::Socket s = tmp2;		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(181)
	s->__s = c;
	HX_STACK_LINE(182)
	::sys::net::_Socket::SocketInput tmp3 = ::sys::net::_Socket::SocketInput_obj::__new(c);		HX_STACK_VAR(tmp3,"tmp3");
	HX_STACK_LINE(182)
	s->input = tmp3;
	HX_STACK_LINE(183)
	::sys::net::_Socket::SocketOutput tmp4 = ::sys::net::_Socket::SocketOutput_obj::__new(c);		HX_STACK_VAR(tmp4,"tmp4");
	HX_STACK_LINE(183)
	s->output = tmp4;
	HX_STACK_LINE(184)
	::sys::net::Socket tmp5 = s;		HX_STACK_VAR(tmp5,"tmp5");
	HX_STACK_LINE(184)
	return tmp5;
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,accept,return )

Void Socket_obj::setBlocking( bool b){
{
		HX_STACK_FRAME("sys.net.Socket","setBlocking",0xe5689b0e,"sys.net.Socket.setBlocking","C:\\HaxeToolkit\\haxe\\std/cpp/_std/sys/net/Socket.hx",209,0xa375f0f1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(b,"b")
		HX_STACK_LINE(210)
		Dynamic tmp = this->__s;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(210)
		bool tmp1 = b;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(210)
		::sys::net::Socket_obj::socket_set_blocking(tmp,tmp1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,setBlocking,(void))

Dynamic Socket_obj::select( Array< ::Dynamic > read,Array< ::Dynamic > write,Array< ::Dynamic > others,Dynamic timeout){
	HX_STACK_FRAME("sys.net.Socket","select",0xfc0916c5,"sys.net.Socket.select","C:\\HaxeToolkit\\haxe\\std/cpp/_std/sys/net/Socket.hx",217,0xa375f0f1)
	HX_STACK_ARG(read,"read")
	HX_STACK_ARG(write,"write")
	HX_STACK_ARG(others,"others")
	HX_STACK_ARG(timeout,"timeout")
	HX_STACK_LINE(218)
	Dynamic tmp = timeout;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(218)
	Array< ::Dynamic > neko_array = ::sys::net::Socket_obj::socket_select(read,write,others,tmp);		HX_STACK_VAR(neko_array,"neko_array");
	HX_STACK_LINE(219)
	bool tmp1 = (neko_array == null());		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(219)
	if ((tmp1)){
		HX_STACK_LINE(220)
		HX_STACK_DO_THROW(HX_HCSTRING("Select error","\xc4","\x23","\x4b","\xb6"));
	}
	struct _Function_1_1{
		inline static Dynamic Block( Array< ::Dynamic > &neko_array){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","C:\\HaxeToolkit\\haxe\\std/cpp/_std/sys/net/Socket.hx",221,0xa375f0f1)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_HCSTRING("read","\x56","\x4b","\xa7","\x4b") , neko_array->__get((int)0).StaticCast< Array< ::Dynamic > >(),false);
				__result->Add(HX_HCSTRING("write","\xdf","\x6c","\x59","\xd0") , neko_array->__get((int)1).StaticCast< Array< ::Dynamic > >(),false);
				__result->Add(HX_HCSTRING("others","\xa3","\x8f","\x23","\x71") , neko_array->__get((int)2).StaticCast< Array< ::Dynamic > >(),false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(221)
	Dynamic tmp2 = _Function_1_1::Block(neko_array);		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(221)
	return tmp2;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Socket_obj,select,return )

Dynamic Socket_obj::socket_new;

Dynamic Socket_obj::socket_close;

Dynamic Socket_obj::socket_listen;

Dynamic Socket_obj::socket_select;

Dynamic Socket_obj::socket_bind;

Dynamic Socket_obj::socket_accept;

Dynamic Socket_obj::socket_set_blocking;


Socket_obj::Socket_obj()
{
}

void Socket_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Socket);
	HX_MARK_MEMBER_NAME(__s,"__s");
	HX_MARK_MEMBER_NAME(input,"input");
	HX_MARK_MEMBER_NAME(output,"output");
	HX_MARK_MEMBER_NAME(custom,"custom");
	HX_MARK_END_CLASS();
}

void Socket_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__s,"__s");
	HX_VISIT_MEMBER_NAME(input,"input");
	HX_VISIT_MEMBER_NAME(output,"output");
	HX_VISIT_MEMBER_NAME(custom,"custom");
}

Dynamic Socket_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__s") ) { return __s; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"bind") ) { return bind_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"input") ) { return input; }
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"output") ) { return output; }
		if (HX_FIELD_EQ(inName,"custom") ) { return custom; }
		if (HX_FIELD_EQ(inName,"listen") ) { return listen_dyn(); }
		if (HX_FIELD_EQ(inName,"accept") ) { return accept_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setBlocking") ) { return setBlocking_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

bool Socket_obj::__GetStatic(const ::String &inName, Dynamic &outValue, hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"select") ) { outValue = select_dyn(); return true;  }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"socket_new") ) { outValue = socket_new; return true;  }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"socket_bind") ) { outValue = socket_bind; return true;  }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"socket_close") ) { outValue = socket_close; return true;  }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"socket_listen") ) { outValue = socket_listen; return true;  }
		if (HX_FIELD_EQ(inName,"socket_select") ) { outValue = socket_select; return true;  }
		if (HX_FIELD_EQ(inName,"socket_accept") ) { outValue = socket_accept; return true;  }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"socket_set_blocking") ) { outValue = socket_set_blocking; return true;  }
	}
	return false;
}

Dynamic Socket_obj::__SetField(const ::String &inName,const Dynamic &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__s") ) { __s=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"input") ) { input=inValue.Cast< ::haxe::io::Input >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"output") ) { output=inValue.Cast< ::haxe::io::Output >(); return inValue; }
		if (HX_FIELD_EQ(inName,"custom") ) { custom=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool Socket_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"socket_new") ) { socket_new=ioValue.Cast< Dynamic >(); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"socket_bind") ) { socket_bind=ioValue.Cast< Dynamic >(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"socket_close") ) { socket_close=ioValue.Cast< Dynamic >(); return true; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"socket_listen") ) { socket_listen=ioValue.Cast< Dynamic >(); return true; }
		if (HX_FIELD_EQ(inName,"socket_select") ) { socket_select=ioValue.Cast< Dynamic >(); return true; }
		if (HX_FIELD_EQ(inName,"socket_accept") ) { socket_accept=ioValue.Cast< Dynamic >(); return true; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"socket_set_blocking") ) { socket_set_blocking=ioValue.Cast< Dynamic >(); return true; }
	}
	return false;
}

void Socket_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("__s","\x53","\x69","\x48","\x00"));
	outFields->push(HX_HCSTRING("input","\x0a","\xc4","\x1d","\xbe"));
	outFields->push(HX_HCSTRING("output","\x01","\x0f","\x81","\x0c"));
	outFields->push(HX_HCSTRING("custom","\xb1","\x87","\x92","\x3f"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Socket_obj,__s),HX_HCSTRING("__s","\x53","\x69","\x48","\x00")},
	{hx::fsObject /*::haxe::io::Input*/ ,(int)offsetof(Socket_obj,input),HX_HCSTRING("input","\x0a","\xc4","\x1d","\xbe")},
	{hx::fsObject /*::haxe::io::Output*/ ,(int)offsetof(Socket_obj,output),HX_HCSTRING("output","\x01","\x0f","\x81","\x0c")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Socket_obj,custom),HX_HCSTRING("custom","\xb1","\x87","\x92","\x3f")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo sStaticStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(void *) &Socket_obj::socket_new,HX_HCSTRING("socket_new","\x94","\xf6","\xc0","\xc3")},
	{hx::fsObject /*Dynamic*/ ,(void *) &Socket_obj::socket_close,HX_HCSTRING("socket_close","\xec","\x32","\x0d","\x9e")},
	{hx::fsObject /*Dynamic*/ ,(void *) &Socket_obj::socket_listen,HX_HCSTRING("socket_listen","\x93","\x7a","\x27","\x8f")},
	{hx::fsObject /*Dynamic*/ ,(void *) &Socket_obj::socket_select,HX_HCSTRING("socket_select","\x48","\xcd","\x60","\x09")},
	{hx::fsObject /*Dynamic*/ ,(void *) &Socket_obj::socket_bind,HX_HCSTRING("socket_bind","\x09","\x3d","\x2b","\x7d")},
	{hx::fsObject /*Dynamic*/ ,(void *) &Socket_obj::socket_accept,HX_HCSTRING("socket_accept","\x54","\x45","\x34","\xaa")},
	{hx::fsObject /*Dynamic*/ ,(void *) &Socket_obj::socket_set_blocking,HX_HCSTRING("socket_set_blocking","\x7e","\x70","\xa1","\xe7")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("__s","\x53","\x69","\x48","\x00"),
	HX_HCSTRING("input","\x0a","\xc4","\x1d","\xbe"),
	HX_HCSTRING("output","\x01","\x0f","\x81","\x0c"),
	HX_HCSTRING("custom","\xb1","\x87","\x92","\x3f"),
	HX_HCSTRING("close","\xb8","\x17","\x63","\x48"),
	HX_HCSTRING("listen","\x47","\xc8","\xf9","\xef"),
	HX_HCSTRING("bind","\xbd","\xf5","\x16","\x41"),
	HX_HCSTRING("accept","\x08","\x93","\x06","\x0b"),
	HX_HCSTRING("setBlocking","\x77","\xef","\x10","\x4a"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Socket_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_new,"socket_new");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_close,"socket_close");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_listen,"socket_listen");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_select,"socket_select");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_bind,"socket_bind");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_accept,"socket_accept");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_set_blocking,"socket_set_blocking");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Socket_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_new,"socket_new");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_close,"socket_close");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_listen,"socket_listen");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_select,"socket_select");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_bind,"socket_bind");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_accept,"socket_accept");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_set_blocking,"socket_set_blocking");
};

#endif

hx::Class Socket_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("select","\xfc","\x1a","\x33","\x6a"),
	HX_HCSTRING("socket_new","\x94","\xf6","\xc0","\xc3"),
	HX_HCSTRING("socket_close","\xec","\x32","\x0d","\x9e"),
	HX_HCSTRING("socket_listen","\x93","\x7a","\x27","\x8f"),
	HX_HCSTRING("socket_select","\x48","\xcd","\x60","\x09"),
	HX_HCSTRING("socket_bind","\x09","\x3d","\x2b","\x7d"),
	HX_HCSTRING("socket_accept","\x54","\x45","\x34","\xaa"),
	HX_HCSTRING("socket_set_blocking","\x7e","\x70","\xa1","\xe7"),
	::String(null()) };

void Socket_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("sys.net.Socket","\x85","\x45","\x9d","\xb4");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Socket_obj::__GetStatic;
	__mClass->mSetStaticField = &Socket_obj::__SetStatic;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(sStaticFields);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< Socket_obj >;
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

void Socket_obj::__boot()
{
	socket_new= ::cpp::Lib_obj::load(HX_HCSTRING("std","\xa3","\xa8","\x57","\x00"),HX_HCSTRING("socket_new","\x94","\xf6","\xc0","\xc3"),(int)1);
	socket_close= ::cpp::Lib_obj::load(HX_HCSTRING("std","\xa3","\xa8","\x57","\x00"),HX_HCSTRING("socket_close","\xec","\x32","\x0d","\x9e"),(int)1);
	socket_listen= ::cpp::Lib_obj::load(HX_HCSTRING("std","\xa3","\xa8","\x57","\x00"),HX_HCSTRING("socket_listen","\x93","\x7a","\x27","\x8f"),(int)2);
	socket_select= ::cpp::Lib_obj::load(HX_HCSTRING("std","\xa3","\xa8","\x57","\x00"),HX_HCSTRING("socket_select","\x48","\xcd","\x60","\x09"),(int)4);
	socket_bind= ::cpp::Lib_obj::load(HX_HCSTRING("std","\xa3","\xa8","\x57","\x00"),HX_HCSTRING("socket_bind","\x09","\x3d","\x2b","\x7d"),(int)3);
	socket_accept= ::cpp::Lib_obj::load(HX_HCSTRING("std","\xa3","\xa8","\x57","\x00"),HX_HCSTRING("socket_accept","\x54","\x45","\x34","\xaa"),(int)1);
	socket_set_blocking= ::cpp::Lib_obj::load(HX_HCSTRING("std","\xa3","\xa8","\x57","\x00"),HX_HCSTRING("socket_set_blocking","\x7e","\x70","\xa1","\xe7"),(int)2);
}

} // end namespace sys
} // end namespace net

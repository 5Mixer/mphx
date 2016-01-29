#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
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
#ifndef INCLUDED_sys_net__Socket_SocketInput
#include <sys/net/_Socket/SocketInput.h>
#endif
namespace sys{
namespace net{
namespace _Socket{

Void SocketInput_obj::__construct(Dynamic s)
{
HX_STACK_FRAME("sys.net._Socket.SocketInput","new",0x5fe92abb,"sys.net._Socket.SocketInput.new","C:\\HaxeToolkit\\haxe\\std/cpp/_std/sys/net/Socket.hx",31,0xa375f0f1)
HX_STACK_THIS(this)
HX_STACK_ARG(s,"s")
{
	HX_STACK_LINE(31)
	this->__s = s;
}
;
	return null();
}

//SocketInput_obj::~SocketInput_obj() { }

Dynamic SocketInput_obj::__CreateEmpty() { return  new SocketInput_obj; }
hx::ObjectPtr< SocketInput_obj > SocketInput_obj::__new(Dynamic s)
{  hx::ObjectPtr< SocketInput_obj > _result_ = new SocketInput_obj();
	_result_->__construct(s);
	return _result_;}

Dynamic SocketInput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SocketInput_obj > _result_ = new SocketInput_obj();
	_result_->__construct(inArgs[0]);
	return _result_;}

int SocketInput_obj::readByte( ){
	HX_STACK_FRAME("sys.net._Socket.SocketInput","readByte",0xee593543,"sys.net._Socket.SocketInput.readByte","C:\\HaxeToolkit\\haxe\\std/cpp/_std/sys/net/Socket.hx",34,0xa375f0f1)
	HX_STACK_THIS(this)
	HX_STACK_LINE(35)
	int tmp;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(35)
	try
	{
	HX_STACK_CATCHABLE(Dynamic, 0);
	{
		HX_STACK_LINE(36)
		Dynamic tmp1 = this->__s;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(36)
		tmp = ::sys::net::_Socket::SocketInput_obj::socket_recv_char(tmp1);
	}
	}
	catch(Dynamic __e){
		{
			HX_STACK_BEGIN_CATCH
			Dynamic e = __e;{
				HX_STACK_LINE(38)
				bool tmp1 = (e == HX_HCSTRING("Blocking","\xd5","\xe1","\x61","\xf3"));		HX_STACK_VAR(tmp1,"tmp1");
				HX_STACK_LINE(38)
				if ((tmp1)){
					HX_STACK_LINE(39)
					HX_STACK_DO_THROW(::haxe::io::Error_obj::Blocked);
				}
				else{
					HX_STACK_LINE(40)
					Dynamic tmp2 = this->__s;		HX_STACK_VAR(tmp2,"tmp2");
					HX_STACK_LINE(40)
					bool tmp3 = (tmp2 == null());		HX_STACK_VAR(tmp3,"tmp3");
					HX_STACK_LINE(40)
					if ((tmp3)){
						HX_STACK_LINE(41)
						Dynamic tmp4 = e;		HX_STACK_VAR(tmp4,"tmp4");
						HX_STACK_LINE(41)
						::haxe::io::Error tmp5 = ::haxe::io::Error_obj::Custom(tmp4);		HX_STACK_VAR(tmp5,"tmp5");
						HX_STACK_LINE(41)
						HX_STACK_DO_THROW(tmp5);
					}
					else{
						HX_STACK_LINE(43)
						::haxe::io::Eof tmp4 = ::haxe::io::Eof_obj::__new();		HX_STACK_VAR(tmp4,"tmp4");
						HX_STACK_LINE(43)
						HX_STACK_DO_THROW(tmp4);
					}
				}
			}
		}
	}
	HX_STACK_LINE(35)
	return tmp;
}


Void SocketInput_obj::close( ){
{
		HX_STACK_FRAME("sys.net._Socket.SocketInput","close",0xbbc7fed3,"sys.net._Socket.SocketInput.close","C:\\HaxeToolkit\\haxe\\std/cpp/_std/sys/net/Socket.hx",64,0xa375f0f1)
		HX_STACK_THIS(this)
		HX_STACK_LINE(65)
		this->super::close();
		HX_STACK_LINE(66)
		Dynamic tmp = this->__s;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(66)
		bool tmp1 = (tmp != null());		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(66)
		if ((tmp1)){
			HX_STACK_LINE(66)
			Dynamic tmp2 = this->__s;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(66)
			::sys::net::_Socket::SocketInput_obj::socket_close(tmp2);
		}
	}
return null();
}


Dynamic SocketInput_obj::socket_recv_char;

Dynamic SocketInput_obj::socket_close;


SocketInput_obj::SocketInput_obj()
{
}

void SocketInput_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SocketInput);
	HX_MARK_MEMBER_NAME(__s,"__s");
	HX_MARK_END_CLASS();
}

void SocketInput_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__s,"__s");
}

Dynamic SocketInput_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__s") ) { return __s; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"readByte") ) { return readByte_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

bool SocketInput_obj::__GetStatic(const ::String &inName, Dynamic &outValue, hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"socket_close") ) { outValue = socket_close; return true;  }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"socket_recv_char") ) { outValue = socket_recv_char; return true;  }
	}
	return false;
}

Dynamic SocketInput_obj::__SetField(const ::String &inName,const Dynamic &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__s") ) { __s=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool SocketInput_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"socket_close") ) { socket_close=ioValue.Cast< Dynamic >(); return true; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"socket_recv_char") ) { socket_recv_char=ioValue.Cast< Dynamic >(); return true; }
	}
	return false;
}

void SocketInput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("__s","\x53","\x69","\x48","\x00"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(SocketInput_obj,__s),HX_HCSTRING("__s","\x53","\x69","\x48","\x00")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo sStaticStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(void *) &SocketInput_obj::socket_recv_char,HX_HCSTRING("socket_recv_char","\x03","\x89","\x4b","\xed")},
	{hx::fsObject /*Dynamic*/ ,(void *) &SocketInput_obj::socket_close,HX_HCSTRING("socket_close","\xec","\x32","\x0d","\x9e")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("__s","\x53","\x69","\x48","\x00"),
	HX_HCSTRING("readByte","\x7e","\xf9","\x1a","\x69"),
	HX_HCSTRING("close","\xb8","\x17","\x63","\x48"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SocketInput_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(SocketInput_obj::socket_recv_char,"socket_recv_char");
	HX_MARK_MEMBER_NAME(SocketInput_obj::socket_close,"socket_close");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SocketInput_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(SocketInput_obj::socket_recv_char,"socket_recv_char");
	HX_VISIT_MEMBER_NAME(SocketInput_obj::socket_close,"socket_close");
};

#endif

hx::Class SocketInput_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("socket_recv_char","\x03","\x89","\x4b","\xed"),
	HX_HCSTRING("socket_close","\xec","\x32","\x0d","\x9e"),
	::String(null()) };

void SocketInput_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("sys.net._Socket.SocketInput","\x49","\xb1","\x40","\x2c");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &SocketInput_obj::__GetStatic;
	__mClass->mSetStaticField = &SocketInput_obj::__SetStatic;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(sStaticFields);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< SocketInput_obj >;
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

void SocketInput_obj::__boot()
{
	socket_recv_char= ::cpp::Lib_obj::load(HX_HCSTRING("std","\xa3","\xa8","\x57","\x00"),HX_HCSTRING("socket_recv_char","\x03","\x89","\x4b","\xed"),(int)1);
	socket_close= ::cpp::Lib_obj::load(HX_HCSTRING("std","\xa3","\xa8","\x57","\x00"),HX_HCSTRING("socket_close","\xec","\x32","\x0d","\x9e"),(int)1);
}

} // end namespace sys
} // end namespace net
} // end namespace _Socket

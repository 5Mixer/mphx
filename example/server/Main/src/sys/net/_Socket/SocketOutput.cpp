#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_sys_net__Socket_SocketOutput
#include <sys/net/_Socket/SocketOutput.h>
#endif
namespace sys{
namespace net{
namespace _Socket{

Void SocketOutput_obj::__construct(Dynamic s)
{
HX_STACK_FRAME("sys.net._Socket.SocketOutput","new",0x717472d4,"sys.net._Socket.SocketOutput.new","C:\\HaxeToolkit\\haxe\\std/cpp/_std/sys/net/Socket.hx",80,0xa375f0f1)
HX_STACK_THIS(this)
HX_STACK_ARG(s,"s")
{
	HX_STACK_LINE(80)
	this->__s = s;
}
;
	return null();
}

//SocketOutput_obj::~SocketOutput_obj() { }

Dynamic SocketOutput_obj::__CreateEmpty() { return  new SocketOutput_obj; }
hx::ObjectPtr< SocketOutput_obj > SocketOutput_obj::__new(Dynamic s)
{  hx::ObjectPtr< SocketOutput_obj > _result_ = new SocketOutput_obj();
	_result_->__construct(s);
	return _result_;}

Dynamic SocketOutput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SocketOutput_obj > _result_ = new SocketOutput_obj();
	_result_->__construct(inArgs[0]);
	return _result_;}

Void SocketOutput_obj::writeByte( int c){
{
		HX_STACK_FRAME("sys.net._Socket.SocketOutput","writeByte",0xbfd704fb,"sys.net._Socket.SocketOutput.writeByte","C:\\HaxeToolkit\\haxe\\std/cpp/_std/sys/net/Socket.hx",83,0xa375f0f1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(84)
		Dynamic tmp = this->__s;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(84)
		bool tmp1 = (tmp == null());		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(84)
		if ((tmp1)){
			HX_STACK_LINE(85)
			HX_STACK_DO_THROW(HX_HCSTRING("Invalid handle","\xd1","\x71","\x75","\x85"));
		}
		HX_STACK_LINE(86)
		try
		{
		HX_STACK_CATCHABLE(Dynamic, 0);
		{
			HX_STACK_LINE(87)
			Dynamic tmp2 = this->__s;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(87)
			int tmp3 = c;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(87)
			::sys::net::_Socket::SocketOutput_obj::socket_send_char(tmp2,tmp3);
		}
		}
		catch(Dynamic __e){
			{
				HX_STACK_BEGIN_CATCH
				Dynamic e = __e;{
					HX_STACK_LINE(89)
					bool tmp2 = (e == HX_HCSTRING("Blocking","\xd5","\xe1","\x61","\xf3"));		HX_STACK_VAR(tmp2,"tmp2");
					HX_STACK_LINE(89)
					if ((tmp2)){
						HX_STACK_LINE(90)
						HX_STACK_DO_THROW(::haxe::io::Error_obj::Blocked);
					}
					else{
						HX_STACK_LINE(92)
						Dynamic tmp3 = e;		HX_STACK_VAR(tmp3,"tmp3");
						HX_STACK_LINE(92)
						::haxe::io::Error tmp4 = ::haxe::io::Error_obj::Custom(tmp3);		HX_STACK_VAR(tmp4,"tmp4");
						HX_STACK_LINE(92)
						HX_STACK_DO_THROW(tmp4);
					}
				}
			}
		}
	}
return null();
}


int SocketOutput_obj::writeBytes( ::haxe::io::Bytes buf,int pos,int len){
	HX_STACK_FRAME("sys.net._Socket.SocketOutput","writeBytes",0x1c4d5718,"sys.net._Socket.SocketOutput.writeBytes","C:\\HaxeToolkit\\haxe\\std/cpp/_std/sys/net/Socket.hx",96,0xa375f0f1)
	HX_STACK_THIS(this)
	HX_STACK_ARG(buf,"buf")
	HX_STACK_ARG(pos,"pos")
	HX_STACK_ARG(len,"len")
	HX_STACK_LINE(97)
	int tmp;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(97)
	try
	{
	HX_STACK_CATCHABLE(Dynamic, 0);
	{
		HX_STACK_LINE(98)
		Dynamic tmp1 = this->__s;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(98)
		int tmp2 = pos;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(98)
		int tmp3 = len;		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(98)
		tmp = ::sys::net::_Socket::SocketOutput_obj::socket_send(tmp1,buf->b,tmp2,tmp3);
	}
	}
	catch(Dynamic __e){
		{
			HX_STACK_BEGIN_CATCH
			Dynamic e = __e;{
				HX_STACK_LINE(100)
				bool tmp1 = (e == HX_HCSTRING("Blocking","\xd5","\xe1","\x61","\xf3"));		HX_STACK_VAR(tmp1,"tmp1");
				HX_STACK_LINE(100)
				if ((tmp1)){
					HX_STACK_LINE(101)
					HX_STACK_DO_THROW(::haxe::io::Error_obj::Blocked);
				}
				else{
					HX_STACK_LINE(103)
					Dynamic tmp2 = e;		HX_STACK_VAR(tmp2,"tmp2");
					HX_STACK_LINE(103)
					::haxe::io::Error tmp3 = ::haxe::io::Error_obj::Custom(tmp2);		HX_STACK_VAR(tmp3,"tmp3");
					HX_STACK_LINE(103)
					HX_STACK_DO_THROW(tmp3);
				}
			}
		}
	}
	HX_STACK_LINE(97)
	return tmp;
}


Void SocketOutput_obj::close( ){
{
		HX_STACK_FRAME("sys.net._Socket.SocketOutput","close",0xbcc83f2c,"sys.net._Socket.SocketOutput.close","C:\\HaxeToolkit\\haxe\\std/cpp/_std/sys/net/Socket.hx",107,0xa375f0f1)
		HX_STACK_THIS(this)
		HX_STACK_LINE(108)
		this->super::close();
		HX_STACK_LINE(109)
		Dynamic tmp = this->__s;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(109)
		bool tmp1 = (tmp != null());		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(109)
		if ((tmp1)){
			HX_STACK_LINE(109)
			Dynamic tmp2 = this->__s;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(109)
			::sys::net::_Socket::SocketOutput_obj::socket_close(tmp2);
		}
	}
return null();
}


Dynamic SocketOutput_obj::socket_close;

Dynamic SocketOutput_obj::socket_send_char;

Dynamic SocketOutput_obj::socket_send;


SocketOutput_obj::SocketOutput_obj()
{
}

void SocketOutput_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SocketOutput);
	HX_MARK_MEMBER_NAME(__s,"__s");
	HX_MARK_END_CLASS();
}

void SocketOutput_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__s,"__s");
}

Dynamic SocketOutput_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__s") ) { return __s; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"writeByte") ) { return writeByte_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"writeBytes") ) { return writeBytes_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

bool SocketOutput_obj::__GetStatic(const ::String &inName, Dynamic &outValue, hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"socket_send") ) { outValue = socket_send; return true;  }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"socket_close") ) { outValue = socket_close; return true;  }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"socket_send_char") ) { outValue = socket_send_char; return true;  }
	}
	return false;
}

Dynamic SocketOutput_obj::__SetField(const ::String &inName,const Dynamic &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__s") ) { __s=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool SocketOutput_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"socket_send") ) { socket_send=ioValue.Cast< Dynamic >(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"socket_close") ) { socket_close=ioValue.Cast< Dynamic >(); return true; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"socket_send_char") ) { socket_send_char=ioValue.Cast< Dynamic >(); return true; }
	}
	return false;
}

void SocketOutput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("__s","\x53","\x69","\x48","\x00"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(SocketOutput_obj,__s),HX_HCSTRING("__s","\x53","\x69","\x48","\x00")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo sStaticStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(void *) &SocketOutput_obj::socket_close,HX_HCSTRING("socket_close","\xec","\x32","\x0d","\x9e")},
	{hx::fsObject /*Dynamic*/ ,(void *) &SocketOutput_obj::socket_send_char,HX_HCSTRING("socket_send_char","\xa1","\x8d","\x3c","\x57")},
	{hx::fsObject /*Dynamic*/ ,(void *) &SocketOutput_obj::socket_send,HX_HCSTRING("socket_send","\x94","\xd4","\x64","\x88")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("__s","\x53","\x69","\x48","\x00"),
	HX_HCSTRING("writeByte","\x87","\x13","\xd7","\x49"),
	HX_HCSTRING("writeBytes","\x0c","\x03","\x5a","\x52"),
	HX_HCSTRING("close","\xb8","\x17","\x63","\x48"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SocketOutput_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(SocketOutput_obj::socket_close,"socket_close");
	HX_MARK_MEMBER_NAME(SocketOutput_obj::socket_send_char,"socket_send_char");
	HX_MARK_MEMBER_NAME(SocketOutput_obj::socket_send,"socket_send");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SocketOutput_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(SocketOutput_obj::socket_close,"socket_close");
	HX_VISIT_MEMBER_NAME(SocketOutput_obj::socket_send_char,"socket_send_char");
	HX_VISIT_MEMBER_NAME(SocketOutput_obj::socket_send,"socket_send");
};

#endif

hx::Class SocketOutput_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("socket_close","\xec","\x32","\x0d","\x9e"),
	HX_HCSTRING("socket_send_char","\xa1","\x8d","\x3c","\x57"),
	HX_HCSTRING("socket_send","\x94","\xd4","\x64","\x88"),
	::String(null()) };

void SocketOutput_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("sys.net._Socket.SocketOutput","\xe2","\xb8","\xed","\xfc");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &SocketOutput_obj::__GetStatic;
	__mClass->mSetStaticField = &SocketOutput_obj::__SetStatic;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(sStaticFields);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< SocketOutput_obj >;
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

void SocketOutput_obj::__boot()
{
	socket_close= ::cpp::Lib_obj::load(HX_HCSTRING("std","\xa3","\xa8","\x57","\x00"),HX_HCSTRING("socket_close","\xec","\x32","\x0d","\x9e"),(int)1);
	socket_send_char= ::cpp::Lib_obj::load(HX_HCSTRING("std","\xa3","\xa8","\x57","\x00"),HX_HCSTRING("socket_send_char","\xa1","\x8d","\x3c","\x57"),(int)2);
	socket_send= ::cpp::Lib_obj::load(HX_HCSTRING("std","\xa3","\xa8","\x57","\x00"),HX_HCSTRING("socket_send","\x94","\xd4","\x64","\x88"),(int)4);
}

} // end namespace sys
} // end namespace net
} // end namespace _Socket

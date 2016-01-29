#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_sys_net_Host
#include <sys/net/Host.h>
#endif
namespace sys{
namespace net{

Void Host_obj::__construct(::String name)
{
HX_STACK_FRAME("sys.net.Host","new",0x056496ac,"sys.net.Host.new","C:\\HaxeToolkit\\haxe\\std/cpp/_std/sys/net/Host.hx",29,0xf180fedc)
HX_STACK_THIS(this)
HX_STACK_ARG(name,"name")
{
	HX_STACK_LINE(30)
	::String tmp = name;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(30)
	int tmp1 = ::sys::net::Host_obj::host_resolve(tmp);		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(30)
	this->ip = tmp1;
}
;
	return null();
}

//Host_obj::~Host_obj() { }

Dynamic Host_obj::__CreateEmpty() { return  new Host_obj; }
hx::ObjectPtr< Host_obj > Host_obj::__new(::String name)
{  hx::ObjectPtr< Host_obj > _result_ = new Host_obj();
	_result_->__construct(name);
	return _result_;}

Dynamic Host_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Host_obj > _result_ = new Host_obj();
	_result_->__construct(inArgs[0]);
	return _result_;}

void Host_obj::__init__() {
HX_STACK_FRAME("sys.net.Host","__init__",0xecfcc384,"sys.net.Host.__init__","C:\\HaxeToolkit\\haxe\\std/cpp/_std/sys/net/Host.hx",45,0xf180fedc)
{
	HX_STACK_LINE(46)
	Dynamic tmp = ::cpp::Lib_obj::load(HX_HCSTRING("std","\xa3","\xa8","\x57","\x00"),HX_HCSTRING("socket_init","\x5c","\x82","\xcf","\x81"),(int)0);		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(46)
	tmp();
}
}

::String Host_obj::localhost( ){
	HX_STACK_FRAME("sys.net.Host","localhost",0x3fc4b19f,"sys.net.Host.localhost","C:\\HaxeToolkit\\haxe\\std/cpp/_std/sys/net/Host.hx",41,0xf180fedc)
	HX_STACK_LINE(42)
	::String tmp = ::sys::net::Host_obj::host_local();		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(42)
	::String tmp1 = ::String(tmp);		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(42)
	return tmp1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Host_obj,localhost,return )

Dynamic Host_obj::host_resolve;

Dynamic Host_obj::host_local;


Host_obj::Host_obj()
{
}

Dynamic Host_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ip") ) { return ip; }
	}
	return super::__Field(inName,inCallProp);
}

bool Host_obj::__GetStatic(const ::String &inName, Dynamic &outValue, hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"localhost") ) { outValue = localhost_dyn(); return true;  }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"host_local") ) { outValue = host_local; return true;  }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"host_resolve") ) { outValue = host_resolve; return true;  }
	}
	return false;
}

Dynamic Host_obj::__SetField(const ::String &inName,const Dynamic &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ip") ) { ip=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool Host_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"host_local") ) { host_local=ioValue.Cast< Dynamic >(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"host_resolve") ) { host_resolve=ioValue.Cast< Dynamic >(); return true; }
	}
	return false;
}

void Host_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("ip","\xe7","\x5b","\x00","\x00"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Host_obj,ip),HX_HCSTRING("ip","\xe7","\x5b","\x00","\x00")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo sStaticStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(void *) &Host_obj::host_resolve,HX_HCSTRING("host_resolve","\xd5","\xe3","\x24","\x2e")},
	{hx::fsObject /*Dynamic*/ ,(void *) &Host_obj::host_local,HX_HCSTRING("host_local","\x14","\x5e","\x28","\x93")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("ip","\xe7","\x5b","\x00","\x00"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Host_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Host_obj::host_resolve,"host_resolve");
	HX_MARK_MEMBER_NAME(Host_obj::host_local,"host_local");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Host_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Host_obj::host_resolve,"host_resolve");
	HX_VISIT_MEMBER_NAME(Host_obj::host_local,"host_local");
};

#endif

hx::Class Host_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("localhost","\x53","\x2a","\x7c","\x1c"),
	HX_HCSTRING("host_resolve","\xd5","\xe3","\x24","\x2e"),
	HX_HCSTRING("host_local","\x14","\x5e","\x28","\x93"),
	::String(null()) };

void Host_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("sys.net.Host","\xba","\x10","\x59","\xc4");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Host_obj::__GetStatic;
	__mClass->mSetStaticField = &Host_obj::__SetStatic;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(sStaticFields);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< Host_obj >;
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

void Host_obj::__boot()
{
	host_resolve= ::cpp::Lib_obj::load(HX_HCSTRING("std","\xa3","\xa8","\x57","\x00"),HX_HCSTRING("host_resolve","\xd5","\xe3","\x24","\x2e"),(int)1);
	host_local= ::cpp::Lib_obj::load(HX_HCSTRING("std","\xa3","\xa8","\x57","\x00"),HX_HCSTRING("host_local","\x14","\x5e","\x28","\x93"),(int)0);
}

} // end namespace sys
} // end namespace net

#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_ds_Either
#include <haxe/ds/Either.h>
#endif
#ifndef INCLUDED_mphx_core_EventManager
#include <mphx/core/EventManager.h>
#endif
#ifndef INCLUDED_mphx_server_Server
#include <mphx/server/Server.h>
#endif
#ifndef INCLUDED_mphx_tcp_Protocol
#include <mphx/tcp/Protocol.h>
#endif

Void Main_obj::__construct()
{
HX_STACK_FRAME("Main","new",0x6616a5cb,"Main.new","Main.hx",4,0x087e5c05)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(5)
	::mphx::server::Server tmp = ::mphx::server::Server_obj::__new(HX_HCSTRING("127.0.0.1","\xfd","\xbc","\x5e","\xa1"),(int)8000);		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(5)
	::mphx::server::Server s = tmp;		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(7)
	::haxe::ds::Either tmp1;		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(7)
	{

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,::mphx::server::Server,s)
		int __ArgCount() const { return 2; }
		Void run(Dynamic data,::mphx::tcp::Protocol sender){
			HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","Main.hx",7,0x087e5c05)
			HX_STACK_ARG(data,"data")
			HX_STACK_ARG(sender,"sender")
			{
				HX_STACK_LINE(9)
				::mphx::tcp::Protocol tmp2 = sender;		HX_STACK_VAR(tmp2,"tmp2");
				HX_STACK_LINE(9)
				Dynamic tmp3 = hx::SourceInfo(HX_HCSTRING("Main.hx","\x05","\x5c","\x7e","\x08"),9,HX_HCSTRING("Main","\x59","\x64","\x2f","\x33"),HX_HCSTRING("new","\x60","\xd0","\x53","\x00"));		HX_STACK_VAR(tmp3,"tmp3");
				HX_STACK_LINE(9)
				::haxe::Log_obj::trace(::Reflect_obj::fields(tmp2),tmp3);
				HX_STACK_LINE(10)
				Dynamic tmp4 = hx::SourceInfo(HX_HCSTRING("Main.hx","\x05","\x5c","\x7e","\x08"),10,HX_HCSTRING("Main","\x59","\x64","\x2f","\x33"),HX_HCSTRING("new","\x60","\xd0","\x53","\x00"));		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(10)
				::haxe::Log_obj::trace(HX_HCSTRING("Client said hello","\x30","\x4f","\x25","\x0a"),tmp4);
				HX_STACK_LINE(11)
				s->broadcast(HX_HCSTRING("BROADCAST","\xe1","\x12","\x72","\xda"),null());
				HX_STACK_LINE(12)
				sender->send(HX_HCSTRING("Hey yo! Direct reply is the in thing","\x84","\x7f","\xc4","\x53"),HX_HCSTRING("Hello","\xf2","\xa2","\xee","\xb7"));
			}
			return null();
		}
		HX_END_LOCAL_FUNC2((void))

		HX_STACK_LINE(7)
		::haxe::ds::Either tmp2 = ::haxe::ds::Either_obj::Left( Dynamic(new _Function_2_1(s)));		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(7)
		::haxe::ds::Either e = tmp2;		HX_STACK_VAR(e,"e");
		HX_STACK_LINE(7)
		tmp1 = e;
	}
	HX_STACK_LINE(7)
	s->events->on(HX_HCSTRING("Hello","\xf2","\xa2","\xee","\xb7"),tmp1);
	HX_STACK_LINE(15)
	s->start();
}
;
	return null();
}

//Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > _result_ = new Main_obj();
	_result_->__construct();
	return _result_;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > _result_ = new Main_obj();
	_result_->__construct();
	return _result_;}

Void Main_obj::main( ){
{
		HX_STACK_FRAME("Main","main",0xed0e206e,"Main.main","Main.hx",18,0x087e5c05)
		HX_STACK_LINE(18)
		::Main_obj::__new();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,main,(void))


Main_obj::Main_obj()
{
}

bool Main_obj::__GetStatic(const ::String &inName, Dynamic &outValue, hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { outValue = main_dyn(); return true;  }
	}
	return false;
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

#endif

hx::Class Main_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("main","\x39","\x38","\x56","\x48"),
	::String(null()) };

void Main_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("Main","\x59","\x64","\x2f","\x33");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Main_obj::__GetStatic;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(sStaticFields);
	__mClass->mMembers = hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = hx::TCanCast< Main_obj >;
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


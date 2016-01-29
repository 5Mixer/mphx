#include <hxcpp.h>

#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_ds_Either
#include <haxe/ds/Either.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_mphx_core_EventManager
#include <mphx/core/EventManager.h>
#endif
#ifndef INCLUDED_mphx_tcp_Protocol
#include <mphx/tcp/Protocol.h>
#endif
namespace mphx{
namespace core{

Void EventManager_obj::__construct()
{
HX_STACK_FRAME("mphx.core.EventManager","new",0xe3a1f479,"mphx.core.EventManager.new","mphx/core/EventManager.hx",9,0x693b8cb7)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(10)
	::haxe::ds::StringMap tmp;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(10)
	{
		HX_STACK_LINE(10)
		::haxe::ds::StringMap tmp1 = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(10)
		::haxe::ds::StringMap tmp2 = tmp1;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(10)
		tmp = tmp2;
	}
	HX_STACK_LINE(10)
	this->eventMap = tmp;
}
;
	return null();
}

//EventManager_obj::~EventManager_obj() { }

Dynamic EventManager_obj::__CreateEmpty() { return  new EventManager_obj; }
hx::ObjectPtr< EventManager_obj > EventManager_obj::__new()
{  hx::ObjectPtr< EventManager_obj > _result_ = new EventManager_obj();
	_result_->__construct();
	return _result_;}

Dynamic EventManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EventManager_obj > _result_ = new EventManager_obj();
	_result_->__construct();
	return _result_;}

Void EventManager_obj::on( ::String eventName,::haxe::ds::Either event){
{
		HX_STACK_FRAME("mphx.core.EventManager","on",0x70600326,"mphx.core.EventManager.on","mphx/core/EventManager.hx",13,0x693b8cb7)
		HX_STACK_THIS(this)
		HX_STACK_ARG(eventName,"eventName")
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(14)
		::haxe::ds::StringMap tmp = this->eventMap;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(14)
		::String tmp1 = eventName;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(14)
		::haxe::ds::Either tmp2 = event;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(14)
		tmp->set(tmp1,tmp2);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(EventManager_obj,on,(void))

Void EventManager_obj::callEvent( ::String eventName,Dynamic data,::mphx::tcp::Protocol sender){
{
		HX_STACK_FRAME("mphx.core.EventManager","callEvent",0x681ddf75,"mphx.core.EventManager.callEvent","mphx/core/EventManager.hx",16,0x693b8cb7)
		HX_STACK_THIS(this)
		HX_STACK_ARG(eventName,"eventName")
		HX_STACK_ARG(data,"data")
		HX_STACK_ARG(sender,"sender")
		HX_STACK_LINE(17)
		::haxe::ds::StringMap tmp = this->eventMap;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(17)
		::String tmp1 = eventName;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(17)
		bool tmp2 = tmp->exists(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(17)
		bool tmp3 = (tmp2 == false);		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(17)
		if ((tmp3)){
		}
		HX_STACK_LINE(21)
		{
			HX_STACK_LINE(21)
			::haxe::ds::Either tmp4;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(21)
			{
				HX_STACK_LINE(21)
				::haxe::ds::StringMap tmp5 = this->eventMap;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(21)
				::String tmp6 = eventName;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(21)
				::haxe::ds::Either tmp7 = tmp5->get(tmp6);		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(21)
				::haxe::ds::Either this1 = tmp7;		HX_STACK_VAR(this1,"this1");
				HX_STACK_LINE(21)
				tmp4 = this1;
			}
			HX_STACK_LINE(21)
			::haxe::ds::Either _g = tmp4;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(21)
			switch( (int)(_g->__Index())){
				case (int)0: {
					HX_STACK_LINE(21)
					Dynamic tmp5 = (::haxe::ds::Either(_g))->__Param(0);		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(21)
					Dynamic eventWithSender = tmp5;		HX_STACK_VAR(eventWithSender,"eventWithSender");
					HX_STACK_LINE(22)
					{
						HX_STACK_LINE(22)
						Dynamic tmp6 = data;		HX_STACK_VAR(tmp6,"tmp6");
						HX_STACK_LINE(22)
						::mphx::tcp::Protocol tmp7 = sender;		HX_STACK_VAR(tmp7,"tmp7");
						HX_STACK_LINE(22)
						eventWithSender(tmp6,tmp7).Cast< Void >();
					}
				}
				;break;
				case (int)1: {
					HX_STACK_LINE(21)
					Dynamic tmp5 = (::haxe::ds::Either(_g))->__Param(0);		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(21)
					Dynamic eventWithoutSender = tmp5;		HX_STACK_VAR(eventWithoutSender,"eventWithoutSender");
					HX_STACK_LINE(23)
					{
						HX_STACK_LINE(23)
						Dynamic tmp6 = data;		HX_STACK_VAR(tmp6,"tmp6");
						HX_STACK_LINE(23)
						eventWithoutSender(tmp6).Cast< Void >();
					}
				}
				;break;
			}
		}
		HX_STACK_LINE(25)
		::String tmp4 = (HX_HCSTRING("Event recieved: ","\xf5","\xc9","\x33","\xa7") + eventName);		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(25)
		Dynamic tmp5 = hx::SourceInfo(HX_HCSTRING("EventManager.hx","\x0b","\xeb","\x97","\xc8"),25,HX_HCSTRING("mphx.core.EventManager","\x07","\x44","\xa6","\x32"),HX_HCSTRING("callEvent","\x9c","\x22","\x04","\x02"));		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(25)
		::haxe::Log_obj::trace(tmp4,tmp5);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(EventManager_obj,callEvent,(void))


EventManager_obj::EventManager_obj()
{
}

void EventManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EventManager);
	HX_MARK_MEMBER_NAME(eventMap,"eventMap");
	HX_MARK_END_CLASS();
}

void EventManager_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(eventMap,"eventMap");
}

Dynamic EventManager_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"on") ) { return on_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"eventMap") ) { return eventMap; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"callEvent") ) { return callEvent_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EventManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"eventMap") ) { eventMap=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool EventManager_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,hx::PropertyAccess inCallProp)
{
	return false;
}

void EventManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("eventMap","\xa2","\x86","\xd2","\xc0"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(EventManager_obj,eventMap),HX_HCSTRING("eventMap","\xa2","\x86","\xd2","\xc0")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("eventMap","\xa2","\x86","\xd2","\xc0"),
	HX_HCSTRING("on","\x1f","\x61","\x00","\x00"),
	HX_HCSTRING("callEvent","\x9c","\x22","\x04","\x02"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EventManager_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EventManager_obj::__mClass,"__mClass");
};

#endif

hx::Class EventManager_obj::__mClass;

void EventManager_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("mphx.core.EventManager","\x07","\x44","\xa6","\x32");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &EventManager_obj::__SetStatic;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< EventManager_obj >;
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
} // end namespace core

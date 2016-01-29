#include <hxcpp.h>

#ifndef INCLUDED_haxe_ds_Either
#include <haxe/ds/Either.h>
#endif
#ifndef INCLUDED_mphx_core__EventManager_Either_Impl_
#include <mphx/core/_EventManager/Either_Impl_.h>
#endif
namespace mphx{
namespace core{
namespace _EventManager{

Void Either_Impl__obj::__construct()
{
	return null();
}

//Either_Impl__obj::~Either_Impl__obj() { }

Dynamic Either_Impl__obj::__CreateEmpty() { return  new Either_Impl__obj; }
hx::ObjectPtr< Either_Impl__obj > Either_Impl__obj::__new()
{  hx::ObjectPtr< Either_Impl__obj > _result_ = new Either_Impl__obj();
	_result_->__construct();
	return _result_;}

Dynamic Either_Impl__obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Either_Impl__obj > _result_ = new Either_Impl__obj();
	_result_->__construct();
	return _result_;}

::haxe::ds::Either Either_Impl__obj::_new( ::haxe::ds::Either e){
	HX_STACK_FRAME("mphx.core._EventManager.Either_Impl_","_new",0xc28f15ba,"mphx.core._EventManager.Either_Impl_._new","mphx/core/EventManager.hx",38,0x693b8cb7)
	HX_STACK_ARG(e,"e")
	HX_STACK_LINE(38)
	::haxe::ds::Either tmp = e;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(38)
	return tmp;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Either_Impl__obj,_new,return )

::haxe::ds::Either Either_Impl__obj::get_type( ::haxe::ds::Either this1){
	HX_STACK_FRAME("mphx.core._EventManager.Either_Impl_","get_type",0x06dd4f1c,"mphx.core._EventManager.Either_Impl_.get_type","mphx/core/EventManager.hx",43,0x693b8cb7)
	HX_STACK_ARG(this1,"this1")
	HX_STACK_LINE(44)
	::haxe::ds::Either tmp = this1;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(44)
	return tmp;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Either_Impl__obj,get_type,return )

::haxe::ds::Either Either_Impl__obj::fromLeft( Dynamic left){
	HX_STACK_FRAME("mphx.core._EventManager.Either_Impl_","fromLeft",0xdf95776a,"mphx.core._EventManager.Either_Impl_.fromLeft","mphx/core/EventManager.hx",48,0x693b8cb7)
	HX_STACK_ARG(left,"left")
	HX_STACK_LINE(49)
	::haxe::ds::Either tmp;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(49)
	{
		HX_STACK_LINE(49)
		Dynamic tmp1 = left;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(49)
		::haxe::ds::Either tmp2 = ::haxe::ds::Either_obj::Left(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(49)
		::haxe::ds::Either e = tmp2;		HX_STACK_VAR(e,"e");
		HX_STACK_LINE(49)
		tmp = e;
	}
	HX_STACK_LINE(49)
	return tmp;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Either_Impl__obj,fromLeft,return )

::haxe::ds::Either Either_Impl__obj::fromRight( Dynamic right){
	HX_STACK_FRAME("mphx.core._EventManager.Either_Impl_","fromRight",0x3a401319,"mphx.core._EventManager.Either_Impl_.fromRight","mphx/core/EventManager.hx",53,0x693b8cb7)
	HX_STACK_ARG(right,"right")
	HX_STACK_LINE(54)
	::haxe::ds::Either tmp;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(54)
	{
		HX_STACK_LINE(54)
		Dynamic tmp1 = right;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(54)
		::haxe::ds::Either tmp2 = ::haxe::ds::Either_obj::Right(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(54)
		::haxe::ds::Either e = tmp2;		HX_STACK_VAR(e,"e");
		HX_STACK_LINE(54)
		tmp = e;
	}
	HX_STACK_LINE(54)
	return tmp;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Either_Impl__obj,fromRight,return )


Either_Impl__obj::Either_Impl__obj()
{
}

bool Either_Impl__obj::__GetStatic(const ::String &inName, Dynamic &outValue, hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_new") ) { outValue = _new_dyn(); return true;  }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_type") ) { outValue = get_type_dyn(); return true;  }
		if (HX_FIELD_EQ(inName,"fromLeft") ) { outValue = fromLeft_dyn(); return true;  }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"fromRight") ) { outValue = fromRight_dyn(); return true;  }
	}
	return false;
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Either_Impl__obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Either_Impl__obj::__mClass,"__mClass");
};

#endif

hx::Class Either_Impl__obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("_new","\x61","\x15","\x1f","\x3f"),
	HX_HCSTRING("get_type","\x43","\xae","\xc3","\xcc"),
	HX_HCSTRING("fromLeft","\x91","\xd6","\x7b","\xa5"),
	HX_HCSTRING("fromRight","\x12","\xf6","\xec","\x9d"),
	::String(null()) };

void Either_Impl__obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("mphx.core._EventManager.Either_Impl_","\xb5","\x3e","\x36","\x74");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Either_Impl__obj::__GetStatic;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(sStaticFields);
	__mClass->mMembers = hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = hx::TCanCast< Either_Impl__obj >;
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
} // end namespace _EventManager

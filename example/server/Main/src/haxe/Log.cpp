#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
namespace haxe{

Void Log_obj::__construct()
{
	return null();
}

//Log_obj::~Log_obj() { }

Dynamic Log_obj::__CreateEmpty() { return  new Log_obj; }
hx::ObjectPtr< Log_obj > Log_obj::__new()
{  hx::ObjectPtr< Log_obj > _result_ = new Log_obj();
	_result_->__construct();
	return _result_;}

Dynamic Log_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Log_obj > _result_ = new Log_obj();
	_result_->__construct();
	return _result_;}

HX_BEGIN_DEFAULT_FUNC(__default_trace,Log_obj)
Void run(Dynamic v,Dynamic infos){
{
		HX_STACK_FRAME("haxe.Log","trace",0x5d6e40b3,"haxe.Log.trace","C:\\HaxeToolkit\\haxe\\std/haxe/Log.hx",45,0x3ca487aa)
		HX_STACK_ARG(v,"v")
		HX_STACK_ARG(infos,"infos")
		HX_STACK_LINE(73)
		bool tmp = (infos != null());		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(73)
		bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(73)
		if ((tmp)){
			HX_STACK_LINE(73)
			tmp1 = (infos->__Field(HX_HCSTRING("customParams","\xd7","\x51","\x18","\xed"), hx::paccDynamic ) != null());
		}
		else{
			HX_STACK_LINE(73)
			tmp1 = false;
		}
		HX_STACK_LINE(73)
		if ((tmp1)){
			HX_STACK_LINE(74)
			::String extra = HX_HCSTRING("","\x00","\x00","\x00","\x00");		HX_STACK_VAR(extra,"extra");
			HX_STACK_LINE(75)
			{
				HX_STACK_LINE(75)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(75)
				cpp::ArrayBase _g1 = infos->__Field(HX_HCSTRING("customParams","\xd7","\x51","\x18","\xed"), hx::paccDynamic );		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(75)
				while((true)){
					HX_STACK_LINE(75)
					bool tmp2 = (_g < _g1->__Field(HX_HCSTRING("length","\xe6","\x94","\x07","\x9f"), hx::paccDynamic ));		HX_STACK_VAR(tmp2,"tmp2");
					HX_STACK_LINE(75)
					bool tmp3 = !(tmp2);		HX_STACK_VAR(tmp3,"tmp3");
					HX_STACK_LINE(75)
					if ((tmp3)){
						HX_STACK_LINE(75)
						break;
					}
					HX_STACK_LINE(75)
					Dynamic tmp4 = _g1->__GetItem(_g);		HX_STACK_VAR(tmp4,"tmp4");
					HX_STACK_LINE(75)
					Dynamic v1 = tmp4;		HX_STACK_VAR(v1,"v1");
					HX_STACK_LINE(75)
					++(_g);
					HX_STACK_LINE(76)
					Dynamic tmp5 = v1;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(76)
					::String tmp6 = ::Std_obj::string(tmp5);		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(76)
					::String tmp7 = (HX_HCSTRING(",","\x2c","\x00","\x00","\x00") + tmp6);		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(76)
					hx::AddEq(extra,tmp7);
				}
			}
			HX_STACK_LINE(77)
			__trace((::Std_obj::string(v) + extra),infos);
		}
		else{
			HX_STACK_LINE(80)
			__trace(v,infos);
		}
	}
return null();
}
HX_END_LOCAL_FUNC2((void))
HX_END_DEFAULT_FUNC

Dynamic Log_obj::trace;


Log_obj::Log_obj()
{
}

bool Log_obj::__GetStatic(const ::String &inName, Dynamic &outValue, hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"trace") ) { outValue = trace; return true;  }
	}
	return false;
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo sStaticStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(void *) &Log_obj::trace,HX_HCSTRING("trace","\x85","\x8e","\x1f","\x16")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Log_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Log_obj::trace,"trace");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Log_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Log_obj::trace,"trace");
};

#endif

hx::Class Log_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("trace","\x85","\x8e","\x1f","\x16"),
	::String(null()) };

void Log_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("haxe.Log","\x1c","\x1c","\x0e","\x3f");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Log_obj::__GetStatic;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(sStaticFields);
	__mClass->mMembers = hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = hx::TCanCast< Log_obj >;
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

void Log_obj::__boot()
{
	trace = new __default_trace;

}

} // end namespace haxe

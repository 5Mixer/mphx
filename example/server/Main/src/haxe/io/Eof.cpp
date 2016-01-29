#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Eof
#include <haxe/io/Eof.h>
#endif
namespace haxe{
namespace io{

Void Eof_obj::__construct()
{
HX_STACK_FRAME("haxe.io.Eof","new",0x2166e64e,"haxe.io.Eof.new","C:\\HaxeToolkit\\haxe\\std/haxe/io/Eof.hx",28,0xe8efd11b)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//Eof_obj::~Eof_obj() { }

Dynamic Eof_obj::__CreateEmpty() { return  new Eof_obj; }
hx::ObjectPtr< Eof_obj > Eof_obj::__new()
{  hx::ObjectPtr< Eof_obj > _result_ = new Eof_obj();
	_result_->__construct();
	return _result_;}

Dynamic Eof_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Eof_obj > _result_ = new Eof_obj();
	_result_->__construct();
	return _result_;}

::String Eof_obj::toString( ){
	HX_STACK_FRAME("haxe.io.Eof","toString",0xf9ff7bfe,"haxe.io.Eof.toString","C:\\HaxeToolkit\\haxe\\std/haxe/io/Eof.hx",31,0xe8efd11b)
	HX_STACK_THIS(this)
	HX_STACK_LINE(31)
	return HX_HCSTRING("Eof","\x9c","\xbc","\x34","\x00");
}


HX_DEFINE_DYNAMIC_FUNC0(Eof_obj,toString,return )


Eof_obj::Eof_obj()
{
}

Dynamic Eof_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("toString","\xac","\xd0","\x6e","\x38"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Eof_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Eof_obj::__mClass,"__mClass");
};

#endif

hx::Class Eof_obj::__mClass;

void Eof_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("haxe.io.Eof","\x5c","\x67","\x0e","\x25");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< Eof_obj >;
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

} // end namespace haxe
} // end namespace io

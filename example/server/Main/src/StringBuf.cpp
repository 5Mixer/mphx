#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif

Void StringBuf_obj::__construct()
{
HX_STACK_FRAME("StringBuf","new",0xaaa8f4b4,"StringBuf.new","C:\\HaxeToolkit\\haxe\\std/cpp/_std/StringBuf.hx",30,0xac74b422)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(30)
	this->b = Array_obj< ::String >::__new();
}
;
	return null();
}

//StringBuf_obj::~StringBuf_obj() { }

Dynamic StringBuf_obj::__CreateEmpty() { return  new StringBuf_obj; }
hx::ObjectPtr< StringBuf_obj > StringBuf_obj::__new()
{  hx::ObjectPtr< StringBuf_obj > _result_ = new StringBuf_obj();
	_result_->__construct();
	return _result_;}

Dynamic StringBuf_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< StringBuf_obj > _result_ = new StringBuf_obj();
	_result_->__construct();
	return _result_;}

Void StringBuf_obj::add( Dynamic x){
{
		HX_STACK_FRAME("StringBuf","add",0xaa9f1675,"StringBuf.add","C:\\HaxeToolkit\\haxe\\std/cpp/_std/StringBuf.hx",40,0xac74b422)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_LINE(41)
		Dynamic tmp = x;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(41)
		::String tmp1 = ::Std_obj::string(tmp);		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(41)
		this->b->push(tmp1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(StringBuf_obj,add,(void))


StringBuf_obj::StringBuf_obj()
{
}

void StringBuf_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(StringBuf);
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_END_CLASS();
}

void StringBuf_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(b,"b");
}

Dynamic StringBuf_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic StringBuf_obj::__SetField(const ::String &inName,const Dynamic &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< Array< ::String > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool StringBuf_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,hx::PropertyAccess inCallProp)
{
	return false;
}

void StringBuf_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("b","\x62","\x00","\x00","\x00"));
	outFields->push(HX_HCSTRING("length","\xe6","\x94","\x07","\x9f"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::String >*/ ,(int)offsetof(StringBuf_obj,b),HX_HCSTRING("b","\x62","\x00","\x00","\x00")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("b","\x62","\x00","\x00","\x00"),
	HX_HCSTRING("add","\x21","\xf2","\x49","\x00"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(StringBuf_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StringBuf_obj::__mClass,"__mClass");
};

#endif

hx::Class StringBuf_obj::__mClass;

void StringBuf_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("StringBuf","\xc2","\xca","\x83","\x69");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &StringBuf_obj::__SetStatic;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< StringBuf_obj >;
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


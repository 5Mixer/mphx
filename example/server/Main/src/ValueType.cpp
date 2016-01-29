#include <hxcpp.h>

#ifndef INCLUDED_ValueType
#include <ValueType.h>
#endif

::ValueType ValueType_obj::TBool;

::ValueType  ValueType_obj::TClass(::hx::Class c)
	{ return hx::CreateEnum< ValueType_obj >(HX_HCSTRING("TClass","\x44","\x37","\x80","\x71"),6,hx::DynamicArray(0,1).Add(c)); }

::ValueType  ValueType_obj::TEnum(::Enum e)
	{ return hx::CreateEnum< ValueType_obj >(HX_HCSTRING("TEnum","\x75","\x51","\x98","\x8b"),7,hx::DynamicArray(0,1).Add(e)); }

::ValueType ValueType_obj::TFloat;

::ValueType ValueType_obj::TFunction;

::ValueType ValueType_obj::TInt;

::ValueType ValueType_obj::TNull;

::ValueType ValueType_obj::TObject;

::ValueType ValueType_obj::TUnknown;

HX_DEFINE_CREATE_ENUM(ValueType_obj)

int ValueType_obj::__FindIndex(::String inName)
{
	if (inName==HX_HCSTRING("TBool","\x9e","\x6a","\x9d","\x89")) return 3;
	if (inName==HX_HCSTRING("TClass","\x44","\x37","\x80","\x71")) return 6;
	if (inName==HX_HCSTRING("TEnum","\x75","\x51","\x98","\x8b")) return 7;
	if (inName==HX_HCSTRING("TFloat","\xa8","\x84","\xbe","\x2b")) return 2;
	if (inName==HX_HCSTRING("TFunction","\x8c","\xdb","\x3a","\x25")) return 5;
	if (inName==HX_HCSTRING("TInt","\xfb","\xb0","\xbd","\x37")) return 1;
	if (inName==HX_HCSTRING("TNull","\xfb","\x84","\x90","\x91")) return 0;
	if (inName==HX_HCSTRING("TObject","\x33","\xea","\xde","\xee")) return 4;
	if (inName==HX_HCSTRING("TUnknown","\x96","\xbd","\x59","\x73")) return 8;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(ValueType_obj,TClass,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(ValueType_obj,TEnum,return)

int ValueType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_HCSTRING("TBool","\x9e","\x6a","\x9d","\x89")) return 0;
	if (inName==HX_HCSTRING("TClass","\x44","\x37","\x80","\x71")) return 1;
	if (inName==HX_HCSTRING("TEnum","\x75","\x51","\x98","\x8b")) return 1;
	if (inName==HX_HCSTRING("TFloat","\xa8","\x84","\xbe","\x2b")) return 0;
	if (inName==HX_HCSTRING("TFunction","\x8c","\xdb","\x3a","\x25")) return 0;
	if (inName==HX_HCSTRING("TInt","\xfb","\xb0","\xbd","\x37")) return 0;
	if (inName==HX_HCSTRING("TNull","\xfb","\x84","\x90","\x91")) return 0;
	if (inName==HX_HCSTRING("TObject","\x33","\xea","\xde","\xee")) return 0;
	if (inName==HX_HCSTRING("TUnknown","\x96","\xbd","\x59","\x73")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic ValueType_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	if (inName==HX_HCSTRING("TBool","\x9e","\x6a","\x9d","\x89")) return TBool;
	if (inName==HX_HCSTRING("TClass","\x44","\x37","\x80","\x71")) return TClass_dyn();
	if (inName==HX_HCSTRING("TEnum","\x75","\x51","\x98","\x8b")) return TEnum_dyn();
	if (inName==HX_HCSTRING("TFloat","\xa8","\x84","\xbe","\x2b")) return TFloat;
	if (inName==HX_HCSTRING("TFunction","\x8c","\xdb","\x3a","\x25")) return TFunction;
	if (inName==HX_HCSTRING("TInt","\xfb","\xb0","\xbd","\x37")) return TInt;
	if (inName==HX_HCSTRING("TNull","\xfb","\x84","\x90","\x91")) return TNull;
	if (inName==HX_HCSTRING("TObject","\x33","\xea","\xde","\xee")) return TObject;
	if (inName==HX_HCSTRING("TUnknown","\x96","\xbd","\x59","\x73")) return TUnknown;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_HCSTRING("TNull","\xfb","\x84","\x90","\x91"),
	HX_HCSTRING("TInt","\xfb","\xb0","\xbd","\x37"),
	HX_HCSTRING("TFloat","\xa8","\x84","\xbe","\x2b"),
	HX_HCSTRING("TBool","\x9e","\x6a","\x9d","\x89"),
	HX_HCSTRING("TObject","\x33","\xea","\xde","\xee"),
	HX_HCSTRING("TFunction","\x8c","\xdb","\x3a","\x25"),
	HX_HCSTRING("TClass","\x44","\x37","\x80","\x71"),
	HX_HCSTRING("TEnum","\x75","\x51","\x98","\x8b"),
	HX_HCSTRING("TUnknown","\x96","\xbd","\x59","\x73"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ValueType_obj::TBool,"TBool");
	HX_MARK_MEMBER_NAME(ValueType_obj::TFloat,"TFloat");
	HX_MARK_MEMBER_NAME(ValueType_obj::TFunction,"TFunction");
	HX_MARK_MEMBER_NAME(ValueType_obj::TInt,"TInt");
	HX_MARK_MEMBER_NAME(ValueType_obj::TNull,"TNull");
	HX_MARK_MEMBER_NAME(ValueType_obj::TObject,"TObject");
	HX_MARK_MEMBER_NAME(ValueType_obj::TUnknown,"TUnknown");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ValueType_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ValueType_obj::TBool,"TBool");
	HX_VISIT_MEMBER_NAME(ValueType_obj::TFloat,"TFloat");
	HX_VISIT_MEMBER_NAME(ValueType_obj::TFunction,"TFunction");
	HX_VISIT_MEMBER_NAME(ValueType_obj::TInt,"TInt");
	HX_VISIT_MEMBER_NAME(ValueType_obj::TNull,"TNull");
	HX_VISIT_MEMBER_NAME(ValueType_obj::TObject,"TObject");
	HX_VISIT_MEMBER_NAME(ValueType_obj::TUnknown,"TUnknown");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
hx::Class ValueType_obj::__mClass;

Dynamic __Create_ValueType_obj() { return new ValueType_obj; }

void ValueType_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("ValueType","\xab","\x8a","\x60","\x3b"), hx::TCanCast< ValueType_obj >,sStaticFields,sMemberFields,
	&__Create_ValueType_obj, &__Create,
	&super::__SGetClass(), &CreateValueType_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void ValueType_obj::__boot()
{
hx::Static(TBool) = hx::CreateEnum< ValueType_obj >(HX_HCSTRING("TBool","\x9e","\x6a","\x9d","\x89"),3);
hx::Static(TFloat) = hx::CreateEnum< ValueType_obj >(HX_HCSTRING("TFloat","\xa8","\x84","\xbe","\x2b"),2);
hx::Static(TFunction) = hx::CreateEnum< ValueType_obj >(HX_HCSTRING("TFunction","\x8c","\xdb","\x3a","\x25"),5);
hx::Static(TInt) = hx::CreateEnum< ValueType_obj >(HX_HCSTRING("TInt","\xfb","\xb0","\xbd","\x37"),1);
hx::Static(TNull) = hx::CreateEnum< ValueType_obj >(HX_HCSTRING("TNull","\xfb","\x84","\x90","\x91"),0);
hx::Static(TObject) = hx::CreateEnum< ValueType_obj >(HX_HCSTRING("TObject","\x33","\xea","\xde","\xee"),4);
hx::Static(TUnknown) = hx::CreateEnum< ValueType_obj >(HX_HCSTRING("TUnknown","\x96","\xbd","\x59","\x73"),8);
}



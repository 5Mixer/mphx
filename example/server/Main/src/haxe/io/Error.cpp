#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
namespace haxe{
namespace io{

::haxe::io::Error Error_obj::Blocked;

::haxe::io::Error  Error_obj::Custom(Dynamic e)
	{ return hx::CreateEnum< Error_obj >(HX_HCSTRING("Custom","\xd1","\xfb","\x26","\x74"),3,hx::DynamicArray(0,1).Add(e)); }

::haxe::io::Error Error_obj::OutsideBounds;

::haxe::io::Error Error_obj::Overflow;

HX_DEFINE_CREATE_ENUM(Error_obj)

int Error_obj::__FindIndex(::String inName)
{
	if (inName==HX_HCSTRING("Blocked","\xcc","\xa2","\x4f","\x12")) return 0;
	if (inName==HX_HCSTRING("Custom","\xd1","\xfb","\x26","\x74")) return 3;
	if (inName==HX_HCSTRING("OutsideBounds","\x5a","\xc1","\x82","\x38")) return 2;
	if (inName==HX_HCSTRING("Overflow","\x62","\x9f","\xed","\x1a")) return 1;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Error_obj,Custom,return)

int Error_obj::__FindArgCount(::String inName)
{
	if (inName==HX_HCSTRING("Blocked","\xcc","\xa2","\x4f","\x12")) return 0;
	if (inName==HX_HCSTRING("Custom","\xd1","\xfb","\x26","\x74")) return 1;
	if (inName==HX_HCSTRING("OutsideBounds","\x5a","\xc1","\x82","\x38")) return 0;
	if (inName==HX_HCSTRING("Overflow","\x62","\x9f","\xed","\x1a")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic Error_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	if (inName==HX_HCSTRING("Blocked","\xcc","\xa2","\x4f","\x12")) return Blocked;
	if (inName==HX_HCSTRING("Custom","\xd1","\xfb","\x26","\x74")) return Custom_dyn();
	if (inName==HX_HCSTRING("OutsideBounds","\x5a","\xc1","\x82","\x38")) return OutsideBounds;
	if (inName==HX_HCSTRING("Overflow","\x62","\x9f","\xed","\x1a")) return Overflow;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_HCSTRING("Blocked","\xcc","\xa2","\x4f","\x12"),
	HX_HCSTRING("Overflow","\x62","\x9f","\xed","\x1a"),
	HX_HCSTRING("OutsideBounds","\x5a","\xc1","\x82","\x38"),
	HX_HCSTRING("Custom","\xd1","\xfb","\x26","\x74"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Error_obj::Blocked,"Blocked");
	HX_MARK_MEMBER_NAME(Error_obj::OutsideBounds,"OutsideBounds");
	HX_MARK_MEMBER_NAME(Error_obj::Overflow,"Overflow");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Error_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Error_obj::Blocked,"Blocked");
	HX_VISIT_MEMBER_NAME(Error_obj::OutsideBounds,"OutsideBounds");
	HX_VISIT_MEMBER_NAME(Error_obj::Overflow,"Overflow");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
hx::Class Error_obj::__mClass;

Dynamic __Create_Error_obj() { return new Error_obj; }

void Error_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("haxe.io.Error","\x68","\x16","\x01","\x55"), hx::TCanCast< Error_obj >,sStaticFields,sMemberFields,
	&__Create_Error_obj, &__Create,
	&super::__SGetClass(), &CreateError_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void Error_obj::__boot()
{
hx::Static(Blocked) = hx::CreateEnum< Error_obj >(HX_HCSTRING("Blocked","\xcc","\xa2","\x4f","\x12"),0);
hx::Static(OutsideBounds) = hx::CreateEnum< Error_obj >(HX_HCSTRING("OutsideBounds","\x5a","\xc1","\x82","\x38"),2);
hx::Static(Overflow) = hx::CreateEnum< Error_obj >(HX_HCSTRING("Overflow","\x62","\x9f","\xed","\x1a"),1);
}


} // end namespace haxe
} // end namespace io

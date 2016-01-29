#include <hxcpp.h>

#ifndef INCLUDED_haxe_ds_Either
#include <haxe/ds/Either.h>
#endif
namespace haxe{
namespace ds{

::haxe::ds::Either  Either_obj::Left(Dynamic v)
	{ return hx::CreateEnum< Either_obj >(HX_HCSTRING("Left","\x27","\x34","\x89","\x32"),0,hx::DynamicArray(0,1).Add(v)); }

::haxe::ds::Either  Either_obj::Right(Dynamic v)
	{ return hx::CreateEnum< Either_obj >(HX_HCSTRING("Right","\xbc","\x7b","\x91","\x7c"),1,hx::DynamicArray(0,1).Add(v)); }

HX_DEFINE_CREATE_ENUM(Either_obj)

int Either_obj::__FindIndex(::String inName)
{
	if (inName==HX_HCSTRING("Left","\x27","\x34","\x89","\x32")) return 0;
	if (inName==HX_HCSTRING("Right","\xbc","\x7b","\x91","\x7c")) return 1;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Either_obj,Left,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Either_obj,Right,return)

int Either_obj::__FindArgCount(::String inName)
{
	if (inName==HX_HCSTRING("Left","\x27","\x34","\x89","\x32")) return 1;
	if (inName==HX_HCSTRING("Right","\xbc","\x7b","\x91","\x7c")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic Either_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	if (inName==HX_HCSTRING("Left","\x27","\x34","\x89","\x32")) return Left_dyn();
	if (inName==HX_HCSTRING("Right","\xbc","\x7b","\x91","\x7c")) return Right_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_HCSTRING("Left","\x27","\x34","\x89","\x32"),
	HX_HCSTRING("Right","\xbc","\x7b","\x91","\x7c"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Either_obj::__mClass,"__mClass");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
hx::Class Either_obj::__mClass;

Dynamic __Create_Either_obj() { return new Either_obj; }

void Either_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_HCSTRING("haxe.ds.Either","\x1c","\x1a","\xb7","\xa4"), hx::TCanCast< Either_obj >,sStaticFields,sMemberFields,
	&__Create_Either_obj, &__Create,
	&super::__SGetClass(), &CreateEither_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void Either_obj::__boot()
{
}


} // end namespace haxe
} // end namespace ds

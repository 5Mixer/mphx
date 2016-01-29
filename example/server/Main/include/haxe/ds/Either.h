#ifndef INCLUDED_haxe_ds_Either
#define INCLUDED_haxe_ds_Either

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,ds,Either)
namespace haxe{
namespace ds{


class Either_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Either_obj OBJ_;

	public:
		Either_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_HCSTRING("haxe.ds.Either","\x1c","\x1a","\xb7","\xa4"); }
		::String __ToString() const { return HX_HCSTRING("Either.","\x29","\x67","\x48","\x40") + tag; }

		static ::haxe::ds::Either Left(Dynamic v);
		static Dynamic Left_dyn();
		static ::haxe::ds::Either Right(Dynamic v);
		static Dynamic Right_dyn();
};

} // end namespace haxe
} // end namespace ds

#endif /* INCLUDED_haxe_ds_Either */ 

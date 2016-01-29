#ifndef INCLUDED_haxe_ds_ObjectMap
#define INCLUDED_haxe_ds_ObjectMap

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
HX_DECLARE_CLASS1(haxe,IMap)
HX_DECLARE_CLASS2(haxe,ds,ObjectMap)
namespace haxe{
namespace ds{


class HXCPP_CLASS_ATTRIBUTES  ObjectMap_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ObjectMap_obj OBJ_;
		ObjectMap_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true,const char *inName="haxe.ds.ObjectMap")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		static hx::ObjectPtr< ObjectMap_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ObjectMap_obj();

		HX_DO_RTTI_ALL;
		Dynamic __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		Dynamic __SetField(const ::String &inString,const Dynamic &inValue, hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		hx::Object *__ToInterface(const hx::type_info &inType);
		operator ::haxe::IMap_obj *();
		::String __ToString() const { return HX_HCSTRING("ObjectMap","\xfd","\xa4","\x50","\xe5"); }

		Dynamic h;
		virtual Void set( Dynamic key,Dynamic value);
		Dynamic set_dyn();

		virtual bool remove( Dynamic key);
		Dynamic remove_dyn();

		virtual Dynamic iterator( );
		Dynamic iterator_dyn();


  inline void set(Dynamic key, ::null value) { __object_hash_set(h,key,value); }
  inline void set(Dynamic key, bool value) { __object_hash_set(h,key,value); }
  inline void set(Dynamic key, char value) { __object_hash_set_int(h,key,value); }
  inline void set(Dynamic key, unsigned char value) { __object_hash_set_int(h,key,value); }
  inline void set(Dynamic key, signed char value) { __object_hash_set_int(h,key,value); }
  inline void set(Dynamic key, short value) { __object_hash_set_int(h,key,value); }
  inline void set(Dynamic key, unsigned short value) { __object_hash_set_int(h,key,value); }
  inline void set(Dynamic key, int value) { __object_hash_set_int(h,key,value); }
  inline void set(Dynamic key, unsigned int value) { __object_hash_set_int(h,key,value); }
  inline void set(Dynamic key, float value) { __object_hash_set_float(h,key,value); }
  inline void set(Dynamic key, double value) { __object_hash_set_float(h,key,value); }
  inline void set(Dynamic key, ::String value) { __object_hash_set_string(h,key,value); }


  template<typename V, typename H>
  inline void set(Dynamic key, const ::cpp::Struct<V,H> &value) {__object_hash_set(h,key,value); }
  template<typename V>
  inline void set(Dynamic key, const ::cpp::Function<V> &value) {__object_hash_set(h,key,(Dynamic)value ); }
  template<typename V>
  inline void set(Dynamic key, const ::cpp::Pointer<V> &value) {__object_hash_set(h,key,(Dynamic)value ); }


};

} // end namespace haxe
} // end namespace ds

#endif /* INCLUDED_haxe_ds_ObjectMap */ 

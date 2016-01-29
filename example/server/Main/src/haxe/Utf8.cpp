#include <hxcpp.h>

#ifndef INCLUDED_haxe_Utf8
#include <haxe/Utf8.h>
#endif
namespace haxe{

Void Utf8_obj::__construct(Dynamic size)
{
HX_STACK_FRAME("haxe.Utf8","new",0x67cc940b,"haxe.Utf8.new","C:\\HaxeToolkit\\haxe\\std/cpp/_std/haxe/Utf8.hx",29,0xf320feca)
HX_STACK_THIS(this)
HX_STACK_ARG(size,"size")
{
	HX_STACK_LINE(30)
	this->__s = Array_obj< int >::__new();
	HX_STACK_LINE(31)
	bool tmp = (size != null());		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(31)
	bool tmp1;		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(31)
	if ((tmp)){
		HX_STACK_LINE(31)
		tmp1 = (size > (int)0);
	}
	else{
		HX_STACK_LINE(31)
		tmp1 = false;
	}
	HX_STACK_LINE(31)
	if ((tmp1)){
		HX_STACK_LINE(32)
		int tmp2 = (size - (int)1);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(32)
		this->__s[tmp2] = (int)0;
	}
}
;
	return null();
}

//Utf8_obj::~Utf8_obj() { }

Dynamic Utf8_obj::__CreateEmpty() { return  new Utf8_obj; }
hx::ObjectPtr< Utf8_obj > Utf8_obj::__new(Dynamic size)
{  hx::ObjectPtr< Utf8_obj > _result_ = new Utf8_obj();
	_result_->__construct(size);
	return _result_;}

Dynamic Utf8_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Utf8_obj > _result_ = new Utf8_obj();
	_result_->__construct(inArgs[0]);
	return _result_;}

Void Utf8_obj::addChar( int c){
{
		HX_STACK_FRAME("haxe.Utf8","addChar",0x9a1816c2,"haxe.Utf8.addChar","C:\\HaxeToolkit\\haxe\\std/cpp/_std/haxe/Utf8.hx",35,0xf320feca)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(36)
		int tmp = c;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(36)
		this->__s->push(tmp);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Utf8_obj,addChar,(void))

::String Utf8_obj::toString( ){
	HX_STACK_FRAME("haxe.Utf8","toString",0xb459e121,"haxe.Utf8.toString","C:\\HaxeToolkit\\haxe\\std/cpp/_std/haxe/Utf8.hx",39,0xf320feca)
	HX_STACK_THIS(this)
	HX_STACK_LINE(40)
	::String tmp = ::__hxcpp_char_array_to_utf8_string(this->__s);		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(40)
	return tmp;
}


HX_DEFINE_DYNAMIC_FUNC0(Utf8_obj,toString,return )

Void Utf8_obj::iter( ::String s,Dynamic chars){
{
		HX_STACK_FRAME("haxe.Utf8","iter",0x67f2370d,"haxe.Utf8.iter","C:\\HaxeToolkit\\haxe\\std/cpp/_std/haxe/Utf8.hx",55,0xf320feca)
		HX_STACK_ARG(s,"s")
		HX_STACK_ARG(chars,"chars")
		HX_STACK_LINE(56)
		Array< int > array = ::__hxcpp_utf8_string_to_char_array(s);		HX_STACK_VAR(array,"array");
		HX_STACK_LINE(57)
		{
			HX_STACK_LINE(57)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(57)
			while((true)){
				HX_STACK_LINE(57)
				bool tmp = (_g < array->length);		HX_STACK_VAR(tmp,"tmp");
				HX_STACK_LINE(57)
				bool tmp1 = !(tmp);		HX_STACK_VAR(tmp1,"tmp1");
				HX_STACK_LINE(57)
				if ((tmp1)){
					HX_STACK_LINE(57)
					break;
				}
				HX_STACK_LINE(57)
				int tmp2 = array->__get(_g);		HX_STACK_VAR(tmp2,"tmp2");
				HX_STACK_LINE(57)
				int a = tmp2;		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(57)
				++(_g);
				HX_STACK_LINE(58)
				int tmp3 = a;		HX_STACK_VAR(tmp3,"tmp3");
				HX_STACK_LINE(58)
				chars(tmp3).Cast< Void >();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Utf8_obj,iter,(void))

int Utf8_obj::length( ::String s){
	HX_STACK_FRAME("haxe.Utf8","length",0x88322e1b,"haxe.Utf8.length","C:\\HaxeToolkit\\haxe\\std/cpp/_std/haxe/Utf8.hx",74,0xf320feca)
	HX_STACK_ARG(s,"s")
	HX_STACK_LINE(75)
	Array< int > array = ::__hxcpp_utf8_string_to_char_array(s);		HX_STACK_VAR(array,"array");
	HX_STACK_LINE(76)
	int tmp = array->length;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(76)
	return tmp;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Utf8_obj,length,return )


Utf8_obj::Utf8_obj()
{
}

void Utf8_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Utf8);
	HX_MARK_MEMBER_NAME(__s,"__s");
	HX_MARK_END_CLASS();
}

void Utf8_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__s,"__s");
}

Dynamic Utf8_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__s") ) { return __s; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"addChar") ) { return addChar_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

bool Utf8_obj::__GetStatic(const ::String &inName, Dynamic &outValue, hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"iter") ) { outValue = iter_dyn(); return true;  }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { outValue = length_dyn(); return true;  }
	}
	return false;
}

Dynamic Utf8_obj::__SetField(const ::String &inName,const Dynamic &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__s") ) { __s=inValue.Cast< Array< int > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool Utf8_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,hx::PropertyAccess inCallProp)
{
	return false;
}

void Utf8_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("__s","\x53","\x69","\x48","\x00"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(Utf8_obj,__s),HX_HCSTRING("__s","\x53","\x69","\x48","\x00")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("__s","\x53","\x69","\x48","\x00"),
	HX_HCSTRING("addChar","\x97","\xa1","\xfc","\x7d"),
	HX_HCSTRING("toString","\xac","\xd0","\x6e","\x38"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Utf8_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Utf8_obj::__mClass,"__mClass");
};

#endif

hx::Class Utf8_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("iter","\x18","\xc5","\xbf","\x45"),
	HX_HCSTRING("length","\xe6","\x94","\x07","\x9f"),
	::String(null()) };

void Utf8_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("haxe.Utf8","\x99","\x32","\x41","\xf3");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Utf8_obj::__GetStatic;
	__mClass->mSetStaticField = &Utf8_obj::__SetStatic;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(sStaticFields);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< Utf8_obj >;
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

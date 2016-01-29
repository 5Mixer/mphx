#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif

Void Std_obj::__construct()
{
	return null();
}

//Std_obj::~Std_obj() { }

Dynamic Std_obj::__CreateEmpty() { return  new Std_obj; }
hx::ObjectPtr< Std_obj > Std_obj::__new()
{  hx::ObjectPtr< Std_obj > _result_ = new Std_obj();
	_result_->__construct();
	return _result_;}

Dynamic Std_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Std_obj > _result_ = new Std_obj();
	_result_->__construct();
	return _result_;}

bool Std_obj::is( Dynamic v,Dynamic t){
	HX_STACK_FRAME("Std","is",0x3c56d6f5,"Std.is","C:\\HaxeToolkit\\haxe\\std/cpp/_std/Std.hx",23,0x6cd09c81)
	HX_STACK_ARG(v,"v")
	HX_STACK_ARG(t,"t")
	HX_STACK_LINE(24)
	bool tmp = ::__instanceof(v,t);		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(24)
	return tmp;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Std_obj,is,return )

Dynamic Std_obj::instance( Dynamic value,::hx::Class c){
	HX_STACK_FRAME("Std","instance",0x1431f4e0,"Std.instance","C:\\HaxeToolkit\\haxe\\std/cpp/_std/Std.hx",27,0x6cd09c81)
	HX_STACK_ARG(value,"value")
	HX_STACK_ARG(c,"c")
	HX_STACK_LINE(28)
	Dynamic tmp = value;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(28)
	::hx::Class tmp1 = c;		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(28)
	bool tmp2 = ::Std_obj::is(tmp,tmp1);		HX_STACK_VAR(tmp2,"tmp2");
	HX_STACK_LINE(28)
	Dynamic tmp3;		HX_STACK_VAR(tmp3,"tmp3");
	HX_STACK_LINE(28)
	if ((tmp2)){
		HX_STACK_LINE(28)
		tmp3 = value;
	}
	else{
		HX_STACK_LINE(28)
		tmp3 = null();
	}
	HX_STACK_LINE(28)
	return tmp3;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Std_obj,instance,return )

::String Std_obj::string( Dynamic s){
	HX_STACK_FRAME("Std","string",0xcf48855c,"Std.string","C:\\HaxeToolkit\\haxe\\std/cpp/_std/Std.hx",31,0x6cd09c81)
	HX_STACK_ARG(s,"s")
	HX_STACK_LINE(32)
	bool tmp = (s == null());		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(32)
	::String tmp1;		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(32)
	if ((tmp)){
		HX_STACK_LINE(32)
		tmp1 = HX_HCSTRING("null","\x87","\x9e","\x0e","\x49");
	}
	else{
		HX_STACK_LINE(32)
		tmp1 = s->toString();
	}
	HX_STACK_LINE(32)
	return tmp1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Std_obj,string,return )

int Std_obj::_int( Float x){
	HX_STACK_FRAME("Std","int",0x8fa53b84,"Std.int","C:\\HaxeToolkit\\haxe\\std/cpp/_std/Std.hx",35,0x6cd09c81)
	HX_STACK_ARG(x,"x")
	HX_STACK_LINE(36)
	int tmp = ::__int__(x);		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(36)
	return tmp;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Std_obj,_int,return )

Dynamic Std_obj::parseInt( ::String x){
	HX_STACK_FRAME("Std","parseInt",0x90c2ebc7,"Std.parseInt","C:\\HaxeToolkit\\haxe\\std/cpp/_std/Std.hx",39,0x6cd09c81)
	HX_STACK_ARG(x,"x")
	HX_STACK_LINE(40)
	Dynamic tmp = ::__hxcpp_parse_int(x);		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(40)
	return tmp;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Std_obj,parseInt,return )

Float Std_obj::parseFloat( ::String x){
	HX_STACK_FRAME("Std","parseFloat",0xbca10a74,"Std.parseFloat","C:\\HaxeToolkit\\haxe\\std/cpp/_std/Std.hx",43,0x6cd09c81)
	HX_STACK_ARG(x,"x")
	HX_STACK_LINE(44)
	Float tmp = ::__hxcpp_parse_float(x);		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(44)
	return tmp;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Std_obj,parseFloat,return )

int Std_obj::random( int x){
	HX_STACK_FRAME("Std","random",0x75a77e8e,"Std.random","C:\\HaxeToolkit\\haxe\\std/cpp/_std/Std.hx",47,0x6cd09c81)
	HX_STACK_ARG(x,"x")
	HX_STACK_LINE(48)
	bool tmp = (x <= (int)0);		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(48)
	if ((tmp)){
		HX_STACK_LINE(48)
		return (int)0;
	}
	HX_STACK_LINE(49)
	int tmp1 = ::__hxcpp_irand(x);		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(49)
	return tmp1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Std_obj,random,return )


Std_obj::Std_obj()
{
}

bool Std_obj::__GetStatic(const ::String &inName, Dynamic &outValue, hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"is") ) { outValue = is_dyn(); return true;  }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"int") ) { outValue = _int_dyn(); return true;  }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"string") ) { outValue = string_dyn(); return true;  }
		if (HX_FIELD_EQ(inName,"random") ) { outValue = random_dyn(); return true;  }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"instance") ) { outValue = instance_dyn(); return true;  }
		if (HX_FIELD_EQ(inName,"parseInt") ) { outValue = parseInt_dyn(); return true;  }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"parseFloat") ) { outValue = parseFloat_dyn(); return true;  }
	}
	return false;
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Std_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Std_obj::__mClass,"__mClass");
};

#endif

hx::Class Std_obj::__mClass;

static ::String sStaticFields[] = {
	HX_HCSTRING("is","\xea","\x5b","\x00","\x00"),
	HX_HCSTRING("instance","\x95","\x1f","\xe1","\x59"),
	HX_HCSTRING("string","\xd1","\x28","\x30","\x11"),
	HX_HCSTRING("int","\xef","\x0c","\x50","\x00"),
	HX_HCSTRING("parseInt","\x7c","\x16","\x72","\xd6"),
	HX_HCSTRING("parseFloat","\x69","\x0c","\x78","\x2c"),
	HX_HCSTRING("random","\x03","\x22","\x8f","\xb7"),
	::String(null()) };

void Std_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("Std","\x83","\x60","\x3f","\x00");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Std_obj::__GetStatic;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(sStaticFields);
	__mClass->mMembers = hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = hx::TCanCast< Std_obj >;
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


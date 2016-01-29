#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_haxe_format_JsonParser
#include <haxe/format/JsonParser.h>
#endif
namespace haxe{
namespace format{

Void JsonParser_obj::__construct(::String str)
{
HX_STACK_FRAME("haxe.format.JsonParser","new",0xa017eec8,"haxe.format.JsonParser.new","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonParser.hx",49,0x53425a8f)
HX_STACK_THIS(this)
HX_STACK_ARG(str,"str")
{
	HX_STACK_LINE(50)
	this->str = str;
	HX_STACK_LINE(51)
	this->pos = (int)0;
}
;
	return null();
}

//JsonParser_obj::~JsonParser_obj() { }

Dynamic JsonParser_obj::__CreateEmpty() { return  new JsonParser_obj; }
hx::ObjectPtr< JsonParser_obj > JsonParser_obj::__new(::String str)
{  hx::ObjectPtr< JsonParser_obj > _result_ = new JsonParser_obj();
	_result_->__construct(str);
	return _result_;}

Dynamic JsonParser_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< JsonParser_obj > _result_ = new JsonParser_obj();
	_result_->__construct(inArgs[0]);
	return _result_;}

Dynamic JsonParser_obj::parseRec( ){
	HX_STACK_FRAME("haxe.format.JsonParser","parseRec",0xda258b75,"haxe.format.JsonParser.parseRec","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonParser.hx",55,0x53425a8f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(55)
	while((true)){
		HX_STACK_LINE(56)
		int tmp;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(56)
		{
			HX_STACK_LINE(56)
			int tmp1 = (this->pos)++;		HX_STACK_VAR(tmp1,"tmp1");
			HX_STACK_LINE(56)
			int index = tmp1;		HX_STACK_VAR(index,"index");
			HX_STACK_LINE(56)
			::String tmp2 = this->str;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(56)
			int tmp3 = index;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(56)
			tmp = tmp2.cca(tmp3);
		}
		HX_STACK_LINE(56)
		int c = tmp;		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(57)
		int tmp1 = c;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(57)
		switch( (int)(tmp1)){
			case (int)32: case (int)13: case (int)10: case (int)9: {
			}
			;break;
			case (int)123: {
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonParser.hx",61,0x53425a8f)
						{
							hx::Anon __result = hx::Anon_obj::Create();
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(61)
				Dynamic tmp2 = _Function_3_1::Block();		HX_STACK_VAR(tmp2,"tmp2");
				HX_STACK_LINE(61)
				Dynamic obj = tmp2;		HX_STACK_VAR(obj,"obj");
				HX_STACK_LINE(61)
				::String field = null();		HX_STACK_VAR(field,"field");
				HX_STACK_LINE(61)
				Dynamic comma = null();		HX_STACK_VAR(comma,"comma");
				HX_STACK_LINE(62)
				while((true)){
					HX_STACK_LINE(63)
					int tmp3;		HX_STACK_VAR(tmp3,"tmp3");
					HX_STACK_LINE(63)
					{
						HX_STACK_LINE(63)
						int tmp4 = (this->pos)++;		HX_STACK_VAR(tmp4,"tmp4");
						HX_STACK_LINE(63)
						int index = tmp4;		HX_STACK_VAR(index,"index");
						HX_STACK_LINE(63)
						::String tmp5 = this->str;		HX_STACK_VAR(tmp5,"tmp5");
						HX_STACK_LINE(63)
						int tmp6 = index;		HX_STACK_VAR(tmp6,"tmp6");
						HX_STACK_LINE(63)
						tmp3 = tmp5.cca(tmp6);
					}
					HX_STACK_LINE(63)
					int c1 = tmp3;		HX_STACK_VAR(c1,"c1");
					HX_STACK_LINE(64)
					int tmp4 = c1;		HX_STACK_VAR(tmp4,"tmp4");
					HX_STACK_LINE(64)
					switch( (int)(tmp4)){
						case (int)32: case (int)13: case (int)10: case (int)9: {
						}
						;break;
						case (int)125: {
							HX_STACK_LINE(68)
							bool tmp5 = (field != null());		HX_STACK_VAR(tmp5,"tmp5");
							HX_STACK_LINE(68)
							bool tmp6 = !(tmp5);		HX_STACK_VAR(tmp6,"tmp6");
							HX_STACK_LINE(68)
							bool tmp7;		HX_STACK_VAR(tmp7,"tmp7");
							HX_STACK_LINE(68)
							if ((tmp6)){
								HX_STACK_LINE(68)
								tmp7 = (comma == false);
							}
							else{
								HX_STACK_LINE(68)
								tmp7 = true;
							}
							HX_STACK_LINE(68)
							if ((tmp7)){
								HX_STACK_LINE(69)
								this->invalidChar();
							}
							HX_STACK_LINE(70)
							Dynamic tmp8 = obj;		HX_STACK_VAR(tmp8,"tmp8");
							HX_STACK_LINE(70)
							return tmp8;
						}
						;break;
						case (int)58: {
							HX_STACK_LINE(72)
							bool tmp5 = (field == null());		HX_STACK_VAR(tmp5,"tmp5");
							HX_STACK_LINE(72)
							if ((tmp5)){
								HX_STACK_LINE(73)
								this->invalidChar();
							}
							HX_STACK_LINE(74)
							Dynamic tmp6 = obj;		HX_STACK_VAR(tmp6,"tmp6");
							HX_STACK_LINE(74)
							::String tmp7 = field;		HX_STACK_VAR(tmp7,"tmp7");
							HX_STACK_LINE(74)
							Dynamic tmp8 = this->parseRec();		HX_STACK_VAR(tmp8,"tmp8");
							HX_STACK_LINE(74)
							::Reflect_obj::setField(tmp6,tmp7,tmp8);
							HX_STACK_LINE(75)
							field = null();
							HX_STACK_LINE(76)
							comma = true;
						}
						;break;
						case (int)44: {
							HX_STACK_LINE(78)
							Dynamic tmp5 = comma;		HX_STACK_VAR(tmp5,"tmp5");
							HX_STACK_LINE(78)
							if ((tmp5)){
								HX_STACK_LINE(78)
								comma = false;
							}
							else{
								HX_STACK_LINE(78)
								this->invalidChar();
							}
						}
						;break;
						case (int)34: {
							HX_STACK_LINE(80)
							Dynamic tmp5 = comma;		HX_STACK_VAR(tmp5,"tmp5");
							HX_STACK_LINE(80)
							if ((tmp5)){
								HX_STACK_LINE(80)
								this->invalidChar();
							}
							HX_STACK_LINE(81)
							::String tmp6 = this->parseString();		HX_STACK_VAR(tmp6,"tmp6");
							HX_STACK_LINE(81)
							field = tmp6;
						}
						;break;
						default: {
							HX_STACK_LINE(83)
							this->invalidChar();
						}
					}
				}
			}
			;break;
			case (int)91: {
				HX_STACK_LINE(87)
				cpp::ArrayBase arr = cpp::ArrayBase_obj::__new();		HX_STACK_VAR(arr,"arr");
				HX_STACK_LINE(87)
				Dynamic comma = null();		HX_STACK_VAR(comma,"comma");
				HX_STACK_LINE(88)
				while((true)){
					HX_STACK_LINE(89)
					int tmp2;		HX_STACK_VAR(tmp2,"tmp2");
					HX_STACK_LINE(89)
					{
						HX_STACK_LINE(89)
						int tmp3 = (this->pos)++;		HX_STACK_VAR(tmp3,"tmp3");
						HX_STACK_LINE(89)
						int index = tmp3;		HX_STACK_VAR(index,"index");
						HX_STACK_LINE(89)
						::String tmp4 = this->str;		HX_STACK_VAR(tmp4,"tmp4");
						HX_STACK_LINE(89)
						int tmp5 = index;		HX_STACK_VAR(tmp5,"tmp5");
						HX_STACK_LINE(89)
						tmp2 = tmp4.cca(tmp5);
					}
					HX_STACK_LINE(89)
					int c1 = tmp2;		HX_STACK_VAR(c1,"c1");
					HX_STACK_LINE(90)
					int tmp3 = c1;		HX_STACK_VAR(tmp3,"tmp3");
					HX_STACK_LINE(90)
					switch( (int)(tmp3)){
						case (int)32: case (int)13: case (int)10: case (int)9: {
						}
						;break;
						case (int)93: {
							HX_STACK_LINE(94)
							bool tmp4 = (comma == false);		HX_STACK_VAR(tmp4,"tmp4");
							HX_STACK_LINE(94)
							if ((tmp4)){
								HX_STACK_LINE(94)
								this->invalidChar();
							}
							HX_STACK_LINE(95)
							return arr;
						}
						;break;
						case (int)44: {
							HX_STACK_LINE(97)
							Dynamic tmp4 = comma;		HX_STACK_VAR(tmp4,"tmp4");
							HX_STACK_LINE(97)
							if ((tmp4)){
								HX_STACK_LINE(97)
								comma = false;
							}
							else{
								HX_STACK_LINE(97)
								this->invalidChar();
							}
						}
						;break;
						default: {
							HX_STACK_LINE(99)
							Dynamic tmp4 = comma;		HX_STACK_VAR(tmp4,"tmp4");
							HX_STACK_LINE(99)
							if ((tmp4)){
								HX_STACK_LINE(99)
								this->invalidChar();
							}
							HX_STACK_LINE(100)
							(this->pos)--;
							HX_STACK_LINE(101)
							Dynamic tmp5 = this->parseRec();		HX_STACK_VAR(tmp5,"tmp5");
							HX_STACK_LINE(101)
							arr->__Field(HX_HCSTRING("push","\xda","\x11","\x61","\x4a"), hx::paccDynamic )(tmp5);
							HX_STACK_LINE(102)
							comma = true;
						}
					}
				}
			}
			;break;
			case (int)116: {
				HX_STACK_LINE(106)
				int tmp2 = this->pos;		HX_STACK_VAR(tmp2,"tmp2");
				HX_STACK_LINE(106)
				int save = tmp2;		HX_STACK_VAR(save,"save");
				HX_STACK_LINE(107)
				int tmp3;		HX_STACK_VAR(tmp3,"tmp3");
				HX_STACK_LINE(107)
				{
					HX_STACK_LINE(107)
					int tmp4 = (this->pos)++;		HX_STACK_VAR(tmp4,"tmp4");
					HX_STACK_LINE(107)
					int index = tmp4;		HX_STACK_VAR(index,"index");
					HX_STACK_LINE(107)
					::String tmp5 = this->str;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(107)
					int tmp6 = index;		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(107)
					tmp3 = tmp5.cca(tmp6);
				}
				HX_STACK_LINE(107)
				bool tmp4 = (tmp3 != (int)114);		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(107)
				bool tmp5 = !(tmp4);		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(107)
				bool tmp6 = tmp5;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(107)
				bool tmp7;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(107)
				if ((tmp6)){
					HX_STACK_LINE(107)
					int tmp8;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(107)
					{
						HX_STACK_LINE(107)
						int tmp9 = (this->pos)++;		HX_STACK_VAR(tmp9,"tmp9");
						HX_STACK_LINE(107)
						int tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(107)
						int tmp11 = tmp10;		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(107)
						int index = tmp11;		HX_STACK_VAR(index,"index");
						HX_STACK_LINE(107)
						::String tmp12 = this->str;		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(107)
						::String tmp13 = tmp12;		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(107)
						::String tmp14 = tmp13;		HX_STACK_VAR(tmp14,"tmp14");
						HX_STACK_LINE(107)
						int tmp15 = index;		HX_STACK_VAR(tmp15,"tmp15");
						HX_STACK_LINE(107)
						int tmp16 = tmp15;		HX_STACK_VAR(tmp16,"tmp16");
						HX_STACK_LINE(107)
						int tmp17 = tmp16;		HX_STACK_VAR(tmp17,"tmp17");
						HX_STACK_LINE(107)
						int tmp18 = tmp14.cca(tmp17);		HX_STACK_VAR(tmp18,"tmp18");
						HX_STACK_LINE(107)
						int tmp19 = tmp18;		HX_STACK_VAR(tmp19,"tmp19");
						HX_STACK_LINE(107)
						tmp8 = tmp19;
					}
					HX_STACK_LINE(107)
					tmp7 = (tmp8 != (int)117);
				}
				else{
					HX_STACK_LINE(107)
					tmp7 = true;
				}
				HX_STACK_LINE(107)
				bool tmp8 = !(tmp7);		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(107)
				bool tmp9;		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(107)
				if ((tmp8)){
					HX_STACK_LINE(107)
					int tmp10;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(107)
					{
						HX_STACK_LINE(107)
						int tmp11 = (this->pos)++;		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(107)
						int tmp12 = tmp11;		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(107)
						int index = tmp12;		HX_STACK_VAR(index,"index");
						HX_STACK_LINE(107)
						::String tmp13 = this->str;		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(107)
						::String tmp14 = tmp13;		HX_STACK_VAR(tmp14,"tmp14");
						HX_STACK_LINE(107)
						int tmp15 = index;		HX_STACK_VAR(tmp15,"tmp15");
						HX_STACK_LINE(107)
						int tmp16 = tmp15;		HX_STACK_VAR(tmp16,"tmp16");
						HX_STACK_LINE(107)
						int tmp17 = tmp14.cca(tmp16);		HX_STACK_VAR(tmp17,"tmp17");
						HX_STACK_LINE(107)
						tmp10 = tmp17;
					}
					HX_STACK_LINE(107)
					tmp9 = (tmp10 != (int)101);
				}
				else{
					HX_STACK_LINE(107)
					tmp9 = true;
				}
				HX_STACK_LINE(107)
				if ((tmp9)){
					HX_STACK_LINE(108)
					this->pos = save;
					HX_STACK_LINE(109)
					this->invalidChar();
				}
				HX_STACK_LINE(111)
				return true;
			}
			;break;
			case (int)102: {
				HX_STACK_LINE(113)
				int tmp2 = this->pos;		HX_STACK_VAR(tmp2,"tmp2");
				HX_STACK_LINE(113)
				int save = tmp2;		HX_STACK_VAR(save,"save");
				HX_STACK_LINE(114)
				int tmp3;		HX_STACK_VAR(tmp3,"tmp3");
				HX_STACK_LINE(114)
				{
					HX_STACK_LINE(114)
					int tmp4 = (this->pos)++;		HX_STACK_VAR(tmp4,"tmp4");
					HX_STACK_LINE(114)
					int index = tmp4;		HX_STACK_VAR(index,"index");
					HX_STACK_LINE(114)
					::String tmp5 = this->str;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(114)
					int tmp6 = index;		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(114)
					tmp3 = tmp5.cca(tmp6);
				}
				HX_STACK_LINE(114)
				bool tmp4 = (tmp3 != (int)97);		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(114)
				bool tmp5 = !(tmp4);		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(114)
				bool tmp6 = tmp5;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(114)
				bool tmp7;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(114)
				if ((tmp6)){
					HX_STACK_LINE(114)
					int tmp8;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(114)
					{
						HX_STACK_LINE(114)
						int tmp9 = (this->pos)++;		HX_STACK_VAR(tmp9,"tmp9");
						HX_STACK_LINE(114)
						int tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(114)
						int tmp11 = tmp10;		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(114)
						int index = tmp11;		HX_STACK_VAR(index,"index");
						HX_STACK_LINE(114)
						::String tmp12 = this->str;		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(114)
						::String tmp13 = tmp12;		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(114)
						::String tmp14 = tmp13;		HX_STACK_VAR(tmp14,"tmp14");
						HX_STACK_LINE(114)
						int tmp15 = index;		HX_STACK_VAR(tmp15,"tmp15");
						HX_STACK_LINE(114)
						int tmp16 = tmp15;		HX_STACK_VAR(tmp16,"tmp16");
						HX_STACK_LINE(114)
						int tmp17 = tmp16;		HX_STACK_VAR(tmp17,"tmp17");
						HX_STACK_LINE(114)
						int tmp18 = tmp14.cca(tmp17);		HX_STACK_VAR(tmp18,"tmp18");
						HX_STACK_LINE(114)
						int tmp19 = tmp18;		HX_STACK_VAR(tmp19,"tmp19");
						HX_STACK_LINE(114)
						tmp8 = tmp19;
					}
					HX_STACK_LINE(114)
					tmp7 = (tmp8 != (int)108);
				}
				else{
					HX_STACK_LINE(114)
					tmp7 = true;
				}
				HX_STACK_LINE(114)
				bool tmp8 = !(tmp7);		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(114)
				bool tmp9 = tmp8;		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(114)
				bool tmp10;		HX_STACK_VAR(tmp10,"tmp10");
				HX_STACK_LINE(114)
				if ((tmp9)){
					HX_STACK_LINE(114)
					int tmp11;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(114)
					{
						HX_STACK_LINE(114)
						int tmp12 = (this->pos)++;		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(114)
						int tmp13 = tmp12;		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(114)
						int tmp14 = tmp13;		HX_STACK_VAR(tmp14,"tmp14");
						HX_STACK_LINE(114)
						int index = tmp14;		HX_STACK_VAR(index,"index");
						HX_STACK_LINE(114)
						::String tmp15 = this->str;		HX_STACK_VAR(tmp15,"tmp15");
						HX_STACK_LINE(114)
						::String tmp16 = tmp15;		HX_STACK_VAR(tmp16,"tmp16");
						HX_STACK_LINE(114)
						::String tmp17 = tmp16;		HX_STACK_VAR(tmp17,"tmp17");
						HX_STACK_LINE(114)
						int tmp18 = index;		HX_STACK_VAR(tmp18,"tmp18");
						HX_STACK_LINE(114)
						int tmp19 = tmp18;		HX_STACK_VAR(tmp19,"tmp19");
						HX_STACK_LINE(114)
						int tmp20 = tmp19;		HX_STACK_VAR(tmp20,"tmp20");
						HX_STACK_LINE(114)
						int tmp21 = tmp17.cca(tmp20);		HX_STACK_VAR(tmp21,"tmp21");
						HX_STACK_LINE(114)
						int tmp22 = tmp21;		HX_STACK_VAR(tmp22,"tmp22");
						HX_STACK_LINE(114)
						tmp11 = tmp22;
					}
					HX_STACK_LINE(114)
					tmp10 = (tmp11 != (int)115);
				}
				else{
					HX_STACK_LINE(114)
					tmp10 = true;
				}
				HX_STACK_LINE(114)
				bool tmp11 = !(tmp10);		HX_STACK_VAR(tmp11,"tmp11");
				HX_STACK_LINE(114)
				bool tmp12;		HX_STACK_VAR(tmp12,"tmp12");
				HX_STACK_LINE(114)
				if ((tmp11)){
					HX_STACK_LINE(114)
					int tmp13;		HX_STACK_VAR(tmp13,"tmp13");
					HX_STACK_LINE(114)
					{
						HX_STACK_LINE(114)
						int tmp14 = (this->pos)++;		HX_STACK_VAR(tmp14,"tmp14");
						HX_STACK_LINE(114)
						int tmp15 = tmp14;		HX_STACK_VAR(tmp15,"tmp15");
						HX_STACK_LINE(114)
						int index = tmp15;		HX_STACK_VAR(index,"index");
						HX_STACK_LINE(114)
						::String tmp16 = this->str;		HX_STACK_VAR(tmp16,"tmp16");
						HX_STACK_LINE(114)
						::String tmp17 = tmp16;		HX_STACK_VAR(tmp17,"tmp17");
						HX_STACK_LINE(114)
						int tmp18 = index;		HX_STACK_VAR(tmp18,"tmp18");
						HX_STACK_LINE(114)
						int tmp19 = tmp18;		HX_STACK_VAR(tmp19,"tmp19");
						HX_STACK_LINE(114)
						int tmp20 = tmp17.cca(tmp19);		HX_STACK_VAR(tmp20,"tmp20");
						HX_STACK_LINE(114)
						tmp13 = tmp20;
					}
					HX_STACK_LINE(114)
					tmp12 = (tmp13 != (int)101);
				}
				else{
					HX_STACK_LINE(114)
					tmp12 = true;
				}
				HX_STACK_LINE(114)
				if ((tmp12)){
					HX_STACK_LINE(115)
					this->pos = save;
					HX_STACK_LINE(116)
					this->invalidChar();
				}
				HX_STACK_LINE(118)
				return false;
			}
			;break;
			case (int)110: {
				HX_STACK_LINE(120)
				int tmp2 = this->pos;		HX_STACK_VAR(tmp2,"tmp2");
				HX_STACK_LINE(120)
				int save = tmp2;		HX_STACK_VAR(save,"save");
				HX_STACK_LINE(121)
				int tmp3;		HX_STACK_VAR(tmp3,"tmp3");
				HX_STACK_LINE(121)
				{
					HX_STACK_LINE(121)
					int tmp4 = (this->pos)++;		HX_STACK_VAR(tmp4,"tmp4");
					HX_STACK_LINE(121)
					int index = tmp4;		HX_STACK_VAR(index,"index");
					HX_STACK_LINE(121)
					::String tmp5 = this->str;		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(121)
					int tmp6 = index;		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(121)
					tmp3 = tmp5.cca(tmp6);
				}
				HX_STACK_LINE(121)
				bool tmp4 = (tmp3 != (int)117);		HX_STACK_VAR(tmp4,"tmp4");
				HX_STACK_LINE(121)
				bool tmp5 = !(tmp4);		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(121)
				bool tmp6 = tmp5;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(121)
				bool tmp7;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(121)
				if ((tmp6)){
					HX_STACK_LINE(121)
					int tmp8;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(121)
					{
						HX_STACK_LINE(121)
						int tmp9 = (this->pos)++;		HX_STACK_VAR(tmp9,"tmp9");
						HX_STACK_LINE(121)
						int tmp10 = tmp9;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(121)
						int tmp11 = tmp10;		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(121)
						int index = tmp11;		HX_STACK_VAR(index,"index");
						HX_STACK_LINE(121)
						::String tmp12 = this->str;		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(121)
						::String tmp13 = tmp12;		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(121)
						::String tmp14 = tmp13;		HX_STACK_VAR(tmp14,"tmp14");
						HX_STACK_LINE(121)
						int tmp15 = index;		HX_STACK_VAR(tmp15,"tmp15");
						HX_STACK_LINE(121)
						int tmp16 = tmp15;		HX_STACK_VAR(tmp16,"tmp16");
						HX_STACK_LINE(121)
						int tmp17 = tmp16;		HX_STACK_VAR(tmp17,"tmp17");
						HX_STACK_LINE(121)
						int tmp18 = tmp14.cca(tmp17);		HX_STACK_VAR(tmp18,"tmp18");
						HX_STACK_LINE(121)
						int tmp19 = tmp18;		HX_STACK_VAR(tmp19,"tmp19");
						HX_STACK_LINE(121)
						tmp8 = tmp19;
					}
					HX_STACK_LINE(121)
					tmp7 = (tmp8 != (int)108);
				}
				else{
					HX_STACK_LINE(121)
					tmp7 = true;
				}
				HX_STACK_LINE(121)
				bool tmp8 = !(tmp7);		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(121)
				bool tmp9;		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(121)
				if ((tmp8)){
					HX_STACK_LINE(121)
					int tmp10;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(121)
					{
						HX_STACK_LINE(121)
						int tmp11 = (this->pos)++;		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(121)
						int tmp12 = tmp11;		HX_STACK_VAR(tmp12,"tmp12");
						HX_STACK_LINE(121)
						int index = tmp12;		HX_STACK_VAR(index,"index");
						HX_STACK_LINE(121)
						::String tmp13 = this->str;		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(121)
						::String tmp14 = tmp13;		HX_STACK_VAR(tmp14,"tmp14");
						HX_STACK_LINE(121)
						int tmp15 = index;		HX_STACK_VAR(tmp15,"tmp15");
						HX_STACK_LINE(121)
						int tmp16 = tmp15;		HX_STACK_VAR(tmp16,"tmp16");
						HX_STACK_LINE(121)
						int tmp17 = tmp14.cca(tmp16);		HX_STACK_VAR(tmp17,"tmp17");
						HX_STACK_LINE(121)
						tmp10 = tmp17;
					}
					HX_STACK_LINE(121)
					tmp9 = (tmp10 != (int)108);
				}
				else{
					HX_STACK_LINE(121)
					tmp9 = true;
				}
				HX_STACK_LINE(121)
				if ((tmp9)){
					HX_STACK_LINE(122)
					this->pos = save;
					HX_STACK_LINE(123)
					this->invalidChar();
				}
				HX_STACK_LINE(125)
				return null();
			}
			;break;
			case (int)34: {
				HX_STACK_LINE(127)
				::String tmp2 = this->parseString();		HX_STACK_VAR(tmp2,"tmp2");
				HX_STACK_LINE(127)
				return tmp2;
			}
			;break;
			case (int)48: case (int)49: case (int)50: case (int)51: case (int)52: case (int)53: case (int)54: case (int)55: case (int)56: case (int)57: case (int)45: {
				HX_STACK_LINE(129)
				Dynamic tmp2;		HX_STACK_VAR(tmp2,"tmp2");
				HX_STACK_LINE(129)
				{
					HX_STACK_LINE(129)
					int c1 = c;		HX_STACK_VAR(c1,"c1");
					HX_STACK_LINE(129)
					int tmp3 = this->pos;		HX_STACK_VAR(tmp3,"tmp3");
					HX_STACK_LINE(129)
					int tmp4 = (tmp3 - (int)1);		HX_STACK_VAR(tmp4,"tmp4");
					HX_STACK_LINE(129)
					int start = tmp4;		HX_STACK_VAR(start,"start");
					HX_STACK_LINE(129)
					bool tmp5 = (c1 == (int)45);		HX_STACK_VAR(tmp5,"tmp5");
					HX_STACK_LINE(129)
					bool minus = tmp5;		HX_STACK_VAR(minus,"minus");
					HX_STACK_LINE(129)
					bool tmp6 = minus;		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(129)
					bool tmp7 = !(tmp6);		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(129)
					bool digit = tmp7;		HX_STACK_VAR(digit,"digit");
					HX_STACK_LINE(129)
					bool tmp8 = (c1 == (int)48);		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(129)
					bool zero = tmp8;		HX_STACK_VAR(zero,"zero");
					HX_STACK_LINE(129)
					bool point = false;		HX_STACK_VAR(point,"point");
					HX_STACK_LINE(129)
					bool e = false;		HX_STACK_VAR(e,"e");
					HX_STACK_LINE(129)
					bool pm = false;		HX_STACK_VAR(pm,"pm");
					HX_STACK_LINE(129)
					bool end = false;		HX_STACK_VAR(end,"end");
					HX_STACK_LINE(129)
					while((true)){
						HX_STACK_LINE(129)
						int tmp9;		HX_STACK_VAR(tmp9,"tmp9");
						HX_STACK_LINE(129)
						{
							HX_STACK_LINE(129)
							int tmp10 = (this->pos)++;		HX_STACK_VAR(tmp10,"tmp10");
							HX_STACK_LINE(129)
							int index = tmp10;		HX_STACK_VAR(index,"index");
							HX_STACK_LINE(129)
							::String tmp11 = this->str;		HX_STACK_VAR(tmp11,"tmp11");
							HX_STACK_LINE(129)
							int tmp12 = index;		HX_STACK_VAR(tmp12,"tmp12");
							HX_STACK_LINE(129)
							tmp9 = tmp11.cca(tmp12);
						}
						HX_STACK_LINE(129)
						c1 = tmp9;
						HX_STACK_LINE(129)
						int tmp10 = c1;		HX_STACK_VAR(tmp10,"tmp10");
						HX_STACK_LINE(129)
						switch( (int)(tmp10)){
							case (int)48: {
								HX_STACK_LINE(129)
								bool tmp11 = zero;		HX_STACK_VAR(tmp11,"tmp11");
								HX_STACK_LINE(129)
								bool tmp12;		HX_STACK_VAR(tmp12,"tmp12");
								HX_STACK_LINE(129)
								if ((tmp11)){
									HX_STACK_LINE(129)
									bool tmp13 = point;		HX_STACK_VAR(tmp13,"tmp13");
									HX_STACK_LINE(129)
									bool tmp14 = tmp13;		HX_STACK_VAR(tmp14,"tmp14");
									HX_STACK_LINE(129)
									tmp12 = !(tmp14);
								}
								else{
									HX_STACK_LINE(129)
									tmp12 = false;
								}
								HX_STACK_LINE(129)
								if ((tmp12)){
									HX_STACK_LINE(129)
									int tmp13 = start;		HX_STACK_VAR(tmp13,"tmp13");
									HX_STACK_LINE(129)
									this->invalidNumber(tmp13);
								}
								HX_STACK_LINE(129)
								bool tmp13 = minus;		HX_STACK_VAR(tmp13,"tmp13");
								HX_STACK_LINE(129)
								if ((tmp13)){
									HX_STACK_LINE(129)
									minus = false;
									HX_STACK_LINE(129)
									zero = true;
								}
								HX_STACK_LINE(129)
								digit = true;
							}
							;break;
							case (int)49: case (int)50: case (int)51: case (int)52: case (int)53: case (int)54: case (int)55: case (int)56: case (int)57: {
								HX_STACK_LINE(129)
								bool tmp11 = zero;		HX_STACK_VAR(tmp11,"tmp11");
								HX_STACK_LINE(129)
								bool tmp12;		HX_STACK_VAR(tmp12,"tmp12");
								HX_STACK_LINE(129)
								if ((tmp11)){
									HX_STACK_LINE(129)
									bool tmp13 = point;		HX_STACK_VAR(tmp13,"tmp13");
									HX_STACK_LINE(129)
									bool tmp14 = tmp13;		HX_STACK_VAR(tmp14,"tmp14");
									HX_STACK_LINE(129)
									tmp12 = !(tmp14);
								}
								else{
									HX_STACK_LINE(129)
									tmp12 = false;
								}
								HX_STACK_LINE(129)
								if ((tmp12)){
									HX_STACK_LINE(129)
									int tmp13 = start;		HX_STACK_VAR(tmp13,"tmp13");
									HX_STACK_LINE(129)
									this->invalidNumber(tmp13);
								}
								HX_STACK_LINE(129)
								bool tmp13 = minus;		HX_STACK_VAR(tmp13,"tmp13");
								HX_STACK_LINE(129)
								if ((tmp13)){
									HX_STACK_LINE(129)
									minus = false;
								}
								HX_STACK_LINE(129)
								digit = true;
								HX_STACK_LINE(129)
								zero = false;
							}
							;break;
							case (int)46: {
								HX_STACK_LINE(129)
								bool tmp11 = minus;		HX_STACK_VAR(tmp11,"tmp11");
								HX_STACK_LINE(129)
								bool tmp12 = !(tmp11);		HX_STACK_VAR(tmp12,"tmp12");
								HX_STACK_LINE(129)
								bool tmp13;		HX_STACK_VAR(tmp13,"tmp13");
								HX_STACK_LINE(129)
								if ((tmp12)){
									HX_STACK_LINE(129)
									tmp13 = point;
								}
								else{
									HX_STACK_LINE(129)
									tmp13 = true;
								}
								HX_STACK_LINE(129)
								if ((tmp13)){
									HX_STACK_LINE(129)
									int tmp14 = start;		HX_STACK_VAR(tmp14,"tmp14");
									HX_STACK_LINE(129)
									this->invalidNumber(tmp14);
								}
								HX_STACK_LINE(129)
								digit = false;
								HX_STACK_LINE(129)
								point = true;
							}
							;break;
							case (int)101: case (int)69: {
								HX_STACK_LINE(129)
								bool tmp11 = minus;		HX_STACK_VAR(tmp11,"tmp11");
								HX_STACK_LINE(129)
								bool tmp12 = !(tmp11);		HX_STACK_VAR(tmp12,"tmp12");
								HX_STACK_LINE(129)
								bool tmp13 = tmp12;		HX_STACK_VAR(tmp13,"tmp13");
								HX_STACK_LINE(129)
								bool tmp14;		HX_STACK_VAR(tmp14,"tmp14");
								HX_STACK_LINE(129)
								if ((tmp13)){
									HX_STACK_LINE(129)
									tmp14 = zero;
								}
								else{
									HX_STACK_LINE(129)
									tmp14 = true;
								}
								HX_STACK_LINE(129)
								bool tmp15 = !(tmp14);		HX_STACK_VAR(tmp15,"tmp15");
								HX_STACK_LINE(129)
								bool tmp16;		HX_STACK_VAR(tmp16,"tmp16");
								HX_STACK_LINE(129)
								if ((tmp15)){
									HX_STACK_LINE(129)
									tmp16 = e;
								}
								else{
									HX_STACK_LINE(129)
									tmp16 = true;
								}
								HX_STACK_LINE(129)
								if ((tmp16)){
									HX_STACK_LINE(129)
									int tmp17 = start;		HX_STACK_VAR(tmp17,"tmp17");
									HX_STACK_LINE(129)
									this->invalidNumber(tmp17);
								}
								HX_STACK_LINE(129)
								digit = false;
								HX_STACK_LINE(129)
								e = true;
							}
							;break;
							case (int)43: case (int)45: {
								HX_STACK_LINE(129)
								bool tmp11 = e;		HX_STACK_VAR(tmp11,"tmp11");
								HX_STACK_LINE(129)
								bool tmp12 = tmp11;		HX_STACK_VAR(tmp12,"tmp12");
								HX_STACK_LINE(129)
								bool tmp13 = !(tmp12);		HX_STACK_VAR(tmp13,"tmp13");
								HX_STACK_LINE(129)
								bool tmp14 = !(tmp13);		HX_STACK_VAR(tmp14,"tmp14");
								HX_STACK_LINE(129)
								bool tmp15;		HX_STACK_VAR(tmp15,"tmp15");
								HX_STACK_LINE(129)
								if ((tmp14)){
									HX_STACK_LINE(129)
									tmp15 = pm;
								}
								else{
									HX_STACK_LINE(129)
									tmp15 = true;
								}
								HX_STACK_LINE(129)
								if ((tmp15)){
									HX_STACK_LINE(129)
									int tmp16 = start;		HX_STACK_VAR(tmp16,"tmp16");
									HX_STACK_LINE(129)
									this->invalidNumber(tmp16);
								}
								HX_STACK_LINE(129)
								digit = false;
								HX_STACK_LINE(129)
								pm = true;
							}
							;break;
							default: {
								HX_STACK_LINE(129)
								bool tmp11 = digit;		HX_STACK_VAR(tmp11,"tmp11");
								HX_STACK_LINE(129)
								bool tmp12 = !(tmp11);		HX_STACK_VAR(tmp12,"tmp12");
								HX_STACK_LINE(129)
								if ((tmp12)){
									HX_STACK_LINE(129)
									int tmp13 = start;		HX_STACK_VAR(tmp13,"tmp13");
									HX_STACK_LINE(129)
									this->invalidNumber(tmp13);
								}
								HX_STACK_LINE(129)
								(this->pos)--;
								HX_STACK_LINE(129)
								end = true;
							}
						}
						HX_STACK_LINE(129)
						bool tmp11 = end;		HX_STACK_VAR(tmp11,"tmp11");
						HX_STACK_LINE(129)
						if ((tmp11)){
							HX_STACK_LINE(129)
							break;
						}
					}
					HX_STACK_LINE(129)
					::String tmp9 = this->str;		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(129)
					int tmp10 = start;		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(129)
					int tmp11 = this->pos;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(129)
					int tmp12 = start;		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(129)
					int tmp13 = (tmp11 - tmp12);		HX_STACK_VAR(tmp13,"tmp13");
					HX_STACK_LINE(129)
					::String tmp14 = tmp9.substr(tmp10,tmp13);		HX_STACK_VAR(tmp14,"tmp14");
					HX_STACK_LINE(129)
					Float tmp15 = ::Std_obj::parseFloat(tmp14);		HX_STACK_VAR(tmp15,"tmp15");
					HX_STACK_LINE(129)
					Float f = tmp15;		HX_STACK_VAR(f,"f");
					HX_STACK_LINE(129)
					Float tmp16 = f;		HX_STACK_VAR(tmp16,"tmp16");
					HX_STACK_LINE(129)
					int tmp17 = ::Std_obj::_int(tmp16);		HX_STACK_VAR(tmp17,"tmp17");
					HX_STACK_LINE(129)
					int i = tmp17;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(129)
					bool tmp18 = (i == f);		HX_STACK_VAR(tmp18,"tmp18");
					HX_STACK_LINE(129)
					if ((tmp18)){
						HX_STACK_LINE(129)
						tmp2 = i;
					}
					else{
						HX_STACK_LINE(129)
						tmp2 = f;
					}
				}
				HX_STACK_LINE(129)
				return tmp2;
			}
			;break;
			default: {
				HX_STACK_LINE(131)
				this->invalidChar();
			}
		}
	}
	HX_STACK_LINE(55)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(JsonParser_obj,parseRec,return )

::String JsonParser_obj::parseString( ){
	HX_STACK_FRAME("haxe.format.JsonParser","parseString",0x8c919bcc,"haxe.format.JsonParser.parseString","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonParser.hx",136,0x53425a8f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(137)
	int tmp = this->pos;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(137)
	int start = tmp;		HX_STACK_VAR(start,"start");
	HX_STACK_LINE(138)
	::StringBuf buf = null();		HX_STACK_VAR(buf,"buf");
	HX_STACK_LINE(139)
	while((true)){
		HX_STACK_LINE(140)
		int tmp1;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(140)
		{
			HX_STACK_LINE(140)
			int tmp2 = (this->pos)++;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(140)
			int index = tmp2;		HX_STACK_VAR(index,"index");
			HX_STACK_LINE(140)
			::String tmp3 = this->str;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(140)
			int tmp4 = index;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(140)
			tmp1 = tmp3.cca(tmp4);
		}
		HX_STACK_LINE(140)
		int c = tmp1;		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(141)
		bool tmp2 = (c == (int)34);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(141)
		if ((tmp2)){
			HX_STACK_LINE(142)
			break;
		}
		HX_STACK_LINE(143)
		bool tmp3 = (c == (int)92);		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(143)
		if ((tmp3)){
			HX_STACK_LINE(144)
			bool tmp4 = (buf == null());		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(144)
			if ((tmp4)){
				HX_STACK_LINE(145)
				::StringBuf tmp5 = ::StringBuf_obj::__new();		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(145)
				buf = tmp5;
			}
			HX_STACK_LINE(147)
			{
				HX_STACK_LINE(147)
				::String tmp5 = this->str;		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(147)
				int tmp6 = start;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(147)
				int tmp7 = this->pos;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(147)
				int tmp8 = start;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(147)
				int tmp9 = (tmp7 - tmp8);		HX_STACK_VAR(tmp9,"tmp9");
				HX_STACK_LINE(147)
				int tmp10 = (tmp9 - (int)1);		HX_STACK_VAR(tmp10,"tmp10");
				HX_STACK_LINE(147)
				::String tmp11 = tmp5.substr(tmp6,tmp10);		HX_STACK_VAR(tmp11,"tmp11");
				HX_STACK_LINE(147)
				buf->b->push(tmp11);
			}
			HX_STACK_LINE(148)
			int tmp5;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(148)
			{
				HX_STACK_LINE(148)
				int tmp6 = (this->pos)++;		HX_STACK_VAR(tmp6,"tmp6");
				HX_STACK_LINE(148)
				int index = tmp6;		HX_STACK_VAR(index,"index");
				HX_STACK_LINE(148)
				::String tmp7 = this->str;		HX_STACK_VAR(tmp7,"tmp7");
				HX_STACK_LINE(148)
				int tmp8 = index;		HX_STACK_VAR(tmp8,"tmp8");
				HX_STACK_LINE(148)
				tmp5 = tmp7.cca(tmp8);
			}
			HX_STACK_LINE(148)
			c = tmp5;
			HX_STACK_LINE(149)
			int tmp6 = c;		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(149)
			switch( (int)(tmp6)){
				case (int)114: {
					HX_STACK_LINE(150)
					::String tmp7 = HX_HCSTRING("\r","\x0d","\x00","\x00","\x00");		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(150)
					buf->b->push(tmp7);
				}
				;break;
				case (int)110: {
					HX_STACK_LINE(151)
					::String tmp7 = HX_HCSTRING("\n","\x0a","\x00","\x00","\x00");		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(151)
					buf->b->push(tmp7);
				}
				;break;
				case (int)116: {
					HX_STACK_LINE(152)
					::String tmp7 = HX_HCSTRING("\t","\x09","\x00","\x00","\x00");		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(152)
					buf->b->push(tmp7);
				}
				;break;
				case (int)98: {
					HX_STACK_LINE(153)
					::String tmp7 = HX_HCSTRING("\x08""","\x08","\x00","\x00","\x00");		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(153)
					buf->b->push(tmp7);
				}
				;break;
				case (int)102: {
					HX_STACK_LINE(154)
					::String tmp7 = HX_HCSTRING("\x0c""","\x0c","\x00","\x00","\x00");		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(154)
					buf->b->push(tmp7);
				}
				;break;
				case (int)47: case (int)92: case (int)34: {
					HX_STACK_LINE(155)
					int tmp7 = c;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(155)
					::String tmp8 = ::String::fromCharCode(tmp7);		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(155)
					buf->b->push(tmp8);
				}
				;break;
				case (int)117: {
					HX_STACK_LINE(157)
					::String tmp7 = this->str;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(157)
					int tmp8 = this->pos;		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(157)
					::String tmp9 = tmp7.substr(tmp8,(int)4);		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(157)
					::String tmp10 = (HX_HCSTRING("0x","\x48","\x2a","\x00","\x00") + tmp9);		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(157)
					Dynamic tmp11 = ::Std_obj::parseInt(tmp10);		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(157)
					Dynamic uc = tmp11;		HX_STACK_VAR(uc,"uc");
					HX_STACK_LINE(158)
					hx::AddEq(this->pos,(int)4);
					HX_STACK_LINE(160)
					bool tmp12 = (uc <= (int)127);		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(160)
					if ((tmp12)){
						HX_STACK_LINE(161)
						int c1 = uc;		HX_STACK_VAR(c1,"c1");
						HX_STACK_LINE(161)
						int tmp13 = c1;		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(161)
						::String tmp14 = ::String::fromCharCode(tmp13);		HX_STACK_VAR(tmp14,"tmp14");
						HX_STACK_LINE(161)
						buf->b->push(tmp14);
					}
					else{
						HX_STACK_LINE(162)
						bool tmp13 = (uc <= (int)2047);		HX_STACK_VAR(tmp13,"tmp13");
						HX_STACK_LINE(162)
						if ((tmp13)){
							HX_STACK_LINE(163)
							{
								HX_STACK_LINE(163)
								int tmp14 = (int(uc) >> int((int)6));		HX_STACK_VAR(tmp14,"tmp14");
								HX_STACK_LINE(163)
								int tmp15 = (int((int)192) | int(tmp14));		HX_STACK_VAR(tmp15,"tmp15");
								HX_STACK_LINE(163)
								::String tmp16 = ::String::fromCharCode(tmp15);		HX_STACK_VAR(tmp16,"tmp16");
								HX_STACK_LINE(163)
								buf->b->push(tmp16);
							}
							HX_STACK_LINE(164)
							{
								HX_STACK_LINE(164)
								int tmp14 = (int(uc) & int((int)63));		HX_STACK_VAR(tmp14,"tmp14");
								HX_STACK_LINE(164)
								int tmp15 = (int((int)128) | int(tmp14));		HX_STACK_VAR(tmp15,"tmp15");
								HX_STACK_LINE(164)
								::String tmp16 = ::String::fromCharCode(tmp15);		HX_STACK_VAR(tmp16,"tmp16");
								HX_STACK_LINE(164)
								buf->b->push(tmp16);
							}
						}
						else{
							HX_STACK_LINE(165)
							bool tmp14 = (uc <= (int)65535);		HX_STACK_VAR(tmp14,"tmp14");
							HX_STACK_LINE(165)
							if ((tmp14)){
								HX_STACK_LINE(166)
								{
									HX_STACK_LINE(166)
									int tmp15 = (int(uc) >> int((int)12));		HX_STACK_VAR(tmp15,"tmp15");
									HX_STACK_LINE(166)
									int tmp16 = (int((int)224) | int(tmp15));		HX_STACK_VAR(tmp16,"tmp16");
									HX_STACK_LINE(166)
									::String tmp17 = ::String::fromCharCode(tmp16);		HX_STACK_VAR(tmp17,"tmp17");
									HX_STACK_LINE(166)
									buf->b->push(tmp17);
								}
								HX_STACK_LINE(167)
								{
									HX_STACK_LINE(167)
									int tmp15 = (int(uc) >> int((int)6));		HX_STACK_VAR(tmp15,"tmp15");
									HX_STACK_LINE(167)
									int tmp16 = (int(tmp15) & int((int)63));		HX_STACK_VAR(tmp16,"tmp16");
									HX_STACK_LINE(167)
									int tmp17 = (int((int)128) | int(tmp16));		HX_STACK_VAR(tmp17,"tmp17");
									HX_STACK_LINE(167)
									::String tmp18 = ::String::fromCharCode(tmp17);		HX_STACK_VAR(tmp18,"tmp18");
									HX_STACK_LINE(167)
									buf->b->push(tmp18);
								}
								HX_STACK_LINE(168)
								{
									HX_STACK_LINE(168)
									int tmp15 = (int(uc) & int((int)63));		HX_STACK_VAR(tmp15,"tmp15");
									HX_STACK_LINE(168)
									int tmp16 = (int((int)128) | int(tmp15));		HX_STACK_VAR(tmp16,"tmp16");
									HX_STACK_LINE(168)
									::String tmp17 = ::String::fromCharCode(tmp16);		HX_STACK_VAR(tmp17,"tmp17");
									HX_STACK_LINE(168)
									buf->b->push(tmp17);
								}
							}
							else{
								HX_STACK_LINE(170)
								{
									HX_STACK_LINE(170)
									int tmp15 = (int(uc) >> int((int)18));		HX_STACK_VAR(tmp15,"tmp15");
									HX_STACK_LINE(170)
									int tmp16 = (int((int)240) | int(tmp15));		HX_STACK_VAR(tmp16,"tmp16");
									HX_STACK_LINE(170)
									::String tmp17 = ::String::fromCharCode(tmp16);		HX_STACK_VAR(tmp17,"tmp17");
									HX_STACK_LINE(170)
									buf->b->push(tmp17);
								}
								HX_STACK_LINE(171)
								{
									HX_STACK_LINE(171)
									int tmp15 = (int(uc) >> int((int)12));		HX_STACK_VAR(tmp15,"tmp15");
									HX_STACK_LINE(171)
									int tmp16 = (int(tmp15) & int((int)63));		HX_STACK_VAR(tmp16,"tmp16");
									HX_STACK_LINE(171)
									int tmp17 = (int((int)128) | int(tmp16));		HX_STACK_VAR(tmp17,"tmp17");
									HX_STACK_LINE(171)
									::String tmp18 = ::String::fromCharCode(tmp17);		HX_STACK_VAR(tmp18,"tmp18");
									HX_STACK_LINE(171)
									buf->b->push(tmp18);
								}
								HX_STACK_LINE(172)
								{
									HX_STACK_LINE(172)
									int tmp15 = (int(uc) >> int((int)6));		HX_STACK_VAR(tmp15,"tmp15");
									HX_STACK_LINE(172)
									int tmp16 = (int(tmp15) & int((int)63));		HX_STACK_VAR(tmp16,"tmp16");
									HX_STACK_LINE(172)
									int tmp17 = (int((int)128) | int(tmp16));		HX_STACK_VAR(tmp17,"tmp17");
									HX_STACK_LINE(172)
									::String tmp18 = ::String::fromCharCode(tmp17);		HX_STACK_VAR(tmp18,"tmp18");
									HX_STACK_LINE(172)
									buf->b->push(tmp18);
								}
								HX_STACK_LINE(173)
								{
									HX_STACK_LINE(173)
									int tmp15 = (int(uc) & int((int)63));		HX_STACK_VAR(tmp15,"tmp15");
									HX_STACK_LINE(173)
									int tmp16 = (int((int)128) | int(tmp15));		HX_STACK_VAR(tmp16,"tmp16");
									HX_STACK_LINE(173)
									::String tmp17 = ::String::fromCharCode(tmp16);		HX_STACK_VAR(tmp17,"tmp17");
									HX_STACK_LINE(173)
									buf->b->push(tmp17);
								}
							}
						}
					}
				}
				;break;
				default: {
					HX_STACK_LINE(179)
					int tmp7 = c;		HX_STACK_VAR(tmp7,"tmp7");
					HX_STACK_LINE(179)
					::String tmp8 = ::String::fromCharCode(tmp7);		HX_STACK_VAR(tmp8,"tmp8");
					HX_STACK_LINE(179)
					::String tmp9 = (HX_HCSTRING("Invalid escape sequence \\","\x73","\xaf","\xf7","\xb2") + tmp8);		HX_STACK_VAR(tmp9,"tmp9");
					HX_STACK_LINE(179)
					::String tmp10 = (tmp9 + HX_HCSTRING(" at position ","\x0a","\xc2","\x01","\xe0"));		HX_STACK_VAR(tmp10,"tmp10");
					HX_STACK_LINE(179)
					int tmp11 = this->pos;		HX_STACK_VAR(tmp11,"tmp11");
					HX_STACK_LINE(179)
					int tmp12 = (tmp11 - (int)1);		HX_STACK_VAR(tmp12,"tmp12");
					HX_STACK_LINE(179)
					::String tmp13 = (tmp10 + tmp12);		HX_STACK_VAR(tmp13,"tmp13");
					HX_STACK_LINE(179)
					HX_STACK_DO_THROW(tmp13);
				}
			}
			HX_STACK_LINE(181)
			int tmp7 = this->pos;		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(181)
			start = tmp7;
		}
		else{
			HX_STACK_LINE(185)
			bool tmp4 = (c >= (int)128);		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(185)
			if ((tmp4)){
				HX_STACK_LINE(186)
				(this->pos)++;
				HX_STACK_LINE(187)
				bool tmp5 = (c >= (int)252);		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(187)
				if ((tmp5)){
					HX_STACK_LINE(187)
					hx::AddEq(this->pos,(int)4);
				}
				else{
					HX_STACK_LINE(188)
					bool tmp6 = (c >= (int)248);		HX_STACK_VAR(tmp6,"tmp6");
					HX_STACK_LINE(188)
					if ((tmp6)){
						HX_STACK_LINE(188)
						hx::AddEq(this->pos,(int)3);
					}
					else{
						HX_STACK_LINE(189)
						bool tmp7 = (c >= (int)240);		HX_STACK_VAR(tmp7,"tmp7");
						HX_STACK_LINE(189)
						if ((tmp7)){
							HX_STACK_LINE(189)
							hx::AddEq(this->pos,(int)2);
						}
						else{
							HX_STACK_LINE(190)
							bool tmp8 = (c >= (int)224);		HX_STACK_VAR(tmp8,"tmp8");
							HX_STACK_LINE(190)
							if ((tmp8)){
								HX_STACK_LINE(190)
								(this->pos)++;
							}
						}
					}
				}
			}
			else{
				HX_STACK_LINE(193)
				bool tmp5 = (c == (int)0);		HX_STACK_VAR(tmp5,"tmp5");
				HX_STACK_LINE(193)
				if ((tmp5)){
					HX_STACK_LINE(194)
					HX_STACK_DO_THROW(HX_HCSTRING("Unclosed string","\xac","\x02","\xef","\xea"));
				}
			}
		}
	}
	HX_STACK_LINE(196)
	bool tmp1 = (buf == null());		HX_STACK_VAR(tmp1,"tmp1");
	HX_STACK_LINE(196)
	if ((tmp1)){
		HX_STACK_LINE(197)
		::String tmp2 = this->str;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(197)
		int tmp3 = start;		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(197)
		int tmp4 = this->pos;		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(197)
		int tmp5 = start;		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(197)
		int tmp6 = (tmp4 - tmp5);		HX_STACK_VAR(tmp6,"tmp6");
		HX_STACK_LINE(197)
		int tmp7 = (tmp6 - (int)1);		HX_STACK_VAR(tmp7,"tmp7");
		HX_STACK_LINE(197)
		::String tmp8 = tmp2.substr(tmp3,tmp7);		HX_STACK_VAR(tmp8,"tmp8");
		HX_STACK_LINE(197)
		return tmp8;
	}
	else{
		HX_STACK_LINE(200)
		{
			HX_STACK_LINE(200)
			::String tmp2 = this->str;		HX_STACK_VAR(tmp2,"tmp2");
			HX_STACK_LINE(200)
			int tmp3 = start;		HX_STACK_VAR(tmp3,"tmp3");
			HX_STACK_LINE(200)
			int tmp4 = this->pos;		HX_STACK_VAR(tmp4,"tmp4");
			HX_STACK_LINE(200)
			int tmp5 = start;		HX_STACK_VAR(tmp5,"tmp5");
			HX_STACK_LINE(200)
			int tmp6 = (tmp4 - tmp5);		HX_STACK_VAR(tmp6,"tmp6");
			HX_STACK_LINE(200)
			int tmp7 = (tmp6 - (int)1);		HX_STACK_VAR(tmp7,"tmp7");
			HX_STACK_LINE(200)
			::String tmp8 = tmp2.substr(tmp3,tmp7);		HX_STACK_VAR(tmp8,"tmp8");
			HX_STACK_LINE(200)
			buf->b->push(tmp8);
		}
		HX_STACK_LINE(201)
		::String tmp2 = buf->b->join(HX_HCSTRING("","\x00","\x00","\x00","\x00"));		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(201)
		return tmp2;
	}
	HX_STACK_LINE(196)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(JsonParser_obj,parseString,return )

Void JsonParser_obj::invalidChar( ){
{
		HX_STACK_FRAME("haxe.format.JsonParser","invalidChar",0xa9f373d5,"haxe.format.JsonParser.invalidChar","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonParser.hx",247,0x53425a8f)
		HX_STACK_THIS(this)
		HX_STACK_LINE(248)
		(this->pos)--;
		HX_STACK_LINE(249)
		::String tmp = this->str;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(249)
		int tmp1 = this->pos;		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(249)
		int tmp2 = tmp.cca(tmp1);		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(249)
		::String tmp3 = (HX_HCSTRING("Invalid char ","\x81","\x66","\xec","\x29") + tmp2);		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(249)
		::String tmp4 = (tmp3 + HX_HCSTRING(" at position ","\x0a","\xc2","\x01","\xe0"));		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(249)
		int tmp5 = this->pos;		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(249)
		::String tmp6 = (tmp4 + tmp5);		HX_STACK_VAR(tmp6,"tmp6");
		HX_STACK_LINE(249)
		HX_STACK_DO_THROW(tmp6);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(JsonParser_obj,invalidChar,(void))

Void JsonParser_obj::invalidNumber( int start){
{
		HX_STACK_FRAME("haxe.format.JsonParser","invalidNumber",0x8e9d1988,"haxe.format.JsonParser.invalidNumber","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonParser.hx",252,0x53425a8f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(start,"start")
		HX_STACK_LINE(253)
		::String tmp = (HX_HCSTRING("Invalid number at position ","\xd8","\x9d","\x6f","\x13") + start);		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(253)
		::String tmp1 = (tmp + HX_HCSTRING(": ","\xa6","\x32","\x00","\x00"));		HX_STACK_VAR(tmp1,"tmp1");
		HX_STACK_LINE(253)
		::String tmp2 = this->str;		HX_STACK_VAR(tmp2,"tmp2");
		HX_STACK_LINE(253)
		int tmp3 = start;		HX_STACK_VAR(tmp3,"tmp3");
		HX_STACK_LINE(253)
		int tmp4 = this->pos;		HX_STACK_VAR(tmp4,"tmp4");
		HX_STACK_LINE(253)
		int tmp5 = start;		HX_STACK_VAR(tmp5,"tmp5");
		HX_STACK_LINE(253)
		int tmp6 = (tmp4 - tmp5);		HX_STACK_VAR(tmp6,"tmp6");
		HX_STACK_LINE(253)
		::String tmp7 = tmp2.substr(tmp3,tmp6);		HX_STACK_VAR(tmp7,"tmp7");
		HX_STACK_LINE(253)
		::String tmp8 = (tmp1 + tmp7);		HX_STACK_VAR(tmp8,"tmp8");
		HX_STACK_LINE(253)
		HX_STACK_DO_THROW(tmp8);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(JsonParser_obj,invalidNumber,(void))


JsonParser_obj::JsonParser_obj()
{
}

void JsonParser_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(JsonParser);
	HX_MARK_MEMBER_NAME(str,"str");
	HX_MARK_MEMBER_NAME(pos,"pos");
	HX_MARK_END_CLASS();
}

void JsonParser_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(str,"str");
	HX_VISIT_MEMBER_NAME(pos,"pos");
}

Dynamic JsonParser_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"str") ) { return str; }
		if (HX_FIELD_EQ(inName,"pos") ) { return pos; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"parseRec") ) { return parseRec_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"parseString") ) { return parseString_dyn(); }
		if (HX_FIELD_EQ(inName,"invalidChar") ) { return invalidChar_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"invalidNumber") ) { return invalidNumber_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic JsonParser_obj::__SetField(const ::String &inName,const Dynamic &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"str") ) { str=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pos") ) { pos=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool JsonParser_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,hx::PropertyAccess inCallProp)
{
	return false;
}

void JsonParser_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("str","\xb1","\xa8","\x57","\x00"));
	outFields->push(HX_HCSTRING("pos","\x94","\x5d","\x55","\x00"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(JsonParser_obj,str),HX_HCSTRING("str","\xb1","\xa8","\x57","\x00")},
	{hx::fsInt,(int)offsetof(JsonParser_obj,pos),HX_HCSTRING("pos","\x94","\x5d","\x55","\x00")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *sStaticStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_HCSTRING("str","\xb1","\xa8","\x57","\x00"),
	HX_HCSTRING("pos","\x94","\x5d","\x55","\x00"),
	HX_HCSTRING("parseRec","\xdd","\xe2","\x78","\xd6"),
	HX_HCSTRING("parseString","\x64","\xd5","\x6c","\x8c"),
	HX_HCSTRING("invalidChar","\x6d","\xad","\xce","\xa9"),
	HX_HCSTRING("invalidNumber","\x20","\xe9","\xeb","\xa6"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(JsonParser_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(JsonParser_obj::__mClass,"__mClass");
};

#endif

hx::Class JsonParser_obj::__mClass;

void JsonParser_obj::__register()
{
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("haxe.format.JsonParser","\xd6","\x2a","\xbf","\x29");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &JsonParser_obj::__SetStatic;
	__mClass->mMarkFunc = sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(sMemberFields);
	__mClass->mCanCast = hx::TCanCast< JsonParser_obj >;
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
} // end namespace format

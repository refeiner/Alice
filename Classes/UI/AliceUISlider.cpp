#include "AliceUISlider.h"

#include <string>

int NewAliceUISlider(lua_State*L)
{
	void*pMemory = lua_newuserdata(L, sizeof(Alice::UISlider));
	Alice::UISlider * ptr = new(pMemory)Alice::UISlider;

	luaL_getmetatable(L, "UISliderT");
	lua_setmetatable(L, -2);

	return 1;
}

int AliceUISlider_AddChild(lua_State*L)
{
	Alice::UIObject * ptr = (Alice::UIObject*)lua_touserdata(L,1);
	Alice::UIObject * child= (Alice::UIObject*)lua_touserdata(L, 2);
	ptr->node->addChild(child->node);
	return 0;
}

int AliceUISlider_SetOnValueChangeCallback(lua_State*L)
{
	Alice::UISlider * ptr = (Alice::UISlider*)lua_touserdata(L, 1);
	ptr->SetOnValueChangedCallbck(luaL_ref(L,LUA_REGISTRYINDEX));
	return 0;
}

namespace Alice
{
	void UISlider::OnSliderValueChanged(cocos2d::Ref *sender, ui::Slider::EventType controlEvent)
	{
		ui::Slider* slide_control = (ui::Slider*)sender;//通过回调参数sender 获得ControlSlider  
		int current_value = slide_control->getPercent();
		lua_State* l = GetMainThreadLuaState();
		lua_getref(l, CallbackScript);
		lua_pushinteger(l, current_value);
		if (lua_pcall(l, 1, 0, 0) != 0)
		{
			std::string err = lua_tostring(l, -1);
			printf("%s %d error %s\n", __FILE__, __LINE__, err.c_str());
		}
	}

	void UISlider::SetOnValueChangedCallbck(int script)
	{
		ui::Slider* slide_control = (ui::Slider*)node;//通过回调参数sender 获得ControlSlider  
		slide_control->addEventListener(CC_CALLBACK_2(UISlider::OnSliderValueChanged, this));
		CallbackScript = script;
	}

	int UISlider::Init(lua_State*L)
	{
		luaL_Reg api_m[] = {
			{ "OnValueChange",AliceUISlider_SetOnValueChangeCallback },
			{ NULL,NULL }
		};
		luaL_newmetatable(L, "UISliderT");
		lua_pushstring(L, "__index");
		lua_pushvalue(L, -2);
		lua_settable(L, -3);
		lua_pushstring(L, "__newindex");
		lua_pushvalue(L, -2);
		lua_settable(L, -3);
		luaL_openlib(L, NULL, api_m, 0);

		//register entry
		luaL_Reg api_c[] = {
			{ "New",NewAliceUISlider },
			{ NULL,NULL }
		};
		luaL_openlib(L, "UISlider", api_c, 0);
		printf("init UISlider\n");
		return 0;
	}
}
#include "AliceUIButton.h"

#include <string>

int NewAliceUIButton(lua_State*L)
{
	void*pMemory = lua_newuserdata(L, sizeof(Alice::UIButton));
	Alice::UIButton * ptr = new(pMemory)Alice::UIButton;
	luaL_getmetatable(L, "UIButtonT");
	lua_setmetatable(L, -2);

	return 1;
}

int AliceUIButton_SetOnButtonUpCallback(lua_State*L)
{
	Alice::UIButton * ptr = (Alice::UIButton*)lua_touserdata(L, 1);
	ptr->SetOnButtonUpCallbackScript(luaL_ref(L, LUA_REGISTRYINDEX));
	(static_cast<ui::Button*>(ptr->node))->addClickEventListener(CC_CALLBACK_1(Alice::UIButton::OnButtonUp, ptr));
	(static_cast<ui::Button*>(ptr->node))->addTouchEventListener(CC_CALLBACK_2(Alice::UIButton::OnButtonTouchEvent, ptr));
	return 0;
}

namespace Alice
{

	void UIButton::SetOnButtonUpCallbackScript(int script)
	{
		CallbackScript = script;
	}

	void UIButton::OnButtonUp(cocos2d::Ref *sender)
	{
		if (CallbackScript == LUA_REFNIL)
		{
			return;
		}
		std::string senderName = ((cocos2d::Node*)sender)->getName();
		lua_State* l = GetMainThreadLuaState();
		lua_rawgeti(l, LUA_REGISTRYINDEX, CallbackScript);
		lua_pushstring(l, senderName.c_str());
		if (lua_pcall(l, 1, 0, 0) != 0)
		{
			printf("%s %d error %s\n", __FILE__, __LINE__, lua_tostring(l, -1));
		}
	}

	void UIButton::OnButtonTouchEvent(cocos2d::Ref *sender, ui::Widget::TouchEventType e)
	{
		if (e == ui::Widget::TouchEventType::ENDED || e == ui::Widget::TouchEventType::CANCELED)
		{
			((Node*)sender)->setPositionY(((Node*)sender)->getPositionY() + 1.0f);
		}
		else if (e == ui::Widget::TouchEventType::BEGAN)
		{
			((Node*)sender)->setPositionY(((Node*)sender)->getPositionY() - 1.0f);
		}
	}

	int UIButton::Init(lua_State*L)
	{
		luaL_Reg api_m[] = {
			{ "OnButtonUp",AliceUIButton_SetOnButtonUpCallback },
			{ NULL,NULL }
		};
		luaL_newmetatable(L, "UIButtonT");
		lua_pushstring(L, "__index");
		lua_pushvalue(L, -2);
		lua_settable(L, -3);
		lua_pushstring(L, "__newindex");
		lua_pushvalue(L, -2);
		lua_settable(L, -3);
		luaL_openlib(L, NULL, api_m, 0);

		//register entry
		luaL_Reg api_c[] = {
			{ "New",NewAliceUIButton },
			{ NULL,NULL }
		};
		luaL_openlib(L, "UIButton", api_c, 0);
		printf("init UIButton\n");
		return 0;
	}
}
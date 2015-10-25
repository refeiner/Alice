#pragma once
#include "lua.hpp"
#include "AliceUIObject.h"
#include "cocos2d.h"
USING_NS_CC;

namespace Alice
{
	class UICSBObject :public UIObject
	{
	public:
		static int Init(lua_State*L);
	};
}
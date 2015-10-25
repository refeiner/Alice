#pragma once
#include "lua.hpp"
#include "AliceObject.h"
#include "cocos2d.h"
USING_NS_CC;

namespace Alice
{
	class UIObject :public Object
	{
	public:
		static int Init(lua_State*L);
		Node* node;
	};
}
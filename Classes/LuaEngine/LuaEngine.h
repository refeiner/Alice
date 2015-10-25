#pragma once
#include "lua.hpp"

namespace Alice
{
	class LuaEngine
	{
	public:
		static lua_State*	s_GobalStatePtr;
		static void Init();
	};
}
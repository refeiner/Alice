#include "LuaEngine.h"

namespace Alice
{
	lua_State*LuaEngine::s_GobalStatePtr = nullptr;
	void LuaEngine::Init()
	{
		s_GobalStatePtr = luaL_newstate();
		luaL_openlibs(s_GobalStatePtr);
	}
}
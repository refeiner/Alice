#include "LuaEngine.h"
#include "ExportModules.h"

namespace Alice
{
	lua_State*LuaEngine::s_GlobalStatePtr = nullptr;
	void LuaEngine::Init()
	{
		s_GlobalStatePtr = luaL_newstate();
		luaL_openlibs(s_GlobalStatePtr);
		INIT_LUAMODULE(Particle2DSystem);
	}
}
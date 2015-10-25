#include "LuaEngine.h"
#include "ExportModules.h"

extern "C" lua_State* GetMainThreadLuaState()
{
	return Alice::LuaEngine::s_GlobalStatePtr;
}
namespace Alice
{
	lua_State*LuaEngine::s_GlobalStatePtr = nullptr;
	void LuaEngine::Init()
	{
		s_GlobalStatePtr = luaL_newstate();
		luaL_openlibs(s_GlobalStatePtr);
		INIT_LUAMODULE(UIObject);
		INIT_LUAMODULE(UISlider);
		INIT_LUAMODULE(UICSBObject);
		INIT_LUAMODULE(Particle2DSystem);
	}
}
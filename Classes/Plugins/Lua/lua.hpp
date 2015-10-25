// lua.hpp
// Lua header files for C++
// <<extern "C">> not supplied automatically because Lua also compiles as C++

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#define INIT_LUAMODULE(X) do \
{	lua_pushcfunction(Alice::LuaEngine::s_GlobalStatePtr, Alice::##X::Init); \
	if(lua_pcall(Alice::LuaEngine::s_GlobalStatePtr,1,0,0)!=0){printf("%s\n",lua_tostring(Alice::LuaEngine::s_GlobalStatePtr,-1));} \
}while(0)
// lua.hpp
// Lua header files for C++
// <<extern "C">> not supplied automatically because Lua also compiles as C++

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#define INIT_LUAMODULE(X) Alice::##X::Init(Alice::LuaEngine::s_GlobalStatePtr)
#include "UIObject.h"
#include <string>

int NewAliceObject(lua_State*L)
{
	void*pMemory = lua_newuserdata(L, sizeof(Alice::UIObject));
	Alice::UIObject * ptr = new(pMemory)Alice::UIObject;

	luaL_getmetatable(L, "MokoObjectT");
	lua_setmetatable(L, -2);
	return 1;
}

int AliceUIObject_AddChild(lua_State*L)
{
	Alice::UIObject * ptr = (Alice::UIObject*)lua_touserdata(L,1);
	Alice::UIObject * child= (Alice::UIObject*)lua_touserdata(L, 2);
	ptr->node->addChild(child->node);
	return 0;
}

namespace Alice
{
	int UIObject::Init(lua_State*L)
	{
		luaL_Reg api_m[] = {
			{ "AddChild",AliceUIObject_AddChild },
			{ NULL,NULL }
		};
		luaL_newmetatable(L, "MokoObjectT");
		lua_pushstring(L, "__index");
		lua_pushvalue(L, -2);
		lua_settable(L, -3);
		lua_pushstring(L, "__newindex");
		lua_pushvalue(L, -2);
		lua_settable(L, -3);
		luaL_openlib(L, NULL, api_m, 0);

		//register entry
		luaL_Reg api_c[] = {
			{ "New",NewAliceObject },
			{ NULL,NULL }
		};
		luaL_openlib(L, "UIObject", api_c, 0);
		printf("init UIObject\n");
		return 0;
	}
}
#include "AliceUICSBObject.h"
#include "AliceUISlider.h"
#include <string>

int NewAliceUICSBObject(lua_State*L)
{
	std::string fileName = lua_tostring(L,1);
	void*pMemory = lua_newuserdata(L, sizeof(Alice::UICSBObject));
	Alice::UICSBObject * ptr = new(pMemory)Alice::UICSBObject;

	luaL_getmetatable(L, "UICSBObjectT");
	lua_setmetatable(L, -2);
	ptr->node = CSLoader::createNode(fileName);
	return 1;
}

int AliceUICSBObject_AddChild(lua_State*L)
{
	Alice::UIObject * ptr = (Alice::UIObject*)lua_touserdata(L,1);
	Alice::UIObject * child= (Alice::UIObject*)lua_touserdata(L, 2);
	ptr->node->addChild(child->node);
	return 0;
}

int AliceUICSBObject_GetUISlider(lua_State*L)
{
	Alice::UIObject * ptr = (Alice::UIObject*)lua_touserdata(L, 1);
	Node * target = ptr->GetChildNodeByPath(lua_tostring(L,2), lua_tostring(L,3));
	if (target!=nullptr)
	{
		lua_getglobal(L,"UISlider");
		lua_pushstring(L, "New");
		lua_pcall(L, 0, 1, 0);
		Alice::UISlider*object = (Alice::UISlider*)lua_touserdata(L, -1);
		object->node = target;
	}
	return 1;
}

namespace Alice
{
	int UICSBObject::Init(lua_State*L)
	{
		luaL_Reg api_m[] = {
			{ "AddChild",AliceUICSBObject_AddChild },
			{ "GetUISlider",AliceUICSBObject_GetUISlider },
			{ NULL,NULL }
		};
		luaL_newmetatable(L, "UICSBObjectT");
		lua_pushstring(L, "__index");
		lua_pushvalue(L, -2);
		lua_settable(L, -3);
		lua_pushstring(L, "__newindex");
		lua_pushvalue(L, -2);
		lua_settable(L, -3);
		luaL_openlib(L, NULL, api_m, 0);

		//register entry
		luaL_Reg api_c[] = {
			{ "New",NewAliceUICSBObject },
			{ NULL,NULL }
		};
		luaL_openlib(L, "UICSBObject", api_c, 0);
		printf("init UICSBObject\n");
		return 0;
	}
}
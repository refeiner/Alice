#include "AliceUIObject.h"
#include <string>

int NewAliceUIObject(lua_State*L)
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
		luaL_newmetatable(L, "UIObjectT");
		lua_pushstring(L, "__index");
		lua_pushvalue(L, -2);
		lua_settable(L, -3);
		lua_pushstring(L, "__newindex");
		lua_pushvalue(L, -2);
		lua_settable(L, -3);
		luaL_openlib(L, NULL, api_m, 0);

		//register entry
		luaL_Reg api_c[] = {
			{ "New",NewAliceUIObject },
			{ NULL,NULL }
		};
		luaL_openlib(L, "UIObject", api_c, 0);
		printf("init UIObject\n");
		return 0;
	}

	Node* UIObject::GetChildNodeByPath(std::string path, std::string childName)
	{
		return GetChildNodeByPath(node, path, childName);
	}

	Node* UIObject::GetChildNodeByPath(Node*parent, std::string path, std::string childName)
	{
		if (parent == nullptr)
		{
			return nullptr;
		}
		size_t pos = path.find_first_of('/');
		size_t index = 0;
		if (pos == std::string::npos)
		{
			return parent->getChildByName(childName);
		}
		else
		{
			std::string component = path.substr(index, pos - index);
			index = pos + 1;
			parent = parent->getChildByName(component);
			return GetChildNodeByPath(parent, path.substr(index, path.length() - index), childName);
		}
	}
}
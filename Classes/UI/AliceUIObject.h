#pragma once
#include "lua.hpp"
#include "AliceObject.h"
#include "cocos2d.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
USING_NS_CC;

namespace Alice
{
	class UIObject :public Object
	{
	public:
		static int Init(lua_State*L);
		Node* GetChildNodeByPath(std::string path, std::string childName);
		Node* node;
	private:
		static Node* GetChildNodeByPath(Node*parent, std::string path, std::string childName);
	};
}
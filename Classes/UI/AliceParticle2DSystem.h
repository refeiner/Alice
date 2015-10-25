#pragma once
#include "lua.hpp"
#include "AliceUIObject.h"

namespace Alice
{
	class Particle2DSystem : public UIObject
	{
	public:
		static int Init(lua_State*L);
		Particle2DSystem();
	};
}
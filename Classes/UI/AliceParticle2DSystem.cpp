#include "AliceParticle2DSystem.h"

int NewParticle2DSystemObject(lua_State*L)
{
	void*pMemory = lua_newuserdata(L, sizeof(Alice::Particle2DSystem));
	Alice::Particle2DSystem * ptr = new(pMemory)Alice::Particle2DSystem;

	luaL_getmetatable(L, "Particle2DSystemT");
	lua_setmetatable(L, -2);
	return 1;
}

int AliceParticle2DSystem_AddChild(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	Alice::Particle2DSystem * child = (Alice::Particle2DSystem*)lua_touserdata(L, 2);
	ptr->node->addChild(child->node);
	return 0;
}

namespace Alice
{
	Particle2DSystem::Particle2DSystem()
	{
		node = ParticleGalaxy::create();
	}
	int Particle2DSystem::Init(lua_State*L)
	{
		luaL_Reg api_m[] = {
			{ "AddChild",AliceParticle2DSystem_AddChild },
			{ NULL,NULL }
		};
		luaL_newmetatable(L, "Particle2DSystemT");
		lua_pushstring(L, "__index");
		lua_pushvalue(L, -2);
		lua_settable(L, -3);
		lua_pushstring(L, "__newindex");
		lua_pushvalue(L, -2);
		lua_settable(L, -3);
		luaL_openlib(L, NULL, api_m, 0);

		//register entry
		luaL_Reg api_c[] = {
			{ "New",NewParticle2DSystemObject },
			{ NULL,NULL }
		};
		luaL_openlib(L, "Particle2DSystem", api_c, 0);
		printf("init Particle2DSystem\n");
		return 0;
	}
}
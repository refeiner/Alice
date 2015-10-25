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

int AliceParticle2DSystem_ChangeMode(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	int mode = lua_tointeger(L, 2);//0、kCCParticleModeGravity，1、kCCParticleModeRadius
	((ParticleSystemQuad*)ptr->node)->setEmitterMode((ParticleSystem::Mode)mode);
	
	return 0;
}

//在重力模式下才有效的属性值
int AliceParticle2DSystem_SetGravity(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setGravity(ccp(lua_tonumber(L,2),lua_tonumber(L,3)));
	return 0;
}
int AliceParticle2DSystem_SetSpeed(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setSpeed(lua_tonumber(L, 2));
	return 0;
}
int AliceParticle2DSystem_SetSpeedVar(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setSpeedVar(lua_tonumber(L, 2));
	return 0;
}
int AliceParticle2DSystem_SetTangencialAccel(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setTangentialAccel(lua_tonumber(L, 2));
	return 0;
}
int AliceParticle2DSystem_SetTangencialAccelVar(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setTangentialAccelVar(lua_tonumber(L, 2));
	return 0;
}
int AliceParticle2DSystem_SetRadialAccel(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setRadialAccel(lua_tonumber(L, 2));
	return 0;
}
int AliceParticle2DSystem_SetRadialAccelVar(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setRadialAccelVar(lua_tonumber(L, 2));
	return 0;
}

//角度模式
int AliceParticle2DSystem_SetStartRadius(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setStartRadius(lua_tonumber(L, 2));
	return 0;
}
int AliceParticle2DSystem_SetStartRadiusVar(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setStartRadiusVar(lua_tonumber(L, 2));
	return 0;
}
int AliceParticle2DSystem_SetEndRadius(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setEndRadius(lua_tonumber(L, 2));
	return 0;
}
int AliceParticle2DSystem_SetEndRadiusVar(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setEndRadiusVar(lua_tonumber(L, 2));
	return 0;
}
int AliceParticle2DSystem_SetRotatePerSecond(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setRotatePerSecond(lua_tonumber(L, 2));
	return 0;
}
int AliceParticle2DSystem_SetRotatePerSecondVar(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setRotatePerSecondVar(lua_tonumber(L, 2));
	return 0;
}

namespace Alice
{
	Particle2DSystem::Particle2DSystem()
	{
		//default to create a file particle
		node = ParticleFire::create();
	}

	int Particle2DSystem::Init(lua_State*L)
	{
		luaL_Reg api_m[] = {
			{ "AddChild",AliceParticle2DSystem_AddChild },
			{ "ChangeMode",AliceParticle2DSystem_ChangeMode },
			//重力模式
			{ "SetGravity",AliceParticle2DSystem_SetGravity },
			{ "SetSpeed",AliceParticle2DSystem_SetSpeed },
			{ "SetSpeedVar",AliceParticle2DSystem_SetSpeedVar },
			{ "SetTangencialAccel",AliceParticle2DSystem_SetTangencialAccel },
			{ "SetTangencialAccelVar",AliceParticle2DSystem_SetTangencialAccelVar },
			{ "SetRadialAccel",AliceParticle2DSystem_SetRadialAccel },
			{ "SetRadialAccelVar",AliceParticle2DSystem_SetRadialAccelVar },
			//角度模式
			{ "SetStartRadius",AliceParticle2DSystem_SetStartRadius },
			{ "SetStartRadiusVar",AliceParticle2DSystem_SetStartRadiusVar },
			{ "SetEndRadius",AliceParticle2DSystem_SetEndRadius },
			{ "SetEndRadiusVar",AliceParticle2DSystem_SetEndRadiusVar },
			{ "SetRotatePerSecond",AliceParticle2DSystem_SetRotatePerSecond },
			{ "SetRotatePerSecondVar",AliceParticle2DSystem_SetRotatePerSecondVar },
			//公用属性

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
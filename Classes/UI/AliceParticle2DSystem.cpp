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
	((ParticleSystemQuad*)ptr->node)->setGravity(Vec2(lua_tonumber(L,2),lua_tonumber(L,3)));
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

//公共属性
int AliceParticle2DSystem_SetStartSize(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setStartSize(lua_tonumber(L, 2));
	return 0;
}
int AliceParticle2DSystem_SetStartSizeVar(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setStartSizeVar(lua_tonumber(L, 2));
	return 0;
}
int AliceParticle2DSystem_SetEndSize(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setEndSize(lua_tonumber(L, 2));
	return 0;
}
int AliceParticle2DSystem_SetEndSizeVar(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setEndSizeVar(lua_tonumber(L, 2));
	return 0;
}
int AliceParticle2DSystem_SetStartColor(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setStartColor(Color4F(lua_tonumber(L,2), lua_tonumber(L, 3), lua_tonumber(L,4), lua_tonumber(L, 5)));
	return 0;
}
int AliceParticle2DSystem_SetStartColorVar(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setStartColorVar(Color4F(lua_tonumber(L, 2), lua_tonumber(L, 3), lua_tonumber(L, 4), lua_tonumber(L, 5)));
	return 0;
}
int AliceParticle2DSystem_SetEndColor(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setEndColor(Color4F(lua_tonumber(L, 2), lua_tonumber(L, 3), lua_tonumber(L, 4), lua_tonumber(L, 5)));
	return 0;
}
int AliceParticle2DSystem_SetEndColorVar(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setEndColorVar(Color4F(lua_tonumber(L, 2), lua_tonumber(L, 3), lua_tonumber(L, 4), lua_tonumber(L, 5)));
	return 0;
}
int AliceParticle2DSystem_SetStartSpin(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setStartSpin(lua_tonumber(L, 2));
	return 0;
}
int AliceParticle2DSystem_SetStartSpinVar(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setStartSpinVar(lua_tonumber(L, 2));
	return 0;
}
int AliceParticle2DSystem_SetEndSpin(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setEndSpin(lua_tonumber(L, 2));
	return 0;
}
int AliceParticle2DSystem_SetEndSpinVar(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setEndSpinVar(lua_tonumber(L, 2));
	return 0;
}
int AliceParticle2DSystem_SetLife(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setLife(lua_tonumber(L, 2));
	return 0;
}
int AliceParticle2DSystem_SetLifeVar(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setLifeVar(lua_tonumber(L, 2));
	return 0;
}
int AliceParticle2DSystem_SetAngle(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setAngle(lua_tonumber(L, 2));
	return 0;
}
int AliceParticle2DSystem_SetAngleVar(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setAngleVar(lua_tonumber(L, 2));
	return 0;
}
int AliceParticle2DSystem_SetPosition(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setPosition(Vec2(lua_tonumber(L, 2),lua_tonumber(L, 3)));
	return 0;
}
int AliceParticle2DSystem_SetPositionVar(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setPosVar(Vec2(lua_tonumber(L, 2), lua_tonumber(L, 3)));
	return 0;
}
int AliceParticle2DSystem_SetCenterOfGravity(lua_State*L)
{
	printf("no implemented method : AliceParticle2DSystem_SetCenterOfGravity\n");
	return 0;
}
//继承自PaticleSystem的公有属性
int AliceParticle2DSystem_SetEmissionRate(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setEmissionRate(lua_tonumber(L, 2));
	return 0;
}

int AliceParticle2DSystem_SetDuration(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setDuration(lua_tonumber(L, 2));
	return 0;
}

int AliceParticle2DSystem_SetBlendFunc(lua_State*L)
{
	GLenum Funcs[] = {
		GL_ZERO,
		GL_ONE,
		GL_SRC_ALPHA,
		GL_ONE_MINUS_SRC_ALPHA,
		GL_SRC_COLOR,
		GL_ONE_MINUS_SRC_COLOR,
		GL_DST_ALPHA,
		GL_ONE_MINUS_DST_ALPHA,
		GL_DST_COLOR,
		GL_ONE_MINUS_DST_COLOR,
		GL_SRC_ALPHA_SATURATE
	};
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setBlendFunc({ Funcs[lua_tointeger(L,2)],Funcs[lua_tointeger(L,3)] });
	return 0;
}

int AliceParticle2DSystem_SetPositionType(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	((ParticleSystemQuad*)ptr->node)->setPositionType((ParticleSystem::PositionType)lua_tointeger(L, 2));
	return 0;
}

int AliceParticle2DSystem_SetTexture(lua_State*L)
{
	Alice::Particle2DSystem * ptr = (Alice::Particle2DSystem*)lua_touserdata(L, 1);
	std::string fileName = lua_tostring(L,2);
	TextureCache * pTextureCache = Director::getInstance()->getTextureCache();
	Texture2D* texture=pTextureCache->addImage(fileName);
	((ParticleSystemQuad*)ptr->node)->setTexture(texture);
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
			{ "SetStartSize",AliceParticle2DSystem_SetStartSize },
			{ "SetStartSizeVar",AliceParticle2DSystem_SetStartSizeVar },
			{ "SetEndSize",AliceParticle2DSystem_SetEndSize },
			{ "SetEndSizeVar",AliceParticle2DSystem_SetEndSizeVar },
			{ "SetStartColor",AliceParticle2DSystem_SetStartColor },
			{ "SetStartColorVar",AliceParticle2DSystem_SetStartColorVar },
			{ "SetEndColor",AliceParticle2DSystem_SetEndColor },
			{ "SetEndColorVar",AliceParticle2DSystem_SetEndColorVar },
			{ "SetStartSpin",AliceParticle2DSystem_SetStartSpin },
			{ "SetStartSpinVar",AliceParticle2DSystem_SetStartSpinVar },
			{ "SetEndSpin",AliceParticle2DSystem_SetEndSpin },
			{ "SetEndSpinVar",AliceParticle2DSystem_SetEndSpinVar },
			{ "SetLife",AliceParticle2DSystem_SetLife },
			{ "SetLifeVar",AliceParticle2DSystem_SetLifeVar },
			{ "SetAngle",AliceParticle2DSystem_SetAngle },
			{ "SetAngleVar",AliceParticle2DSystem_SetAngleVar },
			{ "SetPosition",AliceParticle2DSystem_SetPosition },
			{ "SetPositionVar",AliceParticle2DSystem_SetPositionVar },
			{ "SetCenterOfGravity",AliceParticle2DSystem_SetCenterOfGravity },
			//继承自ParticleSystem的公有属性
			{ "SetEmissionRate",AliceParticle2DSystem_SetEmissionRate },
			{ "SetDuration",AliceParticle2DSystem_SetDuration },
			{ "SetBlendFunc",AliceParticle2DSystem_SetBlendFunc },
			{ "SetPositionType",AliceParticle2DSystem_SetPositionType },
			{ "SetTexture",AliceParticle2DSystem_SetTexture },
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
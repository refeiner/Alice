#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "cocos2d.h"
USING_NS_CC;
#include "LuaEngine.h"
#include "AliceUIObject.h"
cocos2d::Layer* g_Layer;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
	
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);
	
    // return the scene
    return scene;
}

int TempAddChildToScene(lua_State*L)
{
	Alice::UIObject * node = (Alice::UIObject*)lua_touserdata(L, 1);
	g_Layer->addChild(node->node);
	return 0;
}
// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
	g_Layer = this;
	//ParticleSystemQuad* m_emitter = new ParticleSystemQuad();
	//m_emitter = ParticleGalaxy::create();
	//addChild(m_emitter);
	lua_register(Alice::LuaEngine::s_GlobalStatePtr,"AddChildToScene", TempAddChildToScene);
    //auto rootNode = CSLoader::createNode("MainScene.csb");
	//
    //addChild(rootNode);
	luaL_dofile(Alice::LuaEngine::s_GlobalStatePtr,"scripts/main.lua");
    return true;
}

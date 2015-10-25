#include "main.h"
#include "Particle2DSystem.h"
#include "AppDelegate.h"
#include "cocos2d.h"
#include "LuaEngine.h"

USING_NS_CC;

#if _MSC_VER > 1800
#pragma comment(lib,"libcocos2d_2015.lib")
#endif

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
	Alice::LuaEngine::Init();
    // create the application instance
    AppDelegate app;
    return Application::getInstance()->run();
}

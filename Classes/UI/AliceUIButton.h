#pragma once
#include "AliceUIObject.h"
#include "ui/UIButton.h"

namespace Alice
{
	class UIButton :public UIObject
	{
	public:
		static int Init(lua_State*L);
		void SetOnButtonUpCallbackScript(int script);
		void OnButtonUp(cocos2d::Ref* pSender);
		void OnButtonTouchEvent(cocos2d::Ref *sender, ui::Widget::TouchEventType e);
	protected:
		int CallbackScript;
	};
}
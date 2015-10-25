#pragma once
#include "AliceUIObject.h"
#include "ui/UIWidget.h"
#include "ui/UISlider.h"

namespace Alice
{
	class UISlider :public UIObject
	{
	public:
		static int Init(lua_State*L);
		void SetOnValueChangedCallbck(int script);
		void OnSliderValueChanged(cocos2d::Ref *sender,cocos2d::ui::Slider::EventType controlEvent);
	protected:

		int CallbackScript;
	};
}
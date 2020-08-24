#pragma once
#include "../FileWindow.h"
struct SET_TEXTURE
{
	void operator()(FileWindow& flWnd)
	{
		flWnd.InputTextureDir();
		flWnd.btnType_ = BUTTON_TYPE::NON;
		
	}
};
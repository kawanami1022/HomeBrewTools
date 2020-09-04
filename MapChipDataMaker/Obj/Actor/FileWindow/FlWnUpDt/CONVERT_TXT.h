#pragma once
#include "../FileWindow.h"
struct CONVERT_TXT
{
	void operator()(FileWindow& flWnd)
	{
		flWnd.GetConsoleInputFileName();
	}
};
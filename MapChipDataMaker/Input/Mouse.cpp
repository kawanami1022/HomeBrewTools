#include <DxLib.h>
#include "Mouse.h"
#include "MouseID.h"


void Mouse::setInputTbl()
{
	mouseInput = GetMouseInput();
	inputTblNow_ =
	{
		{(mouseInput & MOUSE_INPUT_LEFT) != 0},
		{(mouseInput & MOUSE_INPUT_RIGHT) != 0},
		{(mouseInput & MOUSE_INPUT_MIDDLE) != 0},
	};
}

void Mouse::update()
{
	mouseInput = GetMouseInput();
	for (auto MouseID : MOUSE_ID())
	{
		inputTblOld_[static_cast<int>(MouseID)] =inputTblNow_[static_cast<int>(MouseID)];
		inputTblNow_[static_cast<int>(MouseID)]= inputTblNow_[static_cast<int>(MouseID)];
	}
}

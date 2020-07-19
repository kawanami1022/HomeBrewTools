#include <DxLib.h>
#include "keyInput.h"

void keyInput::setInputTbl()
{
}

void keyInput::update()
{
	GetHitKeyStateAll(keyState.data());
}

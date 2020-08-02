#include <DxLib.h>
#include "keyInput.h"

ContType KeyInput::GetType(void)
{
	return ContType::Key;
}

bool KeyInput::Setup()
{
	return true;
}

void KeyInput::Update(void)
{
	GetHitKeyStateAll(_keyData.data());
	for (auto id:InputID())
	{
		_data[id][static_cast<int>(Trg::Old)] = _data[id][static_cast<int>(Trg::Now)];
		_data[id][static_cast<int>(Trg::Now)] = _keyData[_InputTbl[id]];
	}
}


#include <DxLib.h>
#include "mouse.h"

void mouse::Update()
{
	mousePos_[1] = mousePos_[0];
	GetMousePoint(&mousePos_[0].x, &mousePos_[0].y);
	mouseOffSize = mousePos_[1] - mousePos_[0];
	MouseInput_ = GetMouseInput();
	for (auto id: InputID())
	{
		_data[id][static_cast<int>(Trg::Old)] = _data[id][static_cast<int>(Trg::Now)];
		_data[id][static_cast<int>(Trg::Now)] = _mouseInputTbl[id] & MouseInput_;
	}
}

bool mouse::Setup()
{
	_mouseInputTbl =
	{ {InputID::Left,MOUSE_INPUT_LEFT},
	{InputID::Right,MOUSE_INPUT_RIGHT},
	{InputID::MIDDLE,MOUSE_INPUT_MIDDLE} };
	return true;
}

ContType mouse::GetType(void)
{
	return ContType::Mouse;
}


TrgPos mouse::getMousePos()
{
	return mousePos_;
}

bool mouse::Push(InputID id)
{
	return (_data[id][static_cast<int>(Trg::Old)]==0 && _data[id][static_cast<int>(Trg::Now)]!=0);
}

bool mouse::Sepatate(InputID id)
{
	return (_data[id][static_cast<int>(Trg::Old)] == 0 && _data[id][static_cast<int>(Trg::Now)] == 0);;
}

bool mouse::Release(InputID id)
{
	return (_data[id][static_cast<int>(Trg::Old)] =! 0 && _data[id][static_cast<int>(Trg::Now)] == 0);;
}

bool mouse::Hold(InputID id)
{
	return (_data[id][static_cast<int>(Trg::Old)] |= 0 && _data[id][static_cast<int>(Trg::Now)] != 0);;
}

Vector2 mouse::getMouseOffSize(void)
{
	return mouseOffSize;
}

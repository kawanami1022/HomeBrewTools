#include "Button.h"

Button::Button(SharTexture grHdl, Vector2 pos, Vector2 offsetPos_)
{
	sharTxHandle_ = grHdl;
	pos_ = pos+ offsetPos_;
}

Vector2 Button::GetPos()
{
	return pos_;
}


SharTexture Button::GetTexture()
{
	return sharTxHandle_;
}

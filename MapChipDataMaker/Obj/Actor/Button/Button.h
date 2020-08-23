#pragma once
#include "../../Obj.h"
#include "../../../Texture/TextureFactory.h"
#include "../../../Texture/Texture.h"

class Button:Obj
{
public:
	Button(SharTexture grHdl, Vector2 pos, Vector2 offsetPos_);
	Vector2 GetPos();
	//int GetHandle();
	SharTexture GetTexture();
private:
	SharTexture sharTxHandle_;		// ‰æ‘œƒnƒ“ƒhƒ‹
	bool flag_;
};


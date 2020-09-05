#include <DxLib.h>
#include "Texture.h"

Texture::Texture()
{
	GrHandle_ = 0;
	Size_ = { 0,0 };
}

Texture::Texture(int GrHandle)
{
	GrHandle_ = GrHandle;
	GetGraphSize(GrHandle_, &Size_.x, &Size_.y);
}

Texture::~Texture()
{
}

int Texture::GetGrHandle()
{
	return GrHandle_;
}

Vector2 Texture::GetSize()
{
	return Size_;
}

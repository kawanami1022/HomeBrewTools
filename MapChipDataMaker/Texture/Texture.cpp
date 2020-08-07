#include <DxLib.h>
#include "Texture.h"

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

Vector2I Texture::GetSize()
{
	return Size_;
}

#include "../Actor.h"
#include "TextureBox.h"
#include "../FileWindow/FileWindow.h"

TextureBox::TextureBox()
{
	pos_ = Vector2(32 + 850, 240);
}

void TextureBox::Input()
{
}

void TextureBox::Update()
{
}

void TextureBox::Draw()
{
}

void TextureBox::SetMousePos()
{
}

void TextureBox::SetTexture(std::string FileName)
{
	TextureNmList_.push_back(FileName);
}

void TextureBox::SetTextureList(SharTexture texture)
{
}
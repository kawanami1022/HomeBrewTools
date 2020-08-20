#include <DxLib.h>
#include "../../../Vector2/Vector2.h"
#include "../../../DxLibForHomeBrew/DxLib_Draw.h"

#include "FileWindow.h"

FileWindow::FileWindow()
{
	pos_ = Vector2(32 + 850, 0);
	size_ = Vector2(1200 - pos_.x, 200);
	txFc_ = std::make_unique<TextureFactory>();
	texture_.emplace_back(txFc_->GetTexture_("UI/SetTexture.png"));
}

void FileWindow::Input()
{
}

void FileWindow::Update()
{
}

void FileWindow::Draw()
{
	DxLib_Draw::DrawBoxLineEOff(pos_.x, pos_.y, size_.x, size_.y, 0xffffff);
	DxLib_Draw::DrawBoxLineEOff(pos_.x+9, pos_.y+8, 300, 40, 0xffffff);

}

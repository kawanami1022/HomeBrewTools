#include <DxLib.h>
#include "../../../Vector2/Vector2.h"
#include "../../../DxLibForHomeBrew/DxLib_Draw.h"
#include "../../../input/controller.h"
#include "../../../input/mouse.h"
#include "../../../Collision2D/collision.h"
#include "FileWindow.h"

FileWindow::FileWindow()
{
	btnType_ = BUTTON_TYPE::NON;
	pos_ = Vector2(32 + 850, 0);
	size_ = Vector2(1200 - pos_.x, 200);
	txFc_ = std::make_unique<TextureFactory>();
	txNmList_ = { "","UI/SetTexture.png" };
	for (auto&& TXLIST : txNmList_)
	{textureList_.emplace_back(txFc_->GetTexture_(TXLIST));}

	btn_.emplace_back(Button(textureList_[0], Vector2(9, 8), Vector2(pos_)));
	btn_.emplace_back(Button(textureList_[1], Vector2(9, 8), Vector2(pos_)));
}

void FileWindow::Input()
{
	if ()
}

void FileWindow::Update()
{
}

void FileWindow::Draw()
{

	DrawGraph(btn_[1].GetPos().x,btn_[1].GetPos().y,btn_[1].GetTexture()->GetGrHandle(), true);


	DxLib_Draw::DrawBoxLineEOff(pos_.x, pos_.y, size_.x, size_.y, 0xffffff);
	DxLib_Draw::DrawBoxLineEOff(pos_.x+9, pos_.y+8, 300, 40, 0xffffff);
}

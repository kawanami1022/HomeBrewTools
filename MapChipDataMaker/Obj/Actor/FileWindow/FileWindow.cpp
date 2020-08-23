#include <DxLib.h>
#include "../../../Vector2/Vector2.h"
#include "../../../DxLibForHomeBrew/DxLib_Draw.h"
#include "../../../input/controller.h"
#include "../../../input/mouse.h"
#include "../../../Collision2D/collision2D.h"
#include "FileWindow.h"

FileWindow::FileWindow()
{
	btnType_ = BUTTON_TYPE::NON;
	pos_ = Vector2(32 + 850, 0);
	size_ = Vector2(1200 - pos_.x, 200);
	txFc_ = std::make_unique<TextureFactory>();
	txNmList_ = { "","UI/SetTexture.png","UI/RemoveTexture.png" };
	for (auto&& TXLIST : txNmList_)
	{textureList_.emplace_back(txFc_->GetTexture_(TXLIST));}

	btn_.emplace_back(Button(textureList_[0], Vector2(9, 8), Vector2(pos_)));
	btn_.emplace_back(Button(textureList_[1], Vector2(9, 8), Vector2(pos_)));
	btn_.emplace_back(Button(textureList_[2], Vector2(9, textureList_[2]->GetSize().y+8), Vector2(pos_)));
}

void FileWindow::Input()
{

}

void FileWindow::Update()
{
}

void FileWindow::Draw()
{
	int idx = 0;
	for (auto BTN_TYPE : btn_)
	{
		if (btnType_ != static_cast<BUTTON_TYPE>(idx)) SetDrawBright(123, 123, 123);

		DrawGraph(btn_[idx].GetPos().x,btn_[idx].GetPos().y,btn_[idx].GetTexture()->GetGrHandle(), true);
		SetDrawBright(255, 255, 255);
		idx++;
	}


	DxLib_Draw::DrawBoxLineEOff(pos_.x, pos_.y, size_.x, size_.y, 0xffffff);
	idx = 0;
	for (auto BTN_TYPE : btn_)
	{
		DxLib_Draw::DrawBoxLineEOff(BTN_TYPE.GetPos().x, BTN_TYPE.GetPos().y, 
			textureList_[idx]->GetSize().x, textureList_[idx]->GetSize().y, 0xffffff);
		idx++;
	}
}

void FileWindow::changeButtonType()
{
	int idx = 0;
	for (auto BTN_TYPE : btn_)
	{
		if (Collision2D::IsHitABB(mPos_[0], { BTN_TYPE.GetPos().x,BTN_TYPE.GetPos().y, 
										textureList_[idx]->GetSize().x,textureList_[idx]->GetSize().y }))
		{
			btnType_ = static_cast<BUTTON_TYPE>(idx);
		}
		idx++;
	}
}

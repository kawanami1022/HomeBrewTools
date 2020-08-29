#include <iostream>
#include <DxLib.h>
#include "../../../Collision2D/collision2D.h"
#include "../../../DxLibForHomeBrew/DxLib_Draw.h"
#include "../Actor.h"
#include "TextureBox.h"
#include "../FileWindow/FileWindow.h"
#include "../ChipDataView/ChipDataView.h"

TextureBox::TextureBox()
{
	SlTxNum_ = 0;
	pos_ = Vector2(32 + 850, 220);
	TextureSize_ = { 0,0 };
	TextureCount_ = { 0,0 };
}

void TextureBox::Input()
{
	
}

void TextureBox::Update()
{
	
}

void TextureBox::Draw()
{
	int idx = 0;
	for (auto TXHDL : txHdl_)
	{
		DrawGraph(txPos_[idx].x, txPos_[idx].y, TXHDL->GetGrHandle(), true);
		idx++;
	}
	if (txHdl_.size() > 0)
		DxLib_Draw::DrawBoxLineEOff(txPos_[SlTxNum_].x, txPos_[SlTxNum_].y,
			txHdl_[SlTxNum_]->GetSize().x, txHdl_[SlTxNum_]->GetSize().y, 0x00ff00);
}

//マウスの座標で識別
void TextureBox::InMousePosIdnt()
{
	Vector2 MousePos = mPos_[0] - pos_;
	if (MousePos < 0)return;
	Vector2 Size = TextureCount_;
	Vector2 BlockPos = MousePos / TextureSize_;
	if ( BlockPos< Size)
	{
		if (BlockPos.x + BlockPos.y * Size.x < txHdl_.size() - 1)
		{
			SlTxNum_ = BlockPos.x + BlockPos.y * Size.x;
		}
	}

}


// TextureSize取得
Vector2 TextureBox::GetTextureSize()
{
	return TextureSize_;
}

int TextureBox::GetSlTxNum()
{
	return 0;
}

void TextureBox::SetTexture(std::string FileName)
{
	
	if (FileName == "")
	{
		std::cout << "failed load texture!" << std::endl;
		return;
	}
	auto shTx = txFcty_.GetTexture_(FileName);
	if (shTx->GetGrHandle() == -1)
	{
		std::cout << "failed load texture!" << std::endl;
		return;
	}
	auto it = TextureNmList_.find(FileName);
	if (it == TextureNmList_.end())
	{
		TextureNmList_.emplace(FileName);
		txHdl_.emplace_back(shTx);
		if (pos_.x + txHdl_.back()->GetSize().x * (txHdl_.size() - 1) > SCREEN_SIZE_X)
		{
			pos_.y += STCI(txHdl_.size());
			TextureCount_.x = 0;
			TextureCount_.y++;
		}
		txPos_.emplace_back(Position2(pos_.x+ txHdl_.back()->GetSize().x * (txHdl_.size() - 1), pos_.y));
		TextureSize_ = txHdl_.back()->GetSize();
		TextureCount_.x++;
	}
	std::cout << "successed load texture!" << std::endl;
}


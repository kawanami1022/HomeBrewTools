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
	SlTxNum_ = 1;
	pos_ = Vector2(32 + 850, 220);
	TextureSize_ = { 0,0 };
	TextureCount_ = { 0,0 };
	//0ÇÃìYÇ¶éöâΩÇ‡ï`âÊÇ≥ÇπÇΩÇ≠Ç»Ç¢ÇÃÇ≈0Çì¸ÇÍÇƒÇ®Ç≠
	txHdl_.emplace_back(nullptr);
	txPos_.emplace_back(Vector2(0, 0));
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
		if(!(txHdl_.size()<=1)&&idx>0)
		DrawGraph(txPos_[idx].x, txPos_[idx].y, TXHDL->GetGrHandle(), true);
		idx++;
	}
	// slTxNumÇ™0ÇÃéûÇÕï`âÊÇ≥ÇπÇ»Ç¢
	if (txHdl_.size() > 1&& SlTxNum_!=0)
		DxLib_Draw::DrawBoxLineEOff(txPos_[SlTxNum_].x, txPos_[SlTxNum_].y,
			txHdl_[SlTxNum_]->GetSize().x, txHdl_[SlTxNum_]->GetSize().y, 0x00ff00);
}

//É}ÉEÉXÇÃç¿ïWÇ≈éØï 
void TextureBox::InMousePosIdnt()
{


	Vector2 MousePos = mPos_[0] - pos_;
	if (MousePos < 0)return;
	if (TextureSize_.x == 0 || TextureSize_.y == 0)return;

	Vector2 Size = TextureCount_;
	Vector2 BlockPos = MousePos / TextureSize_;
	int TmpNum=BlockPos.x + BlockPos.y * Size.x;

	if (TmpNum < txHdl_.size())
	{
		SlTxNum_ = BlockPos.x + BlockPos.y * Size.x;
	}

}


// TextureSizeéÊìæ
Vector2 TextureBox::GetTextureSize()
{
	return TextureSize_;
}

int TextureBox::GetSlTxNum()
{
	return SlTxNum_;
}

SharTexture TextureBox::GetTxHdl()
{
	return txHdl_[txHdl_.size()];
}

bool TextureBox::SetTexture(std::string FileName)
{
	
	if (FileName == "")
	{
		std::cout << "failed load texture!" << std::endl;
		return false;
	}

	auto shTx = txFcty_.GetTexture_(FileName);
	if (shTx->GetGrHandle() == -1)
	{
		std::cout << "failed load texture!" << std::endl;
		return false;
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
	return true;
}


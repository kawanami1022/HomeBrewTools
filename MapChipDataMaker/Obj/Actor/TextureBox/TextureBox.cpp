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
	//0�̓Y���������`�悳�������Ȃ��̂�0�����Ă���
	txHdl_.emplace_back(nullptr);
	txPos_.emplace_back(Vector2(0, 0));
	TextureNmList_.push_back("");
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
	// slTxNum��0�̎��͕`�悳���Ȃ�
	if (txHdl_.size() > 1&& SlTxNum_!=0&& SlTxNum_!= txHdl_.size())
		DxLib_Draw::DrawBoxLineEOff(txPos_[SlTxNum_].x, txPos_[SlTxNum_].y,
			txHdl_[SlTxNum_]->GetSize().x, txHdl_[SlTxNum_]->GetSize().y, 0x00ff00);
}

//�}�E�X�̍��W�Ŏ���
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
		SlTxNum_ = SlTxNum_ < 0 ?  0 : TmpNum + 1;
	}
}

void TextureBox::DivTexture()
{

	int x, y;
	if (TextureNmList_.size() > 1)
	{

		std::cout << "plaease input width num" << std::endl;
		std::cin>> x;
		std::cout << "plaease input hight num" << std::endl;
		std::cin>> y;
		auto shTx = txFcty_.CreateDivTexture_(TextureNmList_[1], x, y);
		txHdl_.erase(txHdl_.begin() + 1);			// delete the first one Handle
		txPos_.erase(txPos_.begin() + 1);
		setPos_ = pos_;
		for (auto&& SHTX : shTx)
		{
			txHdl_.emplace_back(SHTX);
			if (txPos_.size() > 1)
			{
				setPos_.x += txHdl_.back()->GetSize().x;
				if (SCREEN_SIZE_X < setPos_.x)
				{	setPos_.x = pos_.x;
					setPos_.y += txHdl_.back()->GetSize().y;
					TextureCount_.y++;
					TextureCount_.x = 0;
				}
				TextureCount_.x++;
			}
			txPos_.emplace_back(setPos_);

			TextureSize_ = txHdl_.back()->GetSize();
		}
	}
	else {
		std::cout << "Non Texture" << std::endl;
	}
}



// TextureSize�擾
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


	TextureNmList_.emplace_back(FileName);
	txHdl_.emplace_back(shTx);
	if (pos_.x + txHdl_.back()->GetSize().x * (txHdl_.size() - 1) > SCREEN_SIZE_X)
	{
		pos_.y += STCI(txHdl_.size());
		TextureCount_.x = 0;
		TextureCount_.y++;
	}
		

	txPos_.emplace_back(Position2(pos_.x+ txHdl_.back()->GetSize().x * (txHdl_.size() - 2), pos_.y));

	TextureSize_ = txHdl_.back()->GetSize();
	TextureCount_.x++;

	std::cout << "successed load texture!" << std::endl;
	return true;
}


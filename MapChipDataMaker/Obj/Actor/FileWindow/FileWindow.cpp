#include <iostream>
#include <string>
#include <DxLib.h>
#include "FileWindow.h"
#include "../../../FileControl/FileControl.h"
#include "../../../Vector2/Vector2.h"
#include "../../../DxLibForHomeBrew/DxLib_Draw.h"
#include "../../../input/controller.h"
#include "../../../input/mouse.h"
#include "../../../Collision2D/collision2D.h"
#include "../TextureBox/TextureBox.h"
#include "FlWnUpDt/NON.h"
#include "FlWnUpDt/CONVERT_TXT.h"
#include "FlWnUpDt/IMPORT_TXT.h"
#include "FlWnUpDt/REMOVE_TEXTURE.h"
#include "FlWnUpDt/SET_GRAPH_SIZE.h"
#include "FlWnUpDt/SET_TEXTURE.h"

FileWindow::FileWindow()
{
	btnType_ = BUTTON_TYPE::NON;
	pos_ = Vector2(32 + 850, 0);
	size_ = Vector2(1200 - pos_.x, 220);
	txFc_ = std::make_unique<TextureFactory>();
	txNmList_ = { "","UI/SetTexture.png","UI/RemoveTexture.png","UI/CONVERT_TXT.png","UI/IMPORT.png", "UI/SET_GRAPH_SIZE.png"};
	for (auto&& TXLIST : txNmList_)
	{textureList_.emplace_back(txFc_->GetTexture_(TXLIST));}

	btn_.emplace_back(Button(textureList_[0], Vector2(9, 8), Vector2(pos_)));
	btn_.emplace_back(Button(textureList_[1], Vector2(9, 8), Vector2(pos_)));
	btn_.emplace_back(Button(textureList_[2], Vector2(9, textureList_[2]->GetSize().y * 1 + 8), Vector2(pos_)));
	btn_.emplace_back(Button(textureList_[3], Vector2(9, textureList_[3]->GetSize().y * 2 + 8), Vector2(pos_)));
	btn_.emplace_back(Button(textureList_[4], Vector2(9, textureList_[4]->GetSize().y * 3 + 8), Vector2(pos_)));
	btn_.emplace_back(Button(textureList_[5], Vector2(9, textureList_[5]->GetSize().y * 4 + 8), Vector2(pos_)));

	upDt.try_emplace(BUTTON_TYPE::NON, NON());
	upDt.try_emplace(BUTTON_TYPE::CONVERT_TXT, CONVERT_TXT());
	upDt.try_emplace(BUTTON_TYPE::IMPORT_TXT, IMPORT_TXT());
	upDt.try_emplace(BUTTON_TYPE::REMOVE_TEXTURE, REMOVE_TEXTURE());
	upDt.try_emplace(BUTTON_TYPE::SET_GRAPH_SIZE, SET_GRAPH_SIZE());
	upDt.try_emplace(BUTTON_TYPE::SET_TEXTURE, SET_TEXTURE());
	frame = 0;
}

void FileWindow::Input()
{

}

void FileWindow::Update()
{
	upDt[btnType_](*this);
	frame++;
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

}

void FileWindow::changeButtonType()
{
	int idx = 0;
	for (auto BTN_TYPE : btn_)
	{
		if (Collision2D::IsHitABB(mPos_[0], { BTN_TYPE.GetPos().x,BTN_TYPE.GetPos().y, 
										textureList_[idx]->GetSize().x,
										textureList_[idx]->GetSize().y }))
		{
			btnType_ = static_cast<BUTTON_TYPE>(idx);
			frame = 0;
		}
		idx++;
	}
	mPos_[0] = { 0,0 };
}

void FileWindow::InputTextureDir()
{
	std::string FileName;
	std::cout << "please input Txture's directory" << std::endl;
	std::cin >> FileName_;
	
}

void FileWindow::InputDirTxtDir()
{
}

BUTTON_TYPE FileWindow::GetButtonType()
{
	return btnType_;
}

std::string FileWindow::GetTextureName()
{
	return FileName_;
}

void FileWindow::SetTextureName(BUTTON_TYPE btnType)
{
	btnType_ = btnType;
}





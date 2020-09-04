#include <iostream>
#include <DxLib.h>
#include "ChipDataView.h"
#include "../../../FileControl/FileControl.h"
#include "../../../DxLibForHomeBrew/DxLib_Draw.h"
#include "../../../Collision2D/collision2D.h"
#include "BUTTON_TYPE/BUTTON_TYPE_BOX.h"
#include "BUTTON_TYPE/BUTTON_TYPE_BOX_FILL.h"
#include "BUTTON_TYPE/BUTTON_TYPE_ERASE.h"
#include "BUTTON_TYPE/BUTTON_TYPE_PEN.h"
#include "../../../Vector2/Vector2.h"

ChipDataView::ChipDataView(Vector2 Size_, Vector2 GridCount):GridSize_(Size_), GridCount_(GridCount)
{
	pos_ = { 32,0 };
	size_ = { 850,800 };
	GrHandleList_.push_back(texFactory_.GetTexture_("UI/size.png"));
	Percent_ = 100;
	GridSize_ = { 0,0 };
	buttonMode_ = Button_Type::Pen;		// ペンツールに初期化しておく
	//
	InitChipData();
	InitChipDataBoxFunc();

}

ChipDataView::~ChipDataView()
{

}

void ChipDataView::Input()
{
}


void ChipDataView::Update()
{

}

// chipDataを編集する
void ChipDataView::EditChipData()
{
	if(Collision2D::IsHitABB(mousePos_[0], { pos_.x,pos_.y,
										GridSize_.x * GridCount_.x * Percent_ / 100 + 1,
										GridSize_.y * GridCount_.y * Percent_ / 100 + 1 }))
	{
		chipDataBoxFunc[buttonMode_]((*this));
	}
}

void ChipDataView::Draw()
{
	for (int y = 0; y < GridCount_.y; y++) {
		for (int x = 0; x < GridCount_.x; x++) {
			DxLib_Draw::DrawBoxLineEOff(pos_.x+(GridSize_.x*x)*Percent_/100, pos_.y+(GridSize_.y*y) * Percent_ / 100,
				GridSize_.x * Percent_ / 100+1, GridSize_.y * Percent_ / 100+1, 0xffffff);
		}
	}
	DrawGraph(pos_.x + size_.x-GrHandleList_[0]->GetSize().x, 
		pos_.y + size_.y - GrHandleList_[0]->GetSize().y,
		GrHandleList_[0]->GetGrHandle(), true);
	DrawFormatString(pos_.x + size_.x-50,
		pos_.y + size_.y-21,
		0x000000, "%d %", Percent_);

	DxLib_Draw::DrawBoxLineEOff(pos_.x, pos_.y,
		size_.x, size_.y, 0x888888);


}

void ChipDataView::DrawImage(TextureBox& TxBox)
{
	// Griddataのサイズが0の時終了
	if (GridData_.size() == 0)return;

	for (int y = 0; y < GridCount_.y; y++) {
		for (int x = 0; x < GridCount_.x; x++) {
			// GridDataが0の時描画させない
			if (GridData_[y][x] != 0)
			DxLib_Draw::DrawExGraphEOff(pos_.x + (GridSize_.x * x) * Percent_ / 100, pos_.y + (GridSize_.y * y) * Percent_ / 100,
				GridSize_.x * Percent_ / 100 + 1, GridSize_.y * Percent_ / 100 + 1, TxBox.txHdl_[GridData_[y][x]]->GetGrHandle());

		}
	}
}

void ChipDataView::PercentBox()
{

	if (Collision2D::IsHitABB(mousePos_[0],
		{ pos_.x + size_.x - GrHandleList_[0]->GetSize().x,
		pos_.y + size_.y - GrHandleList_[0]->GetSize().y,
		 size_.x ,size_.y }))
	{
		if (mouseDiff_.x < 0)
		{
			Percent_-=10;
		}
		else if (mouseDiff_.x > 0)
		{
			Percent_+=10;
		}
	}
}

void ChipDataView::SetMousePos(TrgPos mousePos)
{
	mousePos_ = mousePos;
}

void ChipDataView::SetMouseDiff(Vector2 mouseDiff)
{
	mouseDiff_ = mouseDiff;
}

void ChipDataView::SetGridSize(Vector2 TextureSize)
{
	GridSize_ = TextureSize;
}

void ChipDataView::SetSlTxNum(int SlTxNum)
{
	SlTxNum_ = SlTxNum;
}

void ChipDataView::SetButtonMode(Button_Type btnType)
{
	buttonMode_ = btnType;
}

void ChipDataView::InitChipData()
{
	int idx = 0;
	GridDataBase_.reserve(static_cast<size_t>(GridCount_.x * GridCount_.y));
	// 0に初期化させる
	for (int y = 0; y < GridCount_.y; y++) {
		for (int x = 0; x < GridCount_.x; x++) {
			GridDataBase_.emplace_back(0);
			idx++;
		}
	}

	for (int i = 0; i < GridCount_.y; i++)
	{
		GridData_.emplace_back(
			&GridDataBase_[i * GridCount_.x]);

	}
}

void ChipDataView::InitChipDataBoxFunc()
{
	chipDataBoxFunc.try_emplace(Button_Type::Pen, BUTTON_TYPE_PEN());
	chipDataBoxFunc.try_emplace(Button_Type::Eraser, BUTTON_TYPE_ERASE());
	chipDataBoxFunc.try_emplace(Button_Type::Box, BUTTON_TYPE_BOX());
	chipDataBoxFunc.try_emplace(Button_Type::Box_Fill, BUTTON_TYPE_BOX_FILL());

}

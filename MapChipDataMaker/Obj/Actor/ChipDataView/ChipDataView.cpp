#include <iostream>
#include <DxLib.h>
#include "ChipDataView.h"
#include "../../../DxLibForHomeBrew/DxLib_Draw.h"
#include "../../../Collision2D/collision.h"

ChipDataView::ChipDataView(Vector2 Size_, Vector2 GridCount):GridSize(Size_), GridCount(GridCount)
{
	pos_ = { 32,0 };
	size_ = { 850,800 };
	GrHandleList_.push_back(texFactory_.GetTexture_("UI/size.png"));
	Percent_ = 100;
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

void ChipDataView::Draw()
{
	for (int y = 0; y < GridCount.y; y++) {
		for (int x = 0; x < GridCount.x; x++) {
			DxLib_Draw::DrawBoxLineEOff(pos_.x+(GridSize.x*x)*Percent_/100, pos_.y+(GridSize.y*y) * Percent_ / 100,
				GridSize.x * Percent_ / 100+1, GridSize.y * Percent_ / 100+1, 0xffffff);
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

void ChipDataView::PercentBox()
{
	int mousePos[2] = { mousePos_[static_cast<int>(Trg::Now)].x,mousePos_[static_cast<int>(Trg::Now)].y };
	int percentButtonLU[2] = { pos_.x + size_.x - GrHandleList_[0]->GetSize().x,
							pos_.y + size_.y - GrHandleList_[0]->GetSize().y };
	int percentButtonRD[2] = { pos_.x + size_.x ,pos_.y + size_.y };
	// percentbutton
	if (checkPInRect(mousePos, percentButtonLU, percentButtonRD))
	{
		//Percent_? mouseDiff_.x<0
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

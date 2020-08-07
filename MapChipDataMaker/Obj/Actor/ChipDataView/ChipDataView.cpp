#include <iostream>
#include <DxLib.h>
#include "ChipDataView.h"
#include "../../../DxLibForHomeBrew/DxLib_Draw.h"

ChipDataView::ChipDataView(Vector2I Size_, Vector2I GridCount):GridSize(Size_), GridCount(GridCount)
{
	pos_ = { 32,0 };
	size_ = { 850,800 };
}

ChipDataView::~ChipDataView()
{

}

void ChipDataView::Update()
{

}

void ChipDataView::Draw()
{
	for (int y = 0; y < GridCount.y; y++) {
		for (int x = 0; x < GridCount.x; x++) {
			DxLib_Draw::DrawBoxLineEOff(pos_.x+GridSize.x*x, pos_.y+GridSize.y*y,
				GridSize.x, GridSize.y, 0xffffff);
		}
	}
	DxLib_Draw::DrawBoxLineEOff(pos_.x, pos_.y,
		size_.x, size_.y, 0x888888);
}

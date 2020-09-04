#pragma once
#include "../ChipDataView.h"
struct BUTTON_TYPE_PEN
{
	void operator()(ChipDataView& chDtView)
	{

		Position2 tmpMPos = chDtView.mousePos_[0]-chDtView.pos_;		// �}�E�X�̍��W
		Position2 GridPos;
		GridPos.x = static_cast<int>(tmpMPos.x / static_cast<float>((chDtView.GridSize_.x * (chDtView.Percent_ / 100))));			// �O���b�h���W
		GridPos.y = static_cast<int>(tmpMPos.y / static_cast<float>((chDtView.GridSize_.y * (chDtView.Percent_ / 100))));			// �O���b�h���W

		if (chDtView.GridCount_ <= GridPos)return;
		chDtView.GridData_[GridPos.y][GridPos.x] = chDtView.SlTxNum_;
	}
};
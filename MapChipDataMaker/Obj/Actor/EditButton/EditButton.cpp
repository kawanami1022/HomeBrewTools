#include <DxLib.h>
#include "EditButton.h"
#include "../../../Collision2D/collision.h"
void EditButton::Init()
{
	EditBtnType.emplace_back(Button_Type::Pen);
	EditBtnType.emplace_back(Button_Type::Eraser);

	EditBtnHandle = { {Button_Type::Pen,LoadGraph("UI/Pen.png")},
					{Button_Type::Eraser,LoadGraph("UI/Eraser.png")},
					{Button_Type::Box,LoadGraph("UI/fillBox_NonFill.png")},
					{Button_Type::Box_Fill,LoadGraph("UI/fillBox.png")} };
	buttonMode = Button_Type::Pen;
}

void EditButton::Input()
{
}

void EditButton::Update()
{

}

void EditButton::Draw()
{
	int count = 0;
	for (auto btnID : EditBtnHandle)
	{
		SetDrawBright(0xff, 0xff, 0xff);
		if (buttonMode != btnID.first)
		{
			SetDrawBright(0x44, 0x44, 0x44);
		}
		DrawGraph(0, size * count, btnID.second, true);
		count++;
	}
	SetDrawBright(0xff, 0xff, 0xff);
}

void EditButton::changeButtonType()
{
	int mPos[2] = { mPos_[0].x,mPos_[0].y };
	for (auto btnID : EditBtnHandle)
	{
		int edtBtnPos[2] = { 0,size * static_cast<int>(btnID.first) };
		int edtBtnSize[2] = { size,size * static_cast<int>(btnID.first) + size };
		if (checkPInRect(mPos, edtBtnPos, edtBtnSize))
		{
			buttonMode = btnID.first;
			break;
		}
	}
}


Button_Type EditButton::GetBtnMode()
{
	return buttonMode;
}



EditButton::EditButton():size(32)
{
	Init();
}

#include <DxLib.h>
#include "EditButton.h"
#include "../../../Collision2D/collision2D.h"
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
	for (auto btnID : EditBtnHandle)
	{
		if (Collision2D::IsHitABB({ mPos_[0].x,mPos_[0].y }, 
			{ 0, size * static_cast<int>(btnID.first), size, size }))
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

#include <DxLib.h>
#include "EditButton.h"

void EditButton::Init()
{
	EditBtnType.emplace_back(Button_Type::Pen);
	EditBtnType.emplace_back(Button_Type::Eraser);

	EditBtnHandle = { {Button_Type::Pen,LoadGraph("UI/Pen.png")},
					{Button_Type::Eraser,LoadGraph("UI/Eraser.png")},
					{Button_Type::Box,LoadGraph("UI/fillBox_NonFill.png")},
					{Button_Type::Box_Fill,LoadGraph("UI/fillBox.png")} };
}

void EditButton::update()
{
}

void EditButton::draw()
{
	int count = 0;
	for (auto btnID : EditBtnHandle)
	{
		DrawGraph(0, size * count, btnID.second, true);
		count++;
	}
}

EditButton::EditButton():size(32)
{
	Init();
}

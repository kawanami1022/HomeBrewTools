#pragma once
#include <map>
#include <vector>
#include "../Actor.h"

enum class Button_Type
{
	Pen,
	Eraser,
	Box,
	Box_Fill,
	Max,
};


class EditButton :public Actor
{
public:
	EditButton();
	void Init();
	void update();
	void draw();
private:
	std::vector<Button_Type> EditBtnType;
	std::map<Button_Type,int> EditBtnHandle;
	const int size;
};


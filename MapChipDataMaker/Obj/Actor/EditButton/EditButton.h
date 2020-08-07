#pragma once
#include <array>
#include <map>
#include <vector>
#include "../../../input/InputID.h"
#include "../../../Vector2/Vector2.h"
#include "../Actor.h"
enum class Button_Type
{
	Pen,
	Eraser,
	Box,
	Box_Fill,
	Max,
};

using ButtonFlag=std::map<Button_Type, bool>;
class EditButton :public Actor
{
public:
	EditButton();
	void Init();
	void Update()override;
	void Draw()override;
	void changeButtonType();

	// setter
	void setMousePos(Position2 Pos_);

	// getter
	Button_Type GetBtnMode();
private:
	std::vector<Button_Type> EditBtnType;
	std::map<Button_Type,int> EditBtnHandle;
	const int size;
	Position2 mPos_;
	Button_Type buttonMode;
};


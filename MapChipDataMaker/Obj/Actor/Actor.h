#pragma once
#include "../Obj.h"
#include "../../input/controller.h"
#define STCI static_cast<int>
class Actor :public Obj
{
public:
	virtual void Input() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	// setter
	void setMousePos(TrgPos Pos_);
protected:
	TrgPos mPos_;
};


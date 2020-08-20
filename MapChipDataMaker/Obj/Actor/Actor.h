#pragma once
#include "../Obj.h"
#include "../../input/controller.h"
class Actor :public Obj
{
public:
	virtual void Input() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
protected:
};


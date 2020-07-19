#pragma once
#include <vector>

enum class InputState
{
	Now,
	Old,
	MAX
};

class Controller
{
public:
	virtual void setInputTbl()=0;
	virtual void update() = 0;
private:
	
};


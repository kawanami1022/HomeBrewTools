#pragma once
#include <cstdlib>
#include <memory>
#include "../Input/Mouse.h"

//#define lpBaseScene std::unique_ptr<BaseScene>
class BaseScene;
using unique_Base = std::unique_ptr<BaseScene>;

class BaseScene
{
public:
	virtual unique_Base Input(unique_Base)=0;
	virtual unique_Base upDate(unique_Base)=0;
	virtual void Draw()=0;
	virtual bool sysInit() = 0;
	BaseScene();
	~BaseScene();
protected:
	std::unique_ptr<Controller> input;
private:

};


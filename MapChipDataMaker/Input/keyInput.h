#pragma once
#include <array>
#include "controller.h"

struct KeyInput:public controller
{
	ContType GetType(void) override;
	bool Setup() override;	// プレーヤーのnumber
	void Update(void) override;
private:
	std::array<char, 256> _keyData;
	std::map<InputID, int> _InputTbl;
};
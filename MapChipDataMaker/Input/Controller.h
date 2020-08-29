#pragma once
#include <array>
#include <map>
#include "../Vector2/Vector2.h"
#include "InputID.h"
enum class Trg
{
	Now,
	Old,
	Max
};


//入力装置の種類
enum class ContType
{
	Key,
	Mouse,
	Pad,
	Max
};

using TrgBool = std::array<bool, static_cast<int>(Trg::Max)>;
using CntData = std::map<InputID, TrgBool>;
using TrgPos = std::array<Vector2, static_cast<int>(Trg::Max)>;

struct controller
{
	void operator()()
	{
		Update();
	}

	const CntData& GetCntData(void)
	{
		return _data;
	}

	TrgPos mousePos_;
	Vector2 mouseOffSize;		// 移動量
	virtual ContType GetType(void) = 0;
	virtual bool Setup() = 0;	// プレーヤーのnumber
	virtual bool Push(InputID)=0;
	virtual bool Sepatate(InputID) = 0;
	virtual bool Release(InputID) = 0;
	virtual bool Hold(InputID) = 0;
	virtual TrgPos getMousePos(void) = 0;
	virtual Vector2 getMouseOffSize(void) = 0;
protected:
	Position2 pos;
	CntData _data;

private:
	virtual void Update(void) = 0;
};

#pragma once
#include "../Vector2/Vector2.h"
#include "controller.h"
#include "mouseID.h"

using M_CntDt = std::map<MouseID, TrgBool>;

struct mouse :
	public controller
{
public:

	bool Setup() override;
	ContType GetType(void) override;
	Position2 getMousePos(void) override;
	int MouseInput_;
	virtual bool Push(InputID)override;
	virtual bool Sepatate(InputID)override;
	virtual bool Release(InputID)override;
	virtual bool Hold(InputID)override;
protected:
	std::array<int, 3> _mouseData;
	std::map<InputID, int> _mouseInputTbl;

private:

	void Update() override;
};


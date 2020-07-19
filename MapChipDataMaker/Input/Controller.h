#pragma once
#include <vector>



class Controller
{
public:
	void operator()() {
		update();
	}
	virtual void setInputTbl()=0;
	std::vector<int> inputTblNow_;
	std::vector<int> inputTblOld_;

protected:
	virtual void update() = 0;
private:
	
};


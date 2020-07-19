#pragma once
#include <array>
#include "Controller.h"
class keyInput :
    public Controller
{
public:
    void setInputTbl()override;
protected:
    void update()override;
private:
    std::array<char, 256>keyState;
};


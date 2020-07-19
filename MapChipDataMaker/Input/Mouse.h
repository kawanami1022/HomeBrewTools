#pragma once
#include "InputID.h"
#include "Controller.h"


class Mouse :
    public Controller
{
public:
    void setInputTbl()override;

protected:
    void update()override;
private:
    int mouseInput;
};


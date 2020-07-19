#pragma once
#include <DxLib.h>
#include "Controller.h"
class keyInput :
    public Controller
{
public:
    void update()override;
};


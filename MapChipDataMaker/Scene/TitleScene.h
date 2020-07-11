#pragma once
#include "BaseScene.h"
#include "../Vector2/Vector2.h"

class TitleScene :
    public BaseScene
{
public:
    unique_Base Input(unique_Base);
    unique_Base upDate(unique_Base);
    void Draw();
    TitleScene();
    ~TitleScene();
    Vector2I ToolBoxPos;
    Vector2I ToolBoxSize;
    Vector2I ToolBoxPos;
    Vector2I ChipGraphSize;
    Vector2I mapChipPos;
    Vector2I mapChipSize;
private:
    bool sysInit();
};


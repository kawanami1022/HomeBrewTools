#pragma once
#include <memory>
#include "BaseScene.h"
#include "../Vector2/Vector2.h"
#include "../Obj/Actor/EditButton/EditButton.h"

class EditScene :
    public BaseScene
{
public:
    unique_Base Input(unique_Base);
    unique_Base upDate(unique_Base);
    void Draw();
    EditScene();
    ~EditScene();


    Position2 ToolBoxPos;
    Position2 ToolBoxSize;
    Position2 ChipGraphPos;
    Position2 ChipGraphSize;
    Position2 mapChipPos;
    Position2 mapChipSize;
    Position2 ButtonPos;
    Position2 ButtonSize;
    Position2 RefDirPos;
    Position2 RefDirSize;
    
private:
    std::unique_ptr<EditButton> EdtBtn;
    bool sysInit();
};


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


    Vector2I ToolBoxPos;
    Vector2I ToolBoxSize;
    Vector2I ChipGraphPos;
    Vector2I ChipGraphSize;
    Vector2I mapChipPos;
    Vector2I mapChipSize;
    Vector2I ButtonPos;
    Vector2I ButtonSize;
    Vector2I RefDirPos;
    Vector2I RefDirSize;

private:
    std::unique_ptr<EditButton> EdtBtn;
    bool sysInit();
};


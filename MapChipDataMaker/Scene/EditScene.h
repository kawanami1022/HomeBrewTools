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
    

private:
    std::unique_ptr<EditButton> EdtBtn;
    bool sysInit();
};


#include <iostream>
#include <memory>
#include <utility>
#include <mutex>
#include <DxLib.h>
#include "TitleScene.h"
#include "../Obj/Actor/EditButton/EditButton.h"

unique_Base EditScene::Input(unique_Base nowScene)
{
    return std::move(nowScene);
}

unique_Base EditScene::upDate(unique_Base nowScene)
{

    return std::move(nowScene);
}

void EditScene::Draw()
{
    ClsDrawScreen();
    //DrawBox(ToolBoxPos.x, ToolBoxPos.y,
    //    ToolBoxPos.x + ToolBoxSize.x, ToolBoxPos.y + ToolBoxSize.y, 0x880000, true);
    DrawBox(mapChipPos.x, mapChipPos.y,
        mapChipPos.x + mapChipSize.x, mapChipPos.y + mapChipSize.y, 0x008800, true);
    DrawBox(ChipGraphPos.x, ChipGraphPos.y,
        ChipGraphPos.x + ChipGraphSize.x, ChipGraphPos.y + ChipGraphSize.y, 0x000088, true);
    EdtBtn->draw();
    ScreenFlip();
}

bool EditScene::sysInit()
{
    ToolBoxPos={ 0,0 };
    ToolBoxSize={ 40,40*24 };
    mapChipPos = { 40,0 };
    mapChipSize = { 900,800 };
    ChipGraphPos = { 940,64 };
    ChipGraphSize = { 260,64*9 };
    EdtBtn=std::make_unique<EditButton>();

    return true;
}

EditScene::EditScene()
{
    sysInit();
}

EditScene::~EditScene()
{
}

#include <iostream>
#include <memory>
#include <utility>
#include <mutex>
#include <DxLib.h>
#include "EditScene.h"
#include "../Obj/Actor/EditButton/EditButton.h"
unique_Base EditScene::Input(unique_Base nowScene)
{
    (*input)();
    for (auto&& data : input->GetCntData())
    {
    }

    if (input->Push(InputID::Left)==true)
    {
        EdtBtn->setMousePos(input->getMousePos());
        EdtBtn->changeButtonType();
    }
    return std::move(nowScene);
}

unique_Base EditScene::upDate(unique_Base nowScene)
{
    chipDataView->Update();
    return std::move(nowScene);
}

void EditScene::Draw()
{
    ClsDrawScreen();
    EdtBtn->Draw();
    chipDataView->Draw();
    ScreenFlip();
}

bool EditScene::sysInit()
{
    // ActorClassèâä˙âª
    EdtBtn = std::make_unique<EditButton>();
    chipDataView = std::make_unique<ChipDataView>(Vector2I(32,32),Vector2I(12,6));

    input = std::make_unique<mouse>();
    input->Setup();
    return true;
}

EditScene::EditScene()
{
    sysInit();
}

EditScene::~EditScene()
{
}

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
    return std::move(nowScene);
}

void EditScene::Draw()
{
    ClsDrawScreen();
    EdtBtn->draw();
    ScreenFlip();
}

bool EditScene::sysInit()
{
    EdtBtn=std::make_unique<EditButton>();
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

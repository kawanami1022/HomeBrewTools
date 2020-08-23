#include <iostream>
#include <memory>
#include <utility>
#include <mutex>
#include <DxLib.h>
#include "EditScene.h"
#include "../Obj/Actor/EditButton/EditButton.h"
#include "../Obj/Actor/EditButton/EditButton.h"
#include "../Obj/Actor/ChipDataView/ChipDataView.h"
#include "../Obj/Actor/FileWindow/FileWindow.h"

// ì¸óÕ
unique_Base EditScene::Input(unique_Base nowScene)
{
    (*input)();
    for (auto&& data : input->GetCntData())
    {
    }

    if (input->Push(InputID::Left) == true)
    {
        fileWindow_->setMousePos(input->getMousePos());
        EdtBtn_->setMousePos(input->getMousePos());
        EdtBtn_->changeButtonType();
    }
    if (input->Hold(InputID::Left) == true)
    {
        chipDataView_->PercentBox();
    }

    // setter
    chipDataView_->SetMousePos(input->mousePos_);
    chipDataView_->SetMouseDiff(input->getMouseOffSize());

    return std::move(nowScene);
}

unique_Base EditScene::upDate(unique_Base nowScene)
{
    chipDataView_->Update();
    fileWindow_->Update();
    return std::move(nowScene);
}

void EditScene::Draw()
{
    ClsDrawScreen();
    EdtBtn_->Draw();
    chipDataView_->Draw();
    fileWindow_->Draw();
    ScreenFlip();
}

bool EditScene::sysInit()
{
    // ActorClassèâä˙âª
    EdtBtn_ = std::make_unique<EditButton>();
    chipDataView_ = std::make_unique<ChipDataView>(Vector2(32,32),Vector2(12,6));
    fileWindow_ = std::make_unique<FileWindow>();
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

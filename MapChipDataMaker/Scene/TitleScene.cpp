#include <iostream>
#include <memory>
#include <utility>
#include <mutex>
#include <DxLib.h>
#include "TitleScene.h"


unique_Base TitleScene::Input(unique_Base nowScene)
{
    return std::move(nowScene);
}

unique_Base TitleScene::upDate(unique_Base nowScene)
{
    return std::move(nowScene);
}

void TitleScene::Draw()
{
    ClsDrawScreen();
    ScreenFlip();
}

bool TitleScene::sysInit()
{

    return false;
}

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

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
#include "../Obj/Actor/TextureBox/TextureBox.h"

// 入力
unique_Base EditScene::Input(unique_Base nowScene)
{
    (*input)();
    for (auto&& data : input->GetCntData())
    {
    }



    if (input->Push(InputID::Left) == true)
    {
        // EditButton
        EdtBtn_->setMousePos(input->getMousePos());
        EdtBtn_->changeButtonType();
        // FileWidow
        fileWindow_->SetChipDtVw((*chipDataView_));
        fileWindow_->setMousePos(input->getMousePos());
        fileWindow_->changeButtonType();

        // TextureBox
        textureBox_->setMousePos(input->getMousePos());
        textureBox_->InMousePosIdnt();

        // ChipDataView
        chipDataView_->SetGridSize(textureBox_->GetTextureSize());
        chipDataView_->SetSlTxNum(textureBox_->GetSlTxNum());
        chipDataView_->SetButtonMode(EdtBtn_->GetBtnMode());
        chipDataView_->EditChipData();
    }

    

    if (input->Hold(InputID::Left) == true)
    {
        chipDataView_->EditChipData();
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
    

    // 画像読み込み
    if (fileWindow_->GetButtonType() == BUTTON_TYPE::SET_TEXTURE)
    {
        fileWindow_->InputTextureDir();
        if (textureBox_->SetTexture(fileWindow_->GetTextureName()))
        {

        }
        fileWindow_->SetButtonType(BUTTON_TYPE::NON);
    }

    // 画像読み込み
    if (fileWindow_->GetButtonType() == BUTTON_TYPE::CONVERT_TXT)
    {
        if (fileWindow_->ConvertMapDtForTxt((*chipDataView_)))
        {fileWindow_->ConvertTxBoxDtForTxt((*textureBox_));}
        fileWindow_->SetButtonType(BUTTON_TYPE::NON);
    }

    // 画像分割
    if (fileWindow_->GetButtonType() == BUTTON_TYPE::DIV_TEXTURE)
    {
        textureBox_->DivTexture();
        fileWindow_->SetButtonType(BUTTON_TYPE::NON);
    }
    // change tile size
    if (fileWindow_->GetButtonType() == BUTTON_TYPE::CHANGE_TILE_SIZE)
    {
        chipDataView_->ChangeTileSize();
        fileWindow_->SetButtonType(BUTTON_TYPE::NON);
    }
    return std::move(nowScene);
}

void EditScene::Draw()
{
    ClsDrawScreen();
    EdtBtn_->Draw();
    chipDataView_->Draw();
    chipDataView_->DrawImage((*textureBox_));
    fileWindow_->Draw();
    textureBox_->Draw();
    ScreenFlip();
}

bool EditScene::sysInit()
{
    // ActorClass初期化
    EdtBtn_ = std::make_unique<EditButton>();
    chipDataView_ = std::make_unique<ChipDataView>(Vector2(32,32),Vector2(12,6));
    fileWindow_ = std::make_unique<FileWindow>();
    input = std::make_unique<mouse>();
    textureBox_ = std::make_unique<TextureBox>();
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

#pragma once
#include <memory>
#include "BaseScene.h"
#include "../Vector2/Vector2.h"


class EditButton;
class ChipDataView;
class FileWindow;
class TextureBox;

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
    std::unique_ptr<EditButton> EdtBtn_;
    std::unique_ptr<ChipDataView> chipDataView_;
    std::unique_ptr<FileWindow> fileWindow_;
    std::unique_ptr<TextureBox> textureBox_;
    bool sysInit();
};


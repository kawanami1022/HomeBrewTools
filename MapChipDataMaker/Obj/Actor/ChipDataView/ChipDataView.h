#pragma once
#include <functional>
#include <vector>
#include "../../../Texture/TextureFactory.h"
#include "../../../Texture/Texture.h"
#include "../Actor.h"
#include "../TextureBox/TextureBox.h"
#include "../EditButton/EditButton.h"

class ChipDataView :
    public Actor
{
public:
    ChipDataView(Vector2 Size_, Vector2 GridCount);
    ~ChipDataView();
    void Input()override;
    void Update()override;
    void EditChipData();
    void Draw()override;
    void DrawImage(TextureBox&);

    // input
    void PercentBox();

    // setter
    void SetMousePos(TrgPos);
    void SetMouseDiff(Vector2);
    void SetGridSize(Vector2);
    void SetSlTxNum(int);
    void SetButtonMode(Button_Type);
    //init
    void InitChipData();
    void InitChipDataBoxFunc();
private:
    std::map<Button_Type, std::function<void(ChipDataView&)>> chipDataBoxFunc;       // �X�V����

    TextureFactory texFactory_;
    std::vector<SharTexture> GrHandleList_;
    std::vector<int> GridDataBase_;             //�O���b�h�f�[�^
    std::vector<int*> GridData_;             //�O���b�h�f�[�^
    Vector2 GridSize_;
    Vector2 GridCount_;          // XY�̃O���b�h��
    int Percent_;
    int SlTxNum_;               // �I��texture
    TrgPos mousePos_;
    Vector2 mouseDiff_;

    Button_Type buttonMode_;
    friend class ChipDataView;
    friend class FileWindow;

    friend struct BUTTON_TYPE_PEN;
    friend struct BUTTON_TYPE_BOX;
    friend struct BUTTON_TYPE_BOX_FILL;
    friend struct BUTTON_TYPE_ERASE;
};


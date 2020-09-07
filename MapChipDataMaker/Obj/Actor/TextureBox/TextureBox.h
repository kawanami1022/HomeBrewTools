#pragma once
#include <vector>
#include <set>
#include <map>
#include "../../../Texture/TextureFactory.h"
#include "../../../Texture/Texture.h"

class Actor;
class TextureBox :
    public Actor
{
public:
    TextureBox();
    void Input()override;
    void Update()override;
    void Draw()override;

    //�}�E�X�̍��W�Ŏ���
    void InMousePosIdnt();

    // �摜�𕪊�����
    void DivTexture();

    // Getter
    Vector2 GetTextureSize();
    int GetSlTxNum();   // �I��texture���擾
    SharTexture GetTxHdl();

    // Setter
    bool SetTexture(std::string);       //true �ǂݍ��ݐ���   false �ǂݍ��ݎ��s

private:
    TextureFactory txFcty_;
    int SlTxNum_;
    std::vector<std::string> TextureNmList_;
    std::vector<SharTexture> txHdl_;        // mapChip�p�摜�n���h��
    std::vector<Position2> txPos_;
    Vector2 TextureSize_;
    Vector2 TextureCount_;
    Position2 setPos_;

    friend class ChipDataView;
    friend class FileWindow;
};

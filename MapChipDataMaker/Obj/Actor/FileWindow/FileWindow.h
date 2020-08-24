#pragma once
#include <functional>
#include <list>
#include <vector>
#include <memory>
#include <string>
#include <map>
#include "../Actor.h"
#include "../../../Texture/TextureFactory.h"
#include "../../../Texture/Texture.h"
#include "../Button/Button.h"

enum class BUTTON_TYPE
{
    NON,
    SET_TEXTURE,
    REMOVE_TEXTURE,
    CONVERT_TXT,
    IMPORT_TXT,
    SET_GRAPH_SIZE,
    MAX
};

class FileWindow :public Actor
{
public:
    FileWindow();
    void Input()override;
    void Update()override;
    void Draw()override;
    // ���͏���
    void changeButtonType();

    // �t�@�C�����W����
    void InputTextureDir();        // �摜�t�@�C���̃f�B���N�g�������
    void InputDirTxtDir();         // �摜���ۑ�����Ă�f�B���N�g���ꗗ�e�L�X�g�t�@�C��
private:
    BUTTON_TYPE btnType_;    // ���݂̑I��
    std::list<std::string> txNmList_;       // �摜���̃��X�g
    std::unique_ptr<TextureFactory> txFc_;  // �摜����
    std::vector<SharTexture> textureList_;
    std::vector<Button> btn_;
    std::map < BUTTON_TYPE, std::function<void(FileWindow&)>> upDt;
    friend class TextureBox;
    friend struct NON;
    friend struct IMPORT_TXT;
    friend struct CONVERT_TXT;
    friend struct REMOVE_TEXTURE;
    friend struct SET_GRAPH_SIZE;
    friend struct SET_TEXTURE;

};


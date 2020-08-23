#pragma once
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
    MAX
};

class FileWindow :public Actor
{
public:
    FileWindow();
    void Input()override;
    void Update()override;
    void Draw()override;

private:
    BUTTON_TYPE btnType_;    // 現在の選択中
    std::list<std::string> txNmList_;       // 画像名のリスト
    std::unique_ptr<TextureFactory> txFc_;  // 画像生成
    std::vector<SharTexture> textureList_;
    std::vector<Button> btn_;
};


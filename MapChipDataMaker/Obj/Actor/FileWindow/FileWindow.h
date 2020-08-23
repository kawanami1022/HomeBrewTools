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
    // “ü—Íˆ—
    void changeButtonType();

    // 
private:
    BUTTON_TYPE btnType_;    // Œ»İ‚Ì‘I‘ğ’†
    std::list<std::string> txNmList_;       // ‰æ‘œ–¼‚ÌƒŠƒXƒg
    std::unique_ptr<TextureFactory> txFc_;  // ‰æ‘œ¶¬
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


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

    //マウスの座標で識別
    void InMousePosIdnt();

    // 画像を分割する
    void DivTexture();

    // Getter
    Vector2 GetTextureSize();
    int GetSlTxNum();   // 選択中textureを取得
    SharTexture GetTxHdl();

    // Setter
    bool SetTexture(std::string);       //true 読み込み成功   false 読み込み失敗

private:
    TextureFactory txFcty_;
    int SlTxNum_;
    std::vector<std::string> TextureNmList_;
    std::vector<SharTexture> txHdl_;        // mapChip用画像ハンドル
    std::vector<Position2> txPos_;
    Vector2 TextureSize_;
    Vector2 TextureCount_;
    Position2 setPos_;

    friend class ChipDataView;
    friend class FileWindow;
};

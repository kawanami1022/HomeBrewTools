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

    // Getter
    Vector2 GetTextureSize();
    int GetSlTxNum();   // 選択中textureを取得
    std::vector<SharTexture> GetTxHdl();

    // Setter
    void SetTexture(std::string);

private:
    TextureFactory txFcty_;
    int SlTxNum_;
    std::set<std::string> TextureNmList_;
    std::vector<SharTexture> txHdl_;
    std::vector<Position2> txPos_;
    Vector2 TextureSize_;
    Vector2 TextureCount_;

    friend class ChipDataView;
};

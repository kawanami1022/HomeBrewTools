#pragma once
#include <vector>
#include <list>
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
    void SetMousePos();
    void SetTexture(std::string);
    void SetTextureList(SharTexture texture);
private:
    std::list<std::string> TextureNmList_;
    std::vector<SharTexture> txHdl_;
};


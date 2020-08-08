#pragma once
#include <vector>
#include "../../../Vector2/Vector2.h"
#include "../Actor.h"
#include "../../../Texture/TextureFactory.h"
#include "../../../Texture/Texture.h"

class ChipDataView :
    public Actor
{
public:
    ChipDataView(Vector2 Size_, Vector2 GridCount);
    ~ChipDataView();
    void Update()override;
    void Draw()override;
    // setter
    void SetMousePos(TrgPos);
private:
    TextureFactory texFactory_;
    std::vector<SharTexture> GrHandleList_;
    const Vector2 GridSize;
    const Vector2 GridCount;
    int Percent_;
    TrgPos mousePos_;
};


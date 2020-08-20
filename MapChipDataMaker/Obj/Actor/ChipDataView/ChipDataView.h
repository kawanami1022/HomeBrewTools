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
    void Input()override;
    void Update()override;
    void Draw()override;


    // input
    void PercentBox();

    // setter
    void SetMousePos(TrgPos);
    void SetMouseDiff(Vector2);
private:
    TextureFactory texFactory_;
    std::vector<SharTexture> GrHandleList_;
    const Vector2 GridSize;
    const Vector2 GridCount;
    int Percent_;
    TrgPos mousePos_;
    Vector2 mouseDiff_;
};


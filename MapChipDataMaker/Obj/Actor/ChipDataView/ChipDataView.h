#pragma once
#include "../../../Vector2/Vector2.h"
#include "../Actor.h"


class ChipDataView :
    public Actor
{
public:
    ChipDataView(Vector2I Size_, Vector2I GridCount);
    ~ChipDataView();
    void Update()override;
    void Draw()override;
private:
    const Vector2I GridSize;
    const Vector2I GridCount;
};


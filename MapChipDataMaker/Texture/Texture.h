#pragma once
#include "../Vector2/Vector2.h"

class Texture
{
public:
	Texture(int GrHandle);
	~Texture();

	// getter
	int GetGrHandle();
	Vector2 GetSize();
private:

	Vector2 Size_;
	int GrHandle_;
};


#pragma once
#include "../Vector2/Vector2.h"

class Texture
{
public:
	Texture(int GrHandle);
	~Texture();

	// getter
	int GetGrHandle();
	Vector2I GetSize();
private:

	Vector2I Size_;
	int GrHandle_;
};


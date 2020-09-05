#pragma once
#include <memory>
#include <map>
#include <string>
#include <vector>
#include "Texture.h"

using SharTexture = std::shared_ptr<Texture>;
using MapTexture = std::map<std::string, SharTexture>;

class TextureFactory
{
public:
	// GrHandle‚ðŽæ“¾‚·‚é
	SharTexture GetTexture_(std::string FileName);
	std::vector<SharTexture> CreateDivTexture_(std::string FileName, int numX, int numY);
private:
	MapTexture TextureContainer_;
	SharTexture CreateTexture_(std::string FileName);
};


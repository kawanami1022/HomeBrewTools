#pragma once
#include <memory>
#include <map>
#include <string>
#include "Texture.h"

using SharTexture = std::shared_ptr<Texture>;
using MapTexture = std::map<std::string, SharTexture>;

class TextureFactory
{
public:
	// GrHandleを取得する
	SharTexture GetTexture_(std::string FileName);
private:
	MapTexture TextureContainer_;
	SharTexture CreateTexture_(std::string FileName);
};


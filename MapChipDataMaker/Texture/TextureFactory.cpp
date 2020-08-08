#include <DxLib.h>
#include "TextureFactory.h"

SharTexture TextureFactory::GetTexture_(std::string FileName)
{
	
	auto it = TextureContainer_.find(FileName);
	if (it != TextureContainer_.end())
	{
		return it->second;
	}
	auto newTexture = CreateTexture_(FileName);
	TextureContainer_.insert(TextureContainer_.begin(), std::make_pair(FileName, newTexture));
	return TextureContainer_[FileName];
}

SharTexture TextureFactory::CreateTexture_(std::string FileName)
{
	auto GrHandle = LoadGraph(FileName.data(), 0);
	SharTexture texture=std::make_unique<Texture>(GrHandle);
	
	return texture;
}

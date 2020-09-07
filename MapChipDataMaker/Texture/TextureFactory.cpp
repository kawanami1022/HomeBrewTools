#include <array>
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

std::vector<SharTexture> TextureFactory::CreateDivTexture_(std::string FileName,int numX,int numY)
{
	int* TxHandleList_;
	TxHandleList_ = new int[static_cast<unsigned __int64>(numX * numY)];
	for (int i = 0; i < numX * numY; i++)
	{
		TxHandleList_[i] = 0;
	}

	LoadDivGraph(FileName.data(), numX * numY, numX, numY,
		TextureContainer_[FileName.data()]->GetSize().x / numX,
		TextureContainer_[FileName.data()]->GetSize().y / numY,
		TxHandleList_);

	std::vector<SharTexture> txHdl_;
	txHdl_.reserve(static_cast<unsigned __int64>(numX * numY));
	for (int i = 0; i < numX * numY; i++)
	{txHdl_.emplace_back(new Texture(TxHandleList_[i]));}

	delete[] TxHandleList_;

	return txHdl_;
}

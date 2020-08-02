#pragma once
#include <cstdlib>
#include <memory>
#include <iostream>
#include <thread>
#include <mutex>
#include "BaseScene.h"
#include "EditScene.h"
#define SCREEN_SIZE_X 1200
#define SCREEN_SIZE_Y 800

class SceneController
{
public:
	static SceneController& GetInstance()
	{
		static std::once_flag once;
		std::call_once(once, Create);
		return (*sInstance);
	}
	static void Create()
	{
		if (sInstance == nullptr)
		{
			sInstance = new SceneController();
		}
	}
	static void Destroy()
	{
		delete sInstance;
		sInstance = nullptr;
	}

	std::unique_ptr<BaseScene> nowScene;
	int Run();
private:
	int Init();					// èâä˙âª

	static SceneController* sInstance;
	SceneController();
	~SceneController();
};




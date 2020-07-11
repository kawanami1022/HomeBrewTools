#include <DxLib.h>
#include "SceneController.h"

SceneController* SceneController::sInstance = nullptr;

int SceneController::Run()
{
	ChangeWindowMode(true);
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);


	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;				// エラーが起きたら直ちに終了
	}

	// 描画先画面を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);
	Init();
	// ループ
	while (ProcessMessage() == 0)
	{
		nowScene=nowScene->Input(std::move(nowScene));
		nowScene=nowScene->upDate(std::move(nowScene));
		nowScene->Draw();
		// 画面を初期化する
	}


	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;
}

int SceneController::Init()
{
	nowScene = std::make_unique<TitleScene>();

	return 0;
}

SceneController::SceneController()
{
}

SceneController::~SceneController()
{
}

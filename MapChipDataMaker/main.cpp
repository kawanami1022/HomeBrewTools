#include <iostream>
#include <DxLib.h>
#include "Scene/SceneController.h"


// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SceneController::GetInstance().Run();
	SceneController::Destroy();
}


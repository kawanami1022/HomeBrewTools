#include <iostream>
#include <DxLib.h>
#include "Scene/SceneController.h"


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SceneController::GetInstance().Run();
	SceneController::Destroy();
}


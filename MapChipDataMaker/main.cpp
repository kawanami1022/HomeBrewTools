#include <iostream>
#include <DxLib.h>
#include "Scene/SceneController.h"


// ƒvƒƒOƒ‰ƒ€‚Í WinMain ‚©‚çn‚Ü‚è‚Ü‚·
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SceneController::GetInstance().Run();
	SceneController::Destroy();
}


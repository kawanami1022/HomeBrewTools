#include <DxLib.h>
#include "SceneController.h"

SceneController* SceneController::sInstance = nullptr;

int SceneController::Run()
{
	ChangeWindowMode(true);
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);


	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;				// �G���[���N�����璼���ɏI��
	}

	// �`����ʂ𗠉�ʂɃZ�b�g
	SetDrawScreen(DX_SCREEN_BACK);
	Init();
	// ���[�v
	while (ProcessMessage() == 0)
	{
		nowScene=nowScene->Input(std::move(nowScene));
		nowScene=nowScene->upDate(std::move(nowScene));
		nowScene->Draw();
		// ��ʂ�����������
	}


	DxLib_End();				// �c�w���C�u�����g�p�̏I������

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

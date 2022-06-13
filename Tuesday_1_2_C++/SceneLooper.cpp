#include "SceneLooper.h"

SceneLooper::SceneLooper()
{
	
}
SceneLooper::~SceneLooper()
{
	
}

bool SceneLooper::Init()
{
	scene = new Title;
	if (!scene)
	{
		OutputDebugString("SceneBase�̃��������I�m�ۂ̎��s");//�o�͂ɂ�������
		return false;
	}
	sceneMng = new SceneManeger;
	if (!sceneMng)
	{
		OutputDebugString("SceneManeger�̃��������I�m�ۂ̎��s");//�o�͂ɂ�������
		return false;
	}
	return true;
}

void SceneLooper::Run()
{

	ChangeWindowMode(true);
	SetGraphMode(640, 480, 16);
	// �`����ʂ𗠉�ʂɃZ�b�g
	SetDrawScreen(DX_SCREEN_BACK);
	while (!CheckHitKey(KEY_INPUT_ESCAPE)&&!ProcessMessage())
	{
		
		// ��ʂ�����������
		ClearDrawScreen();
		scene->Update();

		scene->Draw();

		if (scene->GetNextSceneFlag())//�V�[���ڍs�̔���
		{
			auto beforeScene = scene;//�O�V�[���폜�̉��u��
			
			scene = sceneMng->ScenePasser(scene);//���V�[�����}�l�[�W���[���n��
			if (!scene)//nullptr�ŃG���[�f������I��
			{
				OutputDebugString("ScenePasserError");//�o�͂ɂ�������
				return;
			}
			delete beforeScene;//���u�����Ă��������������J��
			WaitTimer(500);
		}
		// ����ʂ̓��e��\��ʂɔ��f������
		ScreenFlip();
		
	}
}

bool SceneLooper::Terminate()
{
	delete scene;
	delete sceneMng;
	return true;
}

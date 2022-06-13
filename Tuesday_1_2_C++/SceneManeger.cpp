#include "SceneManeger.h"
#include"Title.h"
#include"Game.h"
#include"GameClear.h"
#include"GameOver.h"
SceneBase* SceneManeger::ScenePasser(SceneBase* scenebase)
{
	//�^�O���Ŕ���
	if (scenebase->GetSceneTag()==SceneTag::Title)
	{
		//�^�C�g���̎��̓Q�[�����C��
		return new Game();
	}
	if (scenebase->GetSceneTag() == SceneTag::GameMain)
	{
		//�N���A�t���O�����Ă���N���A���U���g��
		if (scenebase->GetClearFlag())
		{
			return new GameClear();
		}
		//�Q�[���I�[�o�[�t���O�����Ă���Q�[���I�[�o�[���U���g��
		if (scenebase->GetGameoverFlag())
		{
			return new GameOver();
		}
	}
	//GameClear(Over)�̎��̓^�C�g��
	if (scenebase->GetSceneTag()== SceneTag::GameClear
		|| scenebase->GetSceneTag() == SceneTag::GameOver)
	{
		return new Title();
	}

	//�^�O���ĂȂ�������nullptr(�G���[)
	return nullptr;
}


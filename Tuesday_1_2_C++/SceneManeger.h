#pragma once
#include"SceneBase.h"
#include"SceneTag.h"
class Title;
class Game;
//���݂̃V�[�����Ď����ēK�؂Ȏ��N���X��n���A�t���[�̖���
class SceneManeger
{
public:
	/// <summary>
	/// ���͂����Ď��̃V�[����n��
	/// �V�[���؂�ւ��̃t���O����������Ăяo�����
	/// </summary>
	/// <param name="nowScene">���̃V�[�����󂯎��</param>
	/// <returns> ���̃V�[����Ԃ�</returns>
	SceneBase* ScenePasser(SceneBase* scenebase);

};


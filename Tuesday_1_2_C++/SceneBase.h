#pragma once
#include"DxLib.h"
#include"SceneTag.h"
//SceneLoop��z�肵���p���p�̊��̃N���X
class SceneBase
{
public:
	

	//�R���X�g���N�^
	SceneBase();
	
	//�R�s�[�̖����I�֎~
	SceneBase(const SceneBase&) = delete;//�R�s�[�R���X�g���N�^
	//�R�s�[�̖����I�֎~
	SceneBase& operator=(const SceneBase&) = delete;//�R�s�[������Z�q
	
	//�f�X�g���N�^
	virtual ~SceneBase();
	
	//�`�揈��
	virtual void Draw();

	/// <summary>
	/// ���t���[�����Ƃ̏���
	/// </summary>
	/// <returns>�Ԃ�l���Ď����ăV�[���̑J�ڂ����m����</returns>
	virtual void Update();

	//���̃V�[���ɉf�邩�𔻒肷��t���O��Ԃ�
	bool GetNextSceneFlag() { return nextSceneFlag; };

	bool GetClearFlag() { return clearFlag; };
	bool GetGameoverFlag() { return gameoverFlag; };

	//���x�̃V�[�������^�O�ŕԂ�
	SceneTag GetSceneTag() { return tag; };

protected:
	//���̃V�[���𔻕ʂ���^�O
	SceneTag tag;

	//���̃V�[���ɉf�邩�𔻒肷��t���O
	bool nextSceneFlag = false;

	//���U���g�ڍs�p�̃t���O
	bool clearFlag = false;
	bool gameoverFlag = false;
};


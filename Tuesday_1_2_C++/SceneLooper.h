#pragma once
#include"SceneManeger.h"
#include"SceneBase.h"
#include"Title.h"
#include"DxLib.h"
class SceneManager;
//SceneLooper�������I�ɃV�[������
//�܂��������A���s�A�I�������̂ݍs�����߃V�[���x�[�X�ɂ͂قڂ������Ȃ�
class SceneLooper
{
public:
	SceneLooper();
	~SceneLooper();
	//
	bool Init();//������
	void Run();//���s
	bool Terminate();//�I������
	SceneBase* scene;//�e�N���X�Ƃ���update��draw���񂷁A���ۂ̏����͌p�������q�N���X�̂��̂ɂȂ�
	SceneManeger* sceneMng;
};


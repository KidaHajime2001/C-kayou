#pragma once
#include"SceneBase.h"
class Title:public SceneBase
{
public:
	//�R���X�g���N�^
	Title();
	//�f�X�g���N�^
	~Title();
	void Update()override;
	void Draw()override;
};


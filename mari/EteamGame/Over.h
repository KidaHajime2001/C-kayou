#pragma once

//����
#include "Scene.h"

class Ui;
class Mouse;

//�I�[�o�[���
class Over :public Scene
{

	Ui* ui;
	Mouse* mouse;

public:

	//������
	Over();

	//�폜
	~Over();

	//�X�V����
	Scene* Update(float _deltaTime)override;

	//�`�揈��
	void Draw()override;

};
#pragma once

//����
#include "Scene.h"

class Ui;
class Mouse;

//�N���A���
class Clear :public Scene
{

	Ui* ui;
	Mouse* mouse;

public:

	//������
	Clear();

	//�폜
	~Clear();

	//�X�V����
	Scene* Update(float _deltaTime)override;

	//�`�揈��
	void Draw()override;

};
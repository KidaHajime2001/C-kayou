#pragma once

//����
#include"Scene.h"

class Ui;
class Mouse;

//�^�C�g�����
class Title :public Scene
{

	Ui* ui;
	Mouse* mouse;

public:

	//������
	Title();

	//�폜
	~Title();

	//�X�V����
	Scene* Update(float _deltaTime)override;

	//�`�揈��
	void Draw()override;

};
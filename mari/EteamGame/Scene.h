#pragma once

//����
#include "DxLib.h"

//���
class Scene
{
public:
	
	//������
	Scene();

	//�폜
	~Scene();

	//�X�V����
	virtual Scene* Update(float _deltaTime) = 0;

	//�`�揈��
	virtual void Draw() = 0;

protected:

	//�摜
	int image;

};
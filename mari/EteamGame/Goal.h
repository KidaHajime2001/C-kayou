#pragma once
class Goal
{
public:
	//������
	Goal();

	//�폜
	~Goal();

	//�ʒu
	float posX;
	float posY;

	//���@
	float sizeX;
	float sizeY;

	//�摜
	int image;

	//�`�揈��
	void Draw();
};

//���L��
extern Goal goal;
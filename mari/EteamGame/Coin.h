#pragma once

//�R�C��
class Coin
{
public:
	//������
	Coin();

	//�폜
	~Coin();

	//�ʒu
	float posX;
	float posY;

	//���@
	float sizeX;
	float sizeY;

	//�摜
	int image[3];

	//�t���O
	bool Flag;
};

//���L��
extern Coin coin[1000];
extern int coinCount;
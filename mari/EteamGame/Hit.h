#pragma once

//Hit
class Hit
{
public:

	////������
	//Hit();

	////�폜
	//~Hit();

	//�ʒu
	float posX;
	float posY;

	//�ʒu�擾
	float& GetPosX() { return posX; }
	float& GetPosY() { return posY; }

	//���@
	float sizeX;
	float sizeY;

	//�ʒu�擾
	float& GetSizeX() { return sizeX; }
	float& GetSizeY() { return sizeY; }

};

//���L��
extern Hit hit;
#pragma once

//�u���b�N
class Block
{
public:
	//������
	Block();

	//�폜
	~Block();

	//�ʒu
	float posX;
	float posY;

	//���@
	float sizeX;
	float sizeY;

	//�摜
	int image;
};

//���L��
extern Block block[1000];
extern int blockCount;
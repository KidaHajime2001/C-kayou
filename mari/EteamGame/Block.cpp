//����
#include "DxLib.h"
#include "Block.h"

//���L��
Block block[1000];
int blockCount = 0;

//������
Block::Block()
	:posX(0)
	,posY(0)
	,sizeX(0)
	,sizeY(0)
{
	blockCount = 0;
	image = LoadGraph("img/stage.png");
}

//�폜
Block::~Block()
{
}
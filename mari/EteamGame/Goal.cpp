//����
#include "DxLib.h"
#include "Goal.h"
#include "Player.h"

//���L��
Goal goal;

//������
Goal::Goal()
	:posX(10000.0f)
	,posY(0.0f)
	,sizeX(1.0f)
	,sizeY(2000.0f)
{
	image = LoadGraph("img/Goal.png");
}

//�폜
Goal::~Goal()
{
}

//�`�揈��
void Goal::Draw()
{
	//�`����s
	DrawGraph(posX + sp, posY, image, true);
}

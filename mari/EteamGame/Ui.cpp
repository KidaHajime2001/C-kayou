//����
#include "Ui.h"
#include "Title.h"

//���L��
Ui ui;

//������
Ui::Ui()
	:posX(820.0f)
	,posY(400.0f)
	,sizeX(100.0f)
	,sizeY(100.0f)
{
	//�摜�̓ǂݍ���
	image = LoadGraph("img/start.png");
}

//�폜
Ui::~Ui()
{
}

//�`�揈��
void Ui::Draw()
{
	//�`����s
	DrawGraph(posX, posY, image, true);
}
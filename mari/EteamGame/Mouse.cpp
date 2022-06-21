//����
#include "Mouse.h"
#include "Ui.h"
#include "Title.h"
#include "Game.h"
#include "Collision.h"

//������
Mouse::Mouse()
	:posX(0.0f)
	,posY(0.0f)
	,sizeX(15.0f)
	,sizeY(15.0f)
	,uiFlag(false)
{
}

//�폜
Mouse::~Mouse()
{
}

//�X�V
void Mouse::Update(Ui& ui)
{
	//�}�E�X�̈ʒu���擾���������
	GetMousePoint(&posX, &posY);

	//�������}�E�X��Ui�Ɠ��������ꍇ
	if (mCollision(posX, posY, sizeX, sizeY, ui.GetPosX() + 100, ui.GetPosY() + 100, ui.sizeX, ui.sizeY))
	{
		//�t���O���I���ɂ���
		uiFlag = true;
	}
}
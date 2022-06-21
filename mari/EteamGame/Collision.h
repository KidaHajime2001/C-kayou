#pragma once

#define COLLISION_CELL_WIDTH 40											//�����蔻��BOX�̕�
#define COLLISION_CELL_HEIGHT 40										//�����蔻��BOX�̍���
#define COLLISION_CELL_NUM_X 300											//�����蔻��BOX�̉������̐�
#define COLLISION_CELL_NUM_Y 30											//�����蔻��BOX�̏c�����̐�
#define COLLISION_WINDOW_X 1600											//�E�B���h�E�̕�
#define COLLISION_WINDOW_Y 480											//�E�B���h�E�̍���


//���L��
class Player;

//�����蔻��
bool mCollision(float posX1, float posY1, float sizeX1, float sizeY1, float posX2, float posY2, float sizeX2, float sizeY2);

struct collisionCell														//�����蔻��BOX�p�̍\���̂����
{
	int collisionBoxHandle;													//�����蔻��Ǘ��p�̕ϐ�
};

class Collision																	//�w�i�����蔻��N���X�����
{
public:

	//������
	Collision();

	//�폜
	~Collision();


	void ColBox(Player&player);

};

//extern struct collisionCell
//{
//	int collisionBoxHandle;
//};
extern int collisionBoxHandle[2];												//�����蔻��BOX�G�̑������|���Z�ŏo��
extern struct collisionCell collisionCell[COLLISION_CELL_NUM_X][COLLISION_CELL_NUM_Y];
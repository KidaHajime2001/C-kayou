#pragma once

//���L��
class Player;

//�~�T�C��
class Missile
{
public:

	//������
	Missile();

	//�폜
	~Missile();

	//�ʒu
	float posX[10] = {0};
	float posY[10] = {0};

	//���A�ʒu
	float returnPosX[10] = { 0 };
	float returnPosY[10] = { 0 };

	//�ʒu�擾
	float& GetPosX() { return posX[0]; }
	float& GetPosY() { return posY[0]; }

	//�~�T�C���̑���
	int total;

	//���@
	float sizeX;
	float sizeY;

	//���x
	float speedX[10] = { 0 };
	float speedY[10] = { 0 };

	//�X�V����
	void Update(Player& player);

	//�`�揈��
	void Draw();

	//�摜
	int image;

};
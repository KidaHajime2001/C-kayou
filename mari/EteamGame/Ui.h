#pragma once

//UI
class Ui
{
public:

	//������
	Ui();

	//�폜
	~Ui();

	//�ʒu
	float posX;
	float posY;

	//�ʒu�擾
	float& GetPosX() { return posX; }
	float& GetPosY() { return posY; }

	//���@
	float sizeX;
	float sizeY;

	//�摜
	int image;

	//�`�揈��
	void Draw();

};

//���L��
extern Ui ui;
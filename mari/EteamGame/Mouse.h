#pragma once

//���L��
class Ui;

//�}�E�X
class Mouse
{
public:

	//������
	Mouse();

	//�폜
	~Mouse();

	//�ʒu
	int posX;
	int posY;
	
	//���@
	float sizeX;
	float sizeY;

	//�X�V
	void Update(Ui&ui);

	//����
	bool uiFlag;

};
#pragma once

#define CELL_WIDTH 40													//�^�C���̕�
#define CELL_HEIGHT 40													//�^�C���̍���
#define CELL_NUM_X 300													//�^�C���̉������̐�
#define CELL_NUM_Y 28													//�^�C���̏c�����̐�
#define WINDOW_X 1600													//�E�B���h�E�̕�
#define WINDOW_Y 480													//�E�B���h�E�̍���


class Stage																									//map�N���X�����
{
public:									//�\���̂Ƀ^�C���̉��c���i�[����

	//������
	Stage();

	//�폜
	~Stage();

	void View();

};
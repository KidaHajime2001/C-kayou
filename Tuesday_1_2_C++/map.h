#pragma once
#pragma once
#include <DxLib.h>
#include"Collision.h"
#define CELL_WIDTH 40													//�^�C���̕�
#define CELL_HEIGHT 40													//�^�C���̍���
#define CELL_NUM_X 40													//�^�C���̉������̐�
#define CELL_NUM_Y 12													//�^�C���̏c�����̐�
#define WINDOW_X 1600													//�E�B���h�E�̕�
#define WINDOW_Y 480													//�E�B���h�E�̍���

int chipgraphicHandle[(256 / 32) * (256 / 32)];							//�^�C���G�̑������|���Z�ŏo��
int tileImgX;															//�w�i�摜��X���W
int characterPack;														//�������i�[����ϐ�
int rawNum = 0;															//�������̃^�C���i���o�[
int columnNum = 0;														//�c�����̃^�C���i���o�[
int num;																//�^�C���̔ԍ�
int i;																	//for���J�E���^�[
int j;																	//for���J�E���^�[
char buffer[10];														//������ϐ�
bool eofFlag = false;													//eof�iend of file�j���o�t���O

struct Cell																			//�^�C���p�̍\���̂����
{
	int graphicHandle;	//�摜����p�̕ϐ�
	Collision* collision;
};

class Map																									//map�N���X�����
{
public:

	Cell cell[CELL_NUM_X][CELL_NUM_Y];																		//�\���̂Ƀ^�C���̉��c���i�[����

	Map()
	{
		LoadDivGraph("img/map3.png", (256 / 32) * (256 / 32), 256 / 32, 256 / 32, 32, 32, chipgraphicHandle);	//�^�C���摜��ǂݍ���
		FILE* filePointer;																					//�t�@�C���̃|�C���^��錾
		fopen_s(&filePointer, "map.csv", "r");																//fopen_s�֐���map.csv��ǂݎ��`���ŊJ��
		if (filePointer == NULL)																			//filePointer����̏ꍇ��
		{
			DebugBreak();																					//�f�o�b�O���~
		}

		memset(buffer, 0, sizeof(buffer));																	//memset�֐��Ń�������buffer���Z�b�g���Asizeof���Z�q�ŗv�f�������߂�

		while (1)
		{
			while (1)
			{
				characterPack = fgetc(filePointer);										//fgetc�֐���filepointer���當����ǂ��characterPack�Ɋi�[
				if (characterPack == EOF)
				{
					eofFlag = true;														//EndOfFile�����o����
					break;																//���[�v�𔲂���
				}
				if (characterPack != ',' && characterPack != '\n')						//��؂肩���s�łȂ����
				{
					strcat_s(buffer, (const char*)&characterPack);						//strcat_s�֐���buffer�ɘA�����Aconst char�֐��ŏ���������
				}
				else
				{
					num = atoi(buffer);													//atoi�֐���buffer��int�^�ɒ����āA���[�J���ϐ�num�ɑ��
					cell[columnNum][rawNum].graphicHandle = chipgraphicHandle[num];		//num�Ԗڂ̃`�b�v�摜�̃n���h�����擾
					memset(buffer, 0, sizeof(buffer));									//buffer�����Z�b�g
					break;																//��؂肩���s�Ȃ̂Ń��[�v�𔲂���
				}
			}
			if (eofFlag)																//1�}�b�v���ɂȂ�����
			{
				break;																	//���[�v�𔲂���
			}
			if (characterPack == ',')													//��؂�����o������
			{
				columnNum++;															//��̐��𑝂₷
			}
			if (characterPack == '\n')													//���s��������
			{
				rawNum++;																//�s�𑝂₷
				columnNum = 0;															//���0�ɂ���
			}
		}
		fclose(filePointer);															//�t�@�C�������
	}

	void View()
	{
		for (i = 0; i < CELL_NUM_X; i++)
		{
			for (j = 0; j < CELL_NUM_Y; j++)
			{
				DrawExtendGraph(i * CELL_WIDTH + tileImgX, j * CELL_HEIGHT, (i + 1) * CELL_WIDTH + tileImgX, (j + 1) * CELL_HEIGHT, cell[i][j].graphicHandle, TRUE);
			}
		}
	}

	void All()
	{
		View();
	}

};
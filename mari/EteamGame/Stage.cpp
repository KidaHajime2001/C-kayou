//����
#include "Dxlib.h"
#include "Stage.h"
#include "Collision.h"
#include "Block.h"
#include "Coin.h"
#include "Missile.h"
#include "Hit.h"
#include "Define.h"
#include "Player.h"

#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
struct Cell																			//�^�C���p�̍\���̂����
{
	int graphicHandle;																//�摜����p�̕ϐ�
};

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
Cell cell[CELL_NUM_X][CELL_NUM_Y];
vector<vector<int>> mapData;

//������
Stage::Stage()
{
	LoadDivGraph("img/map3.png", (256 / 32) * (256 / 32), 256 / 32, 256 / 32, 32, 32, chipgraphicHandle);	//�^�C���摜��ǂݍ���
	FILE* filePointer;																					//�t�@�C���̃|�C���^��錾
	fopen_s(&filePointer, "Data/map.csv", "r");																//fopen_s�֐���map.csv��ǂݎ��`���ŊJ��
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
	fclose(filePointer);
}

//�폜
Stage::~Stage()
{
}

//�`�揈��
void Stage::View()
{
	for (int i = 0; i < CELL_NUM_X; i++)
	{
		for (int j = 0; j < CELL_NUM_Y; j++)
		{
			DrawExtendGraph(i * CELL_WIDTH + sp, j * CELL_HEIGHT, (i + 1) * CELL_WIDTH + sp, (j + 1) * CELL_HEIGHT, cell[i][j].graphicHandle, TRUE);
		}
	}
}
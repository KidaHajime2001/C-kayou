//����
#include <DxLib.h>
#include <math.h>
#include <time.h>
#include"Collision.h"
#include "Player.h"

struct collisionCell collisionCell[COLLISION_CELL_NUM_X][COLLISION_CELL_NUM_Y];

//�����蔻��
bool mCollision(float posX1, float posY1, float sizeX1, float sizeY1, float posX2, float posY2, float sizeX2, float sizeY2)
{
	if (posX1 + (sizeX1 / 2.0f) > posX2 - (sizeX2 / 2.0f) &&
		posX1 - (sizeX1 / 2.0f) < posX2 + (sizeX2 / 2.0f) &&
		posY1 + (sizeY1 / 2.0f) > posY2 - (sizeY2 / 2.0f) &&
		posY1 - (sizeY1 / 2.0f) < posY2 + (sizeY2 / 2.0f))
	{
		return true;
	}
	return false;
}

int collisionBoxHandle[2];												//�����蔻��BOX�G�̑������|���Z�ŏo��
int collisionBoxX;														//�w�i�����蔻��BOX��X���W
int collisionMarker;													//�������i�[����ϐ�
int collisionRawNum = 0;												//�������̓����蔻��BOX�i���o�[
int collisionColumnNum = 0;												//�c�����̓����蔻��BOX�i���o�[
int collisionNum;														//�����蔻��BOX�̔ԍ�
int ci;																	//for���J�E���^�[
int cj;																	//for���J�E���^�[
char collisionBuffer[10];												//������ϐ�
bool collisionEofFlag = false;											//eof�iend of file�j���o�t���O

Collision::Collision()
{
	collisionRawNum = 0;												//�������̓����蔻��BOX�i���o�[
	collisionColumnNum = 0;												//�c�����̓����蔻��BOX�i���o�[
	collisionRawNum = 0;												//�������̓����蔻��BOX�i���o�[
	collisionColumnNum = 0;												//�c�����̓����蔻��BOX�i���o�[
	collisionEofFlag = false;											//eof�iend of file�j���o�t���O
	LoadDivGraph("img/collision_check.png", 2, 2, 1, 32, 32, collisionBoxHandle);//�����蔻��`�F�b�N�p�摜
	FILE* collisionFilePointer;												//�t�@�C���̃|�C���^��錾
	fopen_s(&collisionFilePointer, "Data/collision.csv", "r");					//fopen_s�֐���collision.csv��ǂݎ��`���ŊJ��
	if (collisionFilePointer == NULL)										//collisionFilePointer����̏ꍇ��
	{
		DebugBreak();														//�f�o�b�O���~
	}


	memset(collisionBuffer, 0, sizeof(collisionBuffer));					//memset�֐��Ń�������buffer���Z�b�g���Asizeof���Z�q�ŗv�f�������߂�

	while (1)
	{
		while (1)
		{
			collisionMarker = fgetc(collisionFilePointer);						//fgetc�֐���filepointer���當����ǂ��characterPack�Ɋi�[
			if (collisionMarker == EOF)
			{
				collisionEofFlag = true;									//EndOfFile�����o����
				break;														//���[�v�𔲂���
			}
			if (collisionMarker != ',' && collisionMarker != '\n')			//��؂肩���s�łȂ����
			{
				strcat_s(collisionBuffer, (const char*)&collisionMarker);	//strcat_s�֐���buffer�ɘA�����Aconst char�֐��ŏ���������
			}
			else
			{
				collisionNum = atoi(collisionBuffer);						//atoi�֐���buffer��int�^�ɒ����āA���[�J���ϐ�num�ɑ��
				collisionCell[collisionColumnNum][collisionRawNum].collisionBoxHandle = collisionBoxHandle[collisionNum];		//num�Ԗڂ̃`�b�v�摜�̃n���h�����擾
				memset(collisionBuffer, 0, sizeof(collisionBuffer));		//buffer�����Z�b�g
				break;														//��؂肩���s�Ȃ̂Ń��[�v�𔲂���
			}
		}
		if (collisionEofFlag)												//1�}�b�v���ɂȂ�����
		{
			break;															//���[�v�𔲂���
		}
		if (collisionMarker == ',')											//��؂�����o������
		{
			collisionColumnNum++;											//��̐��𑝂₷
		}
		if (collisionMarker == '\n')										//���s��������
		{
			collisionRawNum++;												//�s�𑝂₷
			collisionColumnNum = 0;											//���0�ɂ���
		}
	}
	fclose(collisionFilePointer);
}

Collision::~Collision()
{
}

void Collision::ColBox(Player& player)
{
		const int playerW = 32;
		const int playerH = 64;

		int playerLX = player.GetPosX() - playerW - sp; // ����X
		int playerLY = player.GetPosY() - playerH;            // ����Y
		int playerRX = player.GetPosX() + playerW - sp; // �E��X
		int playerRY = player.GetPosY() + playerH;            // �E��Y

		int playerLX2 = player.GetPosX(); // ����X
		int playerLY2 = player.GetPosY();            // ����Y
		int playerRX2 = player.GetPosX(); // �E��X
		int playerRY2 = player.GetPosY();            // �E��Y

		int playerVY = player.GetPosY() - player.GetprevPosY();

		int idLX = playerLX / COLLISION_CELL_WIDTH;  // ����X�Y����
		int idLY = playerLY / COLLISION_CELL_HEIGHT; // ����Y�Y����
		int idRX = playerRX / COLLISION_CELL_WIDTH;  // �E��X�Y����
		int idRY = playerRY / COLLISION_CELL_HEIGHT; // �E��Y�Y����

		int idLX2 = playerLX2 / COLLISION_CELL_WIDTH;  // ����X�Y����
		int idLY2 = playerLY2 / COLLISION_CELL_HEIGHT; // ����Y�Y����
		int idRX2 = playerRX2 / COLLISION_CELL_WIDTH;  // �E��X�Y����
		int idRY2 = playerRY2 / COLLISION_CELL_HEIGHT; // �E��Y�Y����

		int blkLX;
		int blkLY;
		int blkRX;
		int blkRY;

		if (idLY < 0 || idRY < 0)
		{
			return;
		}
		
		
		for (int iy = idLY; iy < idRY + 1; iy++)
		{
			for (int ix = idLX; ix < idRX + 1; ix++)
			{
				// �����̓u���b�N���H
				if (collisionCell[ix][iy].collisionBoxHandle == collisionBoxHandle[1])
				{
					//�u���b�N����E�����W
					blkLX = ix * COLLISION_CELL_WIDTH;
					blkLY = iy * COLLISION_CELL_HEIGHT;
					blkRX = blkLX + COLLISION_CELL_WIDTH;
					blkRY = blkLY + COLLISION_CELL_HEIGHT;

					//�{���ɓ������Ă��邩�H
					if (playerLX <= blkRX && blkLX <= playerRX &&
						playerLY <= blkRY && blkLY <= playerRY)
					{
						// �Փ˂����̂ł߂荞�݂�߂��i���A�N�V�����j
						//�u���b�N�̏�[�ƂԂ�����
						if ((playerRY - blkLY > 0) &&
							(playerRY - blkLY <= 64) &&
							(collisionCell[ix][iy - 1].collisionBoxHandle == collisionBoxHandle[0]) &&
							((collisionCell[ix - 1][iy].collisionBoxHandle == collisionBoxHandle[1]) ||
							(collisionCell[ix + 1][iy].collisionBoxHandle == collisionBoxHandle[1])))
						{
							if (player.fGravity)
							{
								player.posY = blkLY - playerH;
								player.fTouching = true;
							}
						}
						// �Փ˂����̂ł߂荞�݂�߂��i���A�N�V�����j
						//�u���b�N�̉��[�ƂԂ�����
						if ((blkRY - playerLY >= 64) &&
							(blkRY - playerLY <= 128) &&
							(collisionCell[ix][iy + 1].collisionBoxHandle == collisionBoxHandle[0]) &&
							((collisionCell[ix - 1][iy].collisionBoxHandle == collisionBoxHandle[1]) ||
							(collisionCell[ix + 1][iy].collisionBoxHandle == collisionBoxHandle[1])))
						{
							if (!player.fGravity)
							{
								player.posY = blkRY;
								player.fTouching = true;
							}
						}
						// �Փ˂����̂ł߂荞�݂�߂��i���A�N�V�����j
						//�u���b�N�̍����ƂԂ�����
						if (player.fGravity)
						{
							if ((playerRX - blkLX > 0) &&
								(playerRX - blkLX <= 64) &&
								(collisionCell[ix][iy + 1].collisionBoxHandle == collisionBoxHandle[1]) /*&&
								(playerVY > 0)*/)
							{
								player.posX = blkLX - 36;
								/*if (player.fGravity)
								{

									player.fTouching = true;
								}*/
							}
						}
						if (!player.fGravity)
						{
							if ((playerRX - blkLX > 0) &&
								(playerRX - blkLX <= 64) &&
								(collisionCell[ix][iy - 1].collisionBoxHandle == collisionBoxHandle[1]) /*&&
								(playerVY > 0)*/)
							{
								player.posX = blkLX - 36;
								/*if (player.fGravity)
								{

									player.fTouching = true;
								}*/
							}
						}
					}
				}
			}
		}

		// �����𒲂ׂ�
		idRY = (player.GetPosY() + 64) / COLLISION_CELL_HEIGHT;
		//�W�����v���łȂ��̂ɁA�����Ƃ��󒆂ɂ��Ȃ����H
		if (player.fTouching && player.fGravity &&
			(collisionCell[idLX][idRY].collisionBoxHandle == collisionBoxHandle[0]) &&
			(collisionCell[idRX][idRY].collisionBoxHandle == collisionBoxHandle[0]))
		{
			player.fTouching = false;
			
		}

		// ����𒲂ׂ�
		idRY = (player.posY - 64) / COLLISION_CELL_HEIGHT;
		//�W�����v���łȂ��̂ɁA�����Ƃ��󒆂ɂ��Ȃ����H
		if (player.fTouching && !player.fGravity &&
			(collisionCell[idLX][idRY].collisionBoxHandle == collisionBoxHandle[0]) &&
			(collisionCell[idRX][idRY].collisionBoxHandle == collisionBoxHandle[0]))
		{
			player.fTouching = false;
		}
}

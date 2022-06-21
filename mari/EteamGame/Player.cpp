//����
#include "Player.h"
#include "Ui.h"
#include "Title.h"
#include "Game.h"
#include "Collision.h"
#include "Stage.h"
#include "block.h"
#include "Goal.h"
#include "Hit.h"
#include "Define.h"
#include <math.h>

//���L��
Player player;

float sp = 0.0f;

//������
Player::Player()
	:credit(3)
	,posX(50.0f)
	,posY(50.0f)
	,returnPosX(50.0f)
	,returnPosY(50.0f)
	,sizeX(32.0f)
	,sizeY(64.0f)
	,speedX(0.0f)
	,speedY(0.0f)
	,fClick(false)
	,fCheckPoint(false)
	,fGravity(true)
	,fTouching(false)
	,fTouching2(false)
	,fHiting(false)
	,fOut(false)
	,fGameOver(false)
	,fGameClear(false)
{
	sp = 0.0f;
	//�摜�ǂݍ���
	image = LoadGraph("img/p3k.png");
	LoadDivGraph("img/playerImg.png",12,12,1,64,64,playerImg);
	LoadDivGraph("img/playerImgReverse.png", 12, 12, 1, 64, 64, playerImgReverse);
	NowImgNumber = 0;
	gonimage = LoadGraph("img/gOn.png");

	goffimage = LoadGraph("img/gOff.png");

	CycleImg = LoadGraph("img/CycleRink.png");
	GravityFontImg= LoadGraph("img/gravity.png");
	MouseImg= LoadGraph("img/Mouse.png");
	x = 0;
	y = 0;

	//�Z���̍s��
	int cellLine;
	
	//�t�@�C��
	int file;	  
	
	//�t�@�C����
	char fileName[32] = { "Data/player.csv" };

	//���݂̃Z��
	int nowCell[64];

	//�Z���f�[�^
	char cellData[64];



	

	//�t�@�C���ǂݍ��݊J�n
	file = FileRead_open(fileName);	

	//�t�@�C���������ꍇ
	if (file == NULL)
	{

		//"read error"�ƕ\������
		printfDx("read error\n");

		//�I������
		return;

	}

	//�t�@�C���̍ŏ���2�s�Ԃ̊�
	for (int i = 0; i < 2; i++)				
	{
		////���s�܂Ń��[�v����
		while (FileRead_getc(file) != '\n');
	}

	//�Z���̍s����0�ɂ���
	cellLine = 0;

	//���s���̊�
	while (1)
	{
		for (int i = 0; i < 64; i++)
		{
			//1�����擾����
			cellData[i] = nowCell[i] = FileRead_getc(file);

			//�������X���b�V��������ꍇ
			if (cellData[i] == '/')								
			{

				//���s�܂Ń��[�v����
				while (FileRead_getc(file) != '\n');

				//i��-1��������
				i = -1;

				//���s����
				continue;
			}

			//�������J���}�����s�̏ꍇ
			if (nowCell[i] == ',' || nowCell[i] == '\n')			//�J���}�����s�Ȃ�
			{

				//������ɕϊ�����
				cellData[i] = '\0';

				//�I������
				break;
			}

			//�������t�@�C�����I���ꍇ
			if (nowCell[i] == EOF)
			{
				//EXFILE�����Ɉڍs����
				goto EXFILE;
			}
		}

		//�Z���̍s�����������ɂ���
		switch (cellLine)
		{

		//�Z���̍s����0�̏ꍇ
		case 0:

			//X���̑����ɃZ�����̐��l��������
			speedX = atoi(cellData);

			//�I������
			break;

		//�Z���̍s����1�̏ꍇ
		case 1:

			//Y���̑����ɃZ�����̐��l��������
			speedY = atoi(cellData); 

			//�I������
			break;

		}

		//�Z���̍s����1�𑫂�
		cellLine++;

		//�Z���̍s����2�̏ꍇ
		if (cellLine == 2)
		{
			//�Z���̍s����0�ɂ���
			cellLine = 0;

		}
	}

	//EXFILE����:�t�@�C���ǂݍ��ݏI��
	EXFILE:FileRead_close(file);
	
}

//�폜
Player::~Player()
{
}

//�X�V����
void Player::Update()
{	
	if (CheckHitKey(KEY_INPUT_UP))
	{
		y--;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		y++;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		x--;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		x++;
	}
	//���������N���b�N�������ꍇ
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0 )
	{
		//�������A�N���b�N����Ă��Ȃ���Ԃ̏ꍇ
		if (!fClick)
		{
			//���N���b�N���Ă����Ԃɂ���
			fClick = true;

			//�������A�u���b�N�ɓ������Ă����Ԃ̏ꍇ
			if (fTouching)
			{
				//�������Ă��Ȃ���Ԃɂ���
				fTouching = false;
				
				//�������d�͂������Ă����Ԃ̏ꍇ
				if (fGravity)
				{
					//�d�͂������Ă��Ȃ���Ԃɂ���
					fGravity = false;
				}
				else
				{
					//�d�͂������Ă����Ԃɂ���
					fGravity = true;
				}
			}
		}
	}
	//���������N���b�N�����Ă��Ȃ��ꍇ
	else
	{
		//���N���b�N���Ă��Ȃ���Ԃɂ���
		fClick = false;
	}
	
	if (posX >= 960)
	{
		posX = 960;
	}

	//�������u���b�N�Ɠ������Ă��Ȃ��ꍇ
	if (!fTouching)
	{
		//�������d�͂������Ă���ꍇ
		if (fGravity)
		{
			//�c���W�ɏc���x�����Z��������
			posY += speedY;
		}
		else
		{
			//�c���W�ɏc���x�����Z��������
			posY -= speedY;
		}
		sp -= 0;
	}
	//�������u���b�N�Ɠ������Ă���ꍇ
	else
	{
		//�����W�ɉ����x�����Z��������
		if (posX < 960)
		{
			posX += speedX;
			
		}
		
		if (posX >= 960)
		{
			sp -= speedX;
		}
	}

	//
	if (posY <= -100 || posY >= 1100)
	{
		fOut = true;
	}

	//�������v���C���[��Y���W����ʊO�ɏo�����A�~�T�C�����g�Q�ɓ��������ꍇ
	if (fOut || fHiting)
	{

		//�c�@������炷
		credit -= 1;

		//�d�͂����Z�b�g����
		fGravity = true;

		fTouching = false;

		sp = 0;

		//300F�҂�
		WaitTimer(300);

		//���������Ԓn�_��˔j���Ă��Ȃ��ꍇ
		if (!fCheckPoint)
		{
			//�ʒu�ɕ��A�ʒu��������
			posX = returnPosX;
			posY = returnPosY;
		}
		//���������Ԓn�_��˔j���Ă���ꍇ
		else
		{
			//���A�ʒu�ɒ��Ԓn�_�̈ʒu��������
			

			//�ʒu�ɏ����ʒu��������
			posX = returnPosX;
			posY = returnPosY;
		}

		//�~�T�C���ɂ��g�Q�ɂ��������Ă��Ȃ���Ԃɂ���
		fHiting = false;

		////�~�T�C���ɂ��g�Q�ɂ��������Ă��Ȃ���Ԃɂ���
		//fOut = false;
	}

	//�������c�@��0�ȉ��ɂȂ����ꍇ
	if (credit <= 0)
	{

		//�Q�[���I�[�o�[�ɂ���
		fGameOver = true;

	}

	//�������v���C���[�ƃS�[�������������ꍇ
	if (mCollision(posX - 300, posY, sizeX, sizeY,
		goal.posX + sp, goal.posY, goal.sizeX, goal.sizeY))
	{

		//�Q�[���N���A�ɂ���
		fGameClear = true;

	}

}

//�`�揈��
void Player::Draw()
{
	bool beforFlag=fGravity;
	//�`����s
	DrawFormatString(50, 100, GetColor(255, 255, 255), "�c�@%d", credit);
	DrawFormatString(50,150, GetColor(255, 255, 255),"x:%d",x);
	DrawFormatString(50, 200, GetColor(255, 255, 255), "y:%d", y);
	if (fGravity)
	{
		//�`����s
		DrawGraph(posX, posY, playerImg[NowImgNumber / 5], true); DrawRotaGraph(1350+x, 110+y, 1.0, 3.14 / 4, CycleImg, TRUE);

	}
	else
	{
		//�`����s
		DrawGraph(1800, 100, goffimage, false);
		DrawGraph(posX, posY, playerImgReverse[NowImgNumber / 5], true);
		DrawRotaGraph(1350, 100, 1.0, 3.14 / 4, CycleImg, TRUE);
	}

	DrawExtendGraph(1450, 60, 1450 + 500, 60 + 200, GravityFontImg, true);//1450,60
	DrawGraph(1750, 60, MouseImg, true);//1300,50
	if (beforFlag!=fGravity)
	{
		DrawRotaGraph(1300, 50, 2.0, 3.14 / 4,CycleImg, TRUE);
		
	}
	NowImgNumber++;
	if (NowImgNumber>=12*5)
	{
		NowImgNumber = 0;
	}
}

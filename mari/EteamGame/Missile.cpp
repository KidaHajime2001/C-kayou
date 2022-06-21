//����
#include "DxLib.h"
#include "Missile.h"
#include "Player.h"
#include "Collision.h"

//���L��
Missile missile[1000];
int missileCount = 0;

//������
Missile::Missile()
	:sizeX(64)
	,sizeY(32)
{
	//�摜�ǂݍ���
	image = LoadGraph("img/missile.png");

	//�Z���̍s��
	int cellLine;

	//�t�@�C��
	int file;

	//�t�@�C����
	char fileName[32] = { "Data/missile.csv" };

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

	//�~�T�C���̑�����0�ɂ���
	total = 0;

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

			//X���W�ɃZ�����̐��l��������
			posX[total] = atoi(cellData);
			returnPosX[total] = atoi(cellData);
			//�I������
			break;

			//�Z���̍s����1�̏ꍇ
		case 1:

			//Y���W�ɃZ�����̐��l��������
			posY[total] = atoi(cellData);
			returnPosY[total] = atoi(cellData);
			//�I������
			break;

		case 2:

			//X���̑����ɃZ�����̐��l��������
			speedX[total] = atoi(cellData);

			//�I������
			break;

		}

		//�Z���̍s����1�𑫂�
		cellLine++;

		//�Z���̍s����2�̏ꍇ
		if (cellLine == 3)
		{
			//�Z���̍s����0�ɂ���
			cellLine = 0;

			//�~�T�C���̑�����1�𑫂�
			total++;

		}
	}

	//EXFILE����:�t�@�C���ǂݍ��ݏI��
EXFILE:FileRead_close(file);

}

//�폜
Missile::~Missile()
{
}

//�X�V����
void Missile::Update(Player& player)
{
	for (int i = 0; i < total; i++)
	{
		//�����W�ɉ����x�����Z��������
		posX[i] -= speedX[i];

		//�������~�T�C���ƃv���C���[�����������ꍇ
		if (mCollision(posX[i] + sp + 32, posY[i], sizeX*2, sizeY*2,
			player.GetPosX(), player.GetPosY(), player.sizeX, player.sizeY))
		{
			//�Q�[���N���A�ɂ���
			player.fHiting = true;

			/*player.fTouching = false;*/
			
		}

		if (player.GetPosY() <= -100 || player.GetPosY() >= 1100)
		{
			player.fOut = true;
		}

		for (int j = 0; j < total; j++)
		{
			if (player.fHiting || player.fOut)
			{
				posX[j] = returnPosX[j];
				posY[j] = returnPosY[j];
				player.fOut = false;
			}
		}

	}
}

//�`�揈��
void Missile::Draw()
{
	for (int i = 0; i < total; i++)
	{
		//�`����s
		DrawGraph(posX[i]+sp, posY[i], image, true);
	}
}

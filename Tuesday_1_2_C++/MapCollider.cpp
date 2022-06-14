#include "MapCollider.h"
MapCollider::MapCollider()
{
}

MapCollider::~MapCollider()
{
}

bool MapCollider::Cheak()
{
	return false;
}

void MapCollider::Update()
{
}

void MapCollider::ReadFileStageSize(string fileName)
{
	int characterPack;		//CSV�̃Z���̒��̕������i�[����ϐ�
	char buffer[10];		//������ϐ�
	int num;				//�^�C���̔ԍ�
	bool eofFlag = false;	//eof�iend of file�j���o�t���O

	FILE* filePointer;						//�t�@�C���̃|�C���^��錾

	fopen_s(&filePointer,fileName.c_str(), "r");	//fopen_s�֐���map.csv��ǂݎ��`���ŊJ��
	if (filePointer == NULL)				//filePointer����̏ꍇ��
	{
		DebugBreak();						//�f�o�b�O���~
	}

	memset(buffer, 0, sizeof(buffer));		//memset�֐��Ń�������buffer���Z�b�g���Asizeof���Z�q�ŗv�f�������߂�

	int maxWidth = 0;

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
			lineNum++;															//��̐��𑝂₷
		}
		if (characterPack == '\n')													//���s��������
		{
			columnNum++;															//�s�𑝂₷
			if (maxWidth < lineNum)maxWidth = lineNum;
			lineNum = 0;															//���0�ɂ���
		}
	}
	lineNum = maxWidth++;
	fclose(filePointer);
}
void MapCollider::SetStageData(string fileName)
{
	int characterPack;		//�������i�[����ϐ�
	char buffer[10];		//������ϐ�
	int num;				//�^�C���̔ԍ�
	bool eofFlag = false;	//eof�iend of file�j���o�t���O

	int width = 0;
	int height = 0;

	FILE* filePointer;						//�t�@�C���̃|�C���^��錾
	fopen_s(&filePointer, fileName.c_str(), "r");	//fopen_s�֐���map.csv��ǂݎ��`���ŊJ��
	if (filePointer == NULL)				//filePointer����̏ꍇ��
	{
		DebugBreak();						//�f�o�b�O���~
	}

	memset(buffer, 0, sizeof(buffer));		//memset�֐��Ń�������buffer���Z�b�g���Asizeof���Z�q�ŗv�f�������߂�

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
				mMapData[height].push_back(num);										//num�Ԗڂ̃`�b�v�摜�̃n���h�����擾
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
			width++;															//��̐��𑝂₷
		}
		if (characterPack == '\n')													//���s��������
		{
			height++;
			width = 0;															//���0�ɂ���
		}
	}
	fclose(filePointer);
}
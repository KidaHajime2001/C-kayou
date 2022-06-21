#pragma once

//�v���C���[
class Player
{

public:

	//������
	Player();

	//�폜
	~Player();

	//�c�@
	int credit;

	//�ʒu
	float posX;
	float posY;

	//���A�ʒu
	float returnPosX;
	float returnPosY;

	//�ʒu�擾
	float& GetPosX() { return posX; }
	float& GetPosY() { return posY; }

	//��O�̈ʒu
	float prevPosY;

	//��O�̈ʒu�擾
	float& GetprevPosY() { return prevPosY; }

	//���@
	float sizeX;
	float sizeY;

	//���x
	float speedX;
	float speedY;

	//�X�V����
	void Update();

	//�`�揈��
	void Draw();

	//�摜
	int image;

	//
	int upwardImage;

	int playerImg[12];
	int playerImgReverse[12];
	int NowImgNumber;

	int flameCount;

	int CycleImg;
	int GravityFontImg;
	int MouseImg;
	float CyclePI=0;

	int x, y;


	int gonimage;

	int goffimage;

	float gPosX;

	float gPosY;

	//�ڐG���Ă邩���ĂȂ����̔���
	bool fTouching;

	//�ڐG���Ă邩���ĂȂ����̔���
	bool fTouching2;
	
	//�~�T�C�����g�Q�ƐڐG���Ă邩���ĂȂ����̔���
	bool fHiting;

	//�N���b�N���Ă邩���ĂȂ����̔���
	bool fClick;

	//�d�͂������Ă邩�����ĂȂ����̔���
	bool fGravity;

	//��ʊO�ɏo�Ă��邩�o�Ă��Ȃ����̔���
	bool fOut;
	//��O�̈ʒu�擾
	bool& GetfOut() { return fOut; }

	//���Ԓn�_��˔j���Ă��邩�ǂ����̔���
	bool fCheckPoint;

	//�Q�[���I�[�o�[���Ă邩���ĂȂ����̔���
	bool fGameOver;

	//�Q�[���N���A���Ă邩���ĂȂ����̔���
	bool fGameClear;

};
extern Player player;
extern float sp;
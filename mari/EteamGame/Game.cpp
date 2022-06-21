//����
#include "Game.h"
#include "Title.h"
#include "Ui.h"
#include "Mouse.h"
#include "Player.h"
#include "Missile.h"
#include "Goal.h"
#include "Over.h"
#include "Clear.h"
#include "Stage.h"
#include "Collision.h"

//������
Game::Game()
	: Scene()
{

	//�摜�̓ǂݍ���
	image = LoadGraph("img/title.png");

	//�X�e�[�W����
	stage = new Stage();
	
	collision = new Collision();

	//�S�[������
	goal = new Goal;

	//�v���C���[�𐶐�
	player = new Player();

	missile = new Missile;

	//UI����
	ui = new Ui();
	ui->posX = 0;
	ui->posY = 0;

	//�}�E�X����
	mouse = new Mouse;

}

//�폜
Game::~Game()
{
}

//�X�V����
Scene* Game::Update(float _deltaTime)
{


	//�v���C���[�̍X�V����
	player->Update();

	missile->Update(*player);

		//�X�e�[�W�̍X�V����
	collision->ColBox(*player);
	int m, a, b;
	m = GetMouseInput();
	GetMousePoint(&a, &b);

	//�������}�E�X�̃t���O���I���̏�ԂŁA�����N���b�N�������ꍇ
	if (mouse->uiFlag && m & MOUSE_INPUT_LEFT != 0)
	{
		//�^�C�g����ʂֈڍs����
		return new Title();
	}

	//�������v���C���[�̃Q�[���I�[�o�[�t���O���I���̏�Ԃ̏ꍇ
	if (player->fGameOver)
	{
		//�I�[�o�[��ʂֈڍs����
		return new Over();
	}

	//�������v���C���[�̃Q�[���N���A�t���O���I���̏�Ԃ̏ꍇ
	if (player->fGameClear)
	{
		//�N���A��ʂֈڍs����
		return new Clear();
	}

	//�}�E�X�X�V����
	mouse->Update(*ui);

	//���s
	return this;
}

//�`�揈��
void Game::Draw()
{
	//�`����s
	DrawGraph(0, 0, image, true);

	//�X�e�[�W�`�揈��
	stage->View();

	//�v���C���[�`�揈��
	player->Draw();

	missile->Draw();

	//�S�[���`�揈��
	goal->Draw();

	//Ui�`�揈��
	ui->Draw();

}
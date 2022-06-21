//����
#include "Title.h"
#include "Game.h"
#include "Ui.h"
#include "Mouse.h"

//������
Title::Title()
	: Scene()
{

	//�^�C�g���摜�̓ǂݍ���
	image = LoadGraph("img/title.png");

	//UI����
	ui = new Ui();

	//�}�E�X����
	mouse = new Mouse;

}

//�폜
Title::~Title()
{
}

//�X�V����
Scene* Title::Update(float _deltaTime)
{
	int m,a,b;
	m = GetMouseInput();
	GetMousePoint(&a, &b);

	//�������}�E�X�̃t���O���I���̏�ԂŁA�����N���b�N�������ꍇ
	if (mouse->uiFlag && m & MOUSE_INPUT_LEFT != 0)
	{
		//300F�҂�
		WaitTimer(300);

		//�Q�[����ʂֈڍs����
		return new Game();

	}

	//�}�E�X�X�V����
	mouse->Update(*ui);

	//���s
	return this;

}

//�`�揈��
void Title::Draw()
{
	//�`����s
	DrawGraph(0, 0, image, true);

	//ui�`�揈��
	ui->Draw();
}
//����
#include "Over.h"
#include "Game.h"
#include "Title.h"
#include "Mouse.h"
#include "Ui.h"
#include "Player.h"

//������
Over::Over()
	: Scene()
{
	//�I�[�o�[�摜���Ăэ���
	image = LoadGraph("img/over.png");

	//UI����
	ui = new Ui();

	//�}�E�X����
	mouse = new Mouse;

}

//�폜
Over::~Over()
{
}


//�X�V����
Scene* Over::Update(float _deltaTime)
{

	int m, a, b;
	m = GetMouseInput();
	GetMousePoint(&a, &b);

	//�������}�E�X�̃t���O���I���̏�ԂŁA�����N���b�N�������ꍇ
	if (mouse->uiFlag && m & MOUSE_INPUT_LEFT != 0)
	{
		//300F�҂�
		WaitTimer(300);

		//�^�C�g����ʂֈڍs����
		return new Title();
	}

	//�}�E�X�X�V����
	mouse->Update(*ui);

	//���s
	return this;

}

//�`�揈��
void Over::Draw()
{
	//�`����s
	DrawGraph(0, 0, image, true);

	//ui�`�揈��
	ui->Draw();

	DrawFormatString(960, 540, GetColor(255, 255, 255), "�X�R�A%d", sp);
}
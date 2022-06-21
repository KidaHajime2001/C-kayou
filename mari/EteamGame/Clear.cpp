//����
#include "Clear.h"
#include "Game.h"
#include "Mouse.h"
#include "Title.h"
#include "Ui.h"

//������
Clear::Clear()
	: Scene()
{
	//�N���A�摜���Ăэ���
	image = LoadGraph("img/clear.png");

	//UI����
	ui = new Ui();

	//�}�E�X����
	mouse = new Mouse;

}

//�폜
Clear::~Clear()
{
}

//�X�V����
Scene* Clear::Update(float _deltaTime)
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
void Clear::Draw()
{

	//�`����s
	DrawGraph(0, 0, image, true);

	//ui�`�揈��
	ui->Draw();

}
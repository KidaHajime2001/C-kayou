#pragma once

//����
#include "Scene.h"

class Ui;
class Mouse;
class Player;
class Missile;
class Stage;
class Goal;
class Collision;

//�Q�[�����
class Game :public Scene
{

	Ui* ui;
	Mouse* mouse;
	Player* player;
	Missile* missile;
	Stage* stage;
	Goal* goal;
	Collision* collision;

public:

	//������
	Game();

	//�폜
	~Game();

	//�X�V����
	Scene* Update(float _deltaTime)override;

	//�`�揈��
	void Draw()override;

};
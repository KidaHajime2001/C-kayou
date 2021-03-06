#pragma once

//統括
#include "Scene.h"

class Ui;
class Mouse;
class Player;
class Missile;
class Stage;
class Goal;
class Collision;

//ゲーム画面
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

	//初期化
	Game();

	//削除
	~Game();

	//更新処理
	Scene* Update(float _deltaTime)override;

	//描画処理
	void Draw()override;

};
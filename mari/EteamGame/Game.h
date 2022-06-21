#pragma once

//“Š‡
#include "Scene.h"

class Ui;
class Mouse;
class Player;
class Missile;
class Stage;
class Goal;
class Collision;

//ƒQ[ƒ€‰æ–Ê
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

	//‰Šú‰»
	Game();

	//íœ
	~Game();

	//XVˆ—
	Scene* Update(float _deltaTime)override;

	//•`‰æˆ—
	void Draw()override;

};
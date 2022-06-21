#pragma once

//統括
#include "Scene.h"

class Ui;
class Mouse;

//クリア画面
class Clear :public Scene
{

	Ui* ui;
	Mouse* mouse;

public:

	//初期化
	Clear();

	//削除
	~Clear();

	//更新処理
	Scene* Update(float _deltaTime)override;

	//描画処理
	void Draw()override;

};
#pragma once

//統括
#include "Scene.h"

class Ui;
class Mouse;

//オーバー画面
class Over :public Scene
{

	Ui* ui;
	Mouse* mouse;

public:

	//初期化
	Over();

	//削除
	~Over();

	//更新処理
	Scene* Update(float _deltaTime)override;

	//描画処理
	void Draw()override;

};
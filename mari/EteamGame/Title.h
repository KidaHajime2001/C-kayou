#pragma once

//統括
#include"Scene.h"

class Ui;
class Mouse;

//タイトル画面
class Title :public Scene
{

	Ui* ui;
	Mouse* mouse;

public:

	//初期化
	Title();

	//削除
	~Title();

	//更新処理
	Scene* Update(float _deltaTime)override;

	//描画処理
	void Draw()override;

};
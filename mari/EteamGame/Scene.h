#pragma once

//統括
#include "DxLib.h"

//画面
class Scene
{
public:
	
	//初期化
	Scene();

	//削除
	~Scene();

	//更新処理
	virtual Scene* Update(float _deltaTime) = 0;

	//描画処理
	virtual void Draw() = 0;

protected:

	//画像
	int image;

};
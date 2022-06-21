#pragma once
class Goal
{
public:
	//初期化
	Goal();

	//削除
	~Goal();

	//位置
	float posX;
	float posY;

	//寸法
	float sizeX;
	float sizeY;

	//画像
	int image;

	//描画処理
	void Draw();
};

//共有化
extern Goal goal;
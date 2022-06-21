#pragma once

//共有化
class Player;

//ミサイル
class Missile
{
public:

	//初期化
	Missile();

	//削除
	~Missile();

	//位置
	float posX[10] = {0};
	float posY[10] = {0};

	//復帰位置
	float returnPosX[10] = { 0 };
	float returnPosY[10] = { 0 };

	//位置取得
	float& GetPosX() { return posX[0]; }
	float& GetPosY() { return posY[0]; }

	//ミサイルの総数
	int total;

	//寸法
	float sizeX;
	float sizeY;

	//速度
	float speedX[10] = { 0 };
	float speedY[10] = { 0 };

	//更新処理
	void Update(Player& player);

	//描画処理
	void Draw();

	//画像
	int image;

};
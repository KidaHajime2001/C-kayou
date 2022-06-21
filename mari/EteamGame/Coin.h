#pragma once

//コイン
class Coin
{
public:
	//初期化
	Coin();

	//削除
	~Coin();

	//位置
	float posX;
	float posY;

	//寸法
	float sizeX;
	float sizeY;

	//画像
	int image[3];

	//フラグ
	bool Flag;
};

//共有化
extern Coin coin[1000];
extern int coinCount;
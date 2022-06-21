#pragma once

//Hit
class Hit
{
public:

	////初期化
	//Hit();

	////削除
	//~Hit();

	//位置
	float posX;
	float posY;

	//位置取得
	float& GetPosX() { return posX; }
	float& GetPosY() { return posY; }

	//寸法
	float sizeX;
	float sizeY;

	//位置取得
	float& GetSizeX() { return sizeX; }
	float& GetSizeY() { return sizeY; }

};

//共有化
extern Hit hit;
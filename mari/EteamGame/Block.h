#pragma once

//ブロック
class Block
{
public:
	//初期化
	Block();

	//削除
	~Block();

	//位置
	float posX;
	float posY;

	//寸法
	float sizeX;
	float sizeY;

	//画像
	int image;
};

//共有化
extern Block block[1000];
extern int blockCount;
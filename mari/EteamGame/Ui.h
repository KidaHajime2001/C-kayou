#pragma once

//UI
class Ui
{
public:

	//初期化
	Ui();

	//削除
	~Ui();

	//位置
	float posX;
	float posY;

	//位置取得
	float& GetPosX() { return posX; }
	float& GetPosY() { return posY; }

	//寸法
	float sizeX;
	float sizeY;

	//画像
	int image;

	//描画処理
	void Draw();

};

//共有化
extern Ui ui;
#pragma once

//共有化
class Ui;

//マウス
class Mouse
{
public:

	//初期化
	Mouse();

	//削除
	~Mouse();

	//位置
	int posX;
	int posY;
	
	//寸法
	float sizeX;
	float sizeY;

	//更新
	void Update(Ui&ui);

	//判定
	bool uiFlag;

};
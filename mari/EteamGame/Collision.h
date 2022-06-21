#pragma once

#define COLLISION_CELL_WIDTH 40											//当たり判定BOXの幅
#define COLLISION_CELL_HEIGHT 40										//当たり判定BOXの高さ
#define COLLISION_CELL_NUM_X 300											//当たり判定BOXの横方向の数
#define COLLISION_CELL_NUM_Y 30											//当たり判定BOXの縦方向の数
#define COLLISION_WINDOW_X 1600											//ウィンドウの幅
#define COLLISION_WINDOW_Y 480											//ウィンドウの高さ


//共有化
class Player;

//当たり判定
bool mCollision(float posX1, float posY1, float sizeX1, float sizeY1, float posX2, float posY2, float sizeX2, float sizeY2);

struct collisionCell														//当たり判定BOX用の構造体を作る
{
	int collisionBoxHandle;													//当たり判定管理用の変数
};

class Collision																	//背景当たり判定クラスを作る
{
public:

	//初期化
	Collision();

	//削除
	~Collision();


	void ColBox(Player&player);

};

//extern struct collisionCell
//{
//	int collisionBoxHandle;
//};
extern int collisionBoxHandle[2];												//当たり判定BOX絵の総数を掛け算で出す
extern struct collisionCell collisionCell[COLLISION_CELL_NUM_X][COLLISION_CELL_NUM_Y];
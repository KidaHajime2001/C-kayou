//統括
#include <DxLib.h>
#include <math.h>
#include <time.h>
#include"Collision.h"
#include "Player.h"

struct collisionCell collisionCell[COLLISION_CELL_NUM_X][COLLISION_CELL_NUM_Y];

//当たり判定
bool mCollision(float posX1, float posY1, float sizeX1, float sizeY1, float posX2, float posY2, float sizeX2, float sizeY2)
{
	if (posX1 + (sizeX1 / 2.0f) > posX2 - (sizeX2 / 2.0f) &&
		posX1 - (sizeX1 / 2.0f) < posX2 + (sizeX2 / 2.0f) &&
		posY1 + (sizeY1 / 2.0f) > posY2 - (sizeY2 / 2.0f) &&
		posY1 - (sizeY1 / 2.0f) < posY2 + (sizeY2 / 2.0f))
	{
		return true;
	}
	return false;
}

int collisionBoxHandle[2];												//当たり判定BOX絵の総数を掛け算で出す
int collisionBoxX;														//背景当たり判定BOXのX座標
int collisionMarker;													//文字を格納する変数
int collisionRawNum = 0;												//横方向の当たり判定BOXナンバー
int collisionColumnNum = 0;												//縦方向の当たり判定BOXナンバー
int collisionNum;														//当たり判定BOXの番号
int ci;																	//for文カウンター
int cj;																	//for文カウンター
char collisionBuffer[10];												//文字列変数
bool collisionEofFlag = false;											//eof（end of file）検出フラグ

Collision::Collision()
{
	collisionRawNum = 0;												//横方向の当たり判定BOXナンバー
	collisionColumnNum = 0;												//縦方向の当たり判定BOXナンバー
	collisionRawNum = 0;												//横方向の当たり判定BOXナンバー
	collisionColumnNum = 0;												//縦方向の当たり判定BOXナンバー
	collisionEofFlag = false;											//eof（end of file）検出フラグ
	LoadDivGraph("img/collision_check.png", 2, 2, 1, 32, 32, collisionBoxHandle);//当たり判定チェック用画像
	FILE* collisionFilePointer;												//ファイルのポインタを宣言
	fopen_s(&collisionFilePointer, "Data/collision.csv", "r");					//fopen_s関数でcollision.csvを読み取り形式で開く
	if (collisionFilePointer == NULL)										//collisionFilePointerが空の場合は
	{
		DebugBreak();														//デバッグ中止
	}


	memset(collisionBuffer, 0, sizeof(collisionBuffer));					//memset関数でメモリにbufferをセットし、sizeof演算子で要素数を決める

	while (1)
	{
		while (1)
		{
			collisionMarker = fgetc(collisionFilePointer);						//fgetc関数でfilepointerから文字を読んでcharacterPackに格納
			if (collisionMarker == EOF)
			{
				collisionEofFlag = true;									//EndOfFileを検出して
				break;														//ループを抜ける
			}
			if (collisionMarker != ',' && collisionMarker != '\n')			//区切りか改行でなければ
			{
				strcat_s(collisionBuffer, (const char*)&collisionMarker);	//strcat_s関数でbufferに連結し、const char関数で書き換える
			}
			else
			{
				collisionNum = atoi(collisionBuffer);						//atoi関数でbufferをint型に直して、ローカル変数numに代入
				collisionCell[collisionColumnNum][collisionRawNum].collisionBoxHandle = collisionBoxHandle[collisionNum];		//num番目のチップ画像のハンドルを取得
				memset(collisionBuffer, 0, sizeof(collisionBuffer));		//bufferをリセット
				break;														//区切りか改行なのでループを抜ける
			}
		}
		if (collisionEofFlag)												//1マップ分になったら
		{
			break;															//ループを抜ける
		}
		if (collisionMarker == ',')											//区切りを検出したら
		{
			collisionColumnNum++;											//列の数を増やす
		}
		if (collisionMarker == '\n')										//改行だったら
		{
			collisionRawNum++;												//行を増やす
			collisionColumnNum = 0;											//列を0にする
		}
	}
	fclose(collisionFilePointer);
}

Collision::~Collision()
{
}

void Collision::ColBox(Player& player)
{
		const int playerW = 32;
		const int playerH = 64;

		int playerLX = player.GetPosX() - playerW - sp; // 左上X
		int playerLY = player.GetPosY() - playerH;            // 左上Y
		int playerRX = player.GetPosX() + playerW - sp; // 右下X
		int playerRY = player.GetPosY() + playerH;            // 右下Y

		int playerLX2 = player.GetPosX(); // 左下X
		int playerLY2 = player.GetPosY();            // 左下Y
		int playerRX2 = player.GetPosX(); // 右上X
		int playerRY2 = player.GetPosY();            // 右上Y

		int playerVY = player.GetPosY() - player.GetprevPosY();

		int idLX = playerLX / COLLISION_CELL_WIDTH;  // 左上X添え字
		int idLY = playerLY / COLLISION_CELL_HEIGHT; // 左上Y添え字
		int idRX = playerRX / COLLISION_CELL_WIDTH;  // 右下X添え字
		int idRY = playerRY / COLLISION_CELL_HEIGHT; // 右下Y添え字

		int idLX2 = playerLX2 / COLLISION_CELL_WIDTH;  // 左上X添え字
		int idLY2 = playerLY2 / COLLISION_CELL_HEIGHT; // 左上Y添え字
		int idRX2 = playerRX2 / COLLISION_CELL_WIDTH;  // 右下X添え字
		int idRY2 = playerRY2 / COLLISION_CELL_HEIGHT; // 右下Y添え字

		int blkLX;
		int blkLY;
		int blkRX;
		int blkRY;

		if (idLY < 0 || idRY < 0)
		{
			return;
		}
		
		
		for (int iy = idLY; iy < idRY + 1; iy++)
		{
			for (int ix = idLX; ix < idRX + 1; ix++)
			{
				// そこはブロックか？
				if (collisionCell[ix][iy].collisionBoxHandle == collisionBoxHandle[1])
				{
					//ブロック左上右下座標
					blkLX = ix * COLLISION_CELL_WIDTH;
					blkLY = iy * COLLISION_CELL_HEIGHT;
					blkRX = blkLX + COLLISION_CELL_WIDTH;
					blkRY = blkLY + COLLISION_CELL_HEIGHT;

					//本当に当たっているか？
					if (playerLX <= blkRX && blkLX <= playerRX &&
						playerLY <= blkRY && blkLY <= playerRY)
					{
						// 衝突したのでめり込みを戻す（リアクション）
						//ブロックの上端とぶつかった
						if ((playerRY - blkLY > 0) &&
							(playerRY - blkLY <= 64) &&
							(collisionCell[ix][iy - 1].collisionBoxHandle == collisionBoxHandle[0]) &&
							((collisionCell[ix - 1][iy].collisionBoxHandle == collisionBoxHandle[1]) ||
							(collisionCell[ix + 1][iy].collisionBoxHandle == collisionBoxHandle[1])))
						{
							if (player.fGravity)
							{
								player.posY = blkLY - playerH;
								player.fTouching = true;
							}
						}
						// 衝突したのでめり込みを戻す（リアクション）
						//ブロックの下端とぶつかった
						if ((blkRY - playerLY >= 64) &&
							(blkRY - playerLY <= 128) &&
							(collisionCell[ix][iy + 1].collisionBoxHandle == collisionBoxHandle[0]) &&
							((collisionCell[ix - 1][iy].collisionBoxHandle == collisionBoxHandle[1]) ||
							(collisionCell[ix + 1][iy].collisionBoxHandle == collisionBoxHandle[1])))
						{
							if (!player.fGravity)
							{
								player.posY = blkRY;
								player.fTouching = true;
							}
						}
						// 衝突したのでめり込みを戻す（リアクション）
						//ブロックの左側とぶつかった
						if (player.fGravity)
						{
							if ((playerRX - blkLX > 0) &&
								(playerRX - blkLX <= 64) &&
								(collisionCell[ix][iy + 1].collisionBoxHandle == collisionBoxHandle[1]) /*&&
								(playerVY > 0)*/)
							{
								player.posX = blkLX - 36;
								/*if (player.fGravity)
								{

									player.fTouching = true;
								}*/
							}
						}
						if (!player.fGravity)
						{
							if ((playerRX - blkLX > 0) &&
								(playerRX - blkLX <= 64) &&
								(collisionCell[ix][iy - 1].collisionBoxHandle == collisionBoxHandle[1]) /*&&
								(playerVY > 0)*/)
							{
								player.posX = blkLX - 36;
								/*if (player.fGravity)
								{

									player.fTouching = true;
								}*/
							}
						}
					}
				}
			}
		}

		// 足元を調べる
		idRY = (player.GetPosY() + 64) / COLLISION_CELL_HEIGHT;
		//ジャンプ中でないのに、両足とも空中にいないか？
		if (player.fTouching && player.fGravity &&
			(collisionCell[idLX][idRY].collisionBoxHandle == collisionBoxHandle[0]) &&
			(collisionCell[idRX][idRY].collisionBoxHandle == collisionBoxHandle[0]))
		{
			player.fTouching = false;
			
		}

		// 頭上を調べる
		idRY = (player.posY - 64) / COLLISION_CELL_HEIGHT;
		//ジャンプ中でないのに、両足とも空中にいないか？
		if (player.fTouching && !player.fGravity &&
			(collisionCell[idLX][idRY].collisionBoxHandle == collisionBoxHandle[0]) &&
			(collisionCell[idRX][idRY].collisionBoxHandle == collisionBoxHandle[0]))
		{
			player.fTouching = false;
		}
}

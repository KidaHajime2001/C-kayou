#pragma once
#pragma once
#include <DxLib.h>
#include"Collision.h"
#define CELL_WIDTH 40													//タイルの幅
#define CELL_HEIGHT 40													//タイルの高さ
#define CELL_NUM_X 40													//タイルの横方向の数
#define CELL_NUM_Y 12													//タイルの縦方向の数
#define WINDOW_X 1600													//ウィンドウの幅
#define WINDOW_Y 480													//ウィンドウの高さ

int chipgraphicHandle[(256 / 32) * (256 / 32)];							//タイル絵の総数を掛け算で出す
int tileImgX;															//背景画像のX座標
int characterPack;														//文字を格納する変数
int rawNum = 0;															//横方向のタイルナンバー
int columnNum = 0;														//縦方向のタイルナンバー
int num;																//タイルの番号
int i;																	//for文カウンター
int j;																	//for文カウンター
char buffer[10];														//文字列変数
bool eofFlag = false;													//eof（end of file）検出フラグ

struct Cell																			//タイル用の構造体を作る
{
	int graphicHandle;	//画像操作用の変数
	Collision* collision;
};

class Map																									//mapクラスを作る
{
public:

	Cell cell[CELL_NUM_X][CELL_NUM_Y];																		//構造体にタイルの横縦を格納する

	Map()
	{
		LoadDivGraph("img/map3.png", (256 / 32) * (256 / 32), 256 / 32, 256 / 32, 32, 32, chipgraphicHandle);	//タイル画像を読み込む
		FILE* filePointer;																					//ファイルのポインタを宣言
		fopen_s(&filePointer, "map.csv", "r");																//fopen_s関数でmap.csvを読み取り形式で開く
		if (filePointer == NULL)																			//filePointerが空の場合は
		{
			DebugBreak();																					//デバッグ中止
		}

		memset(buffer, 0, sizeof(buffer));																	//memset関数でメモリにbufferをセットし、sizeof演算子で要素数を決める

		while (1)
		{
			while (1)
			{
				characterPack = fgetc(filePointer);										//fgetc関数でfilepointerから文字を読んでcharacterPackに格納
				if (characterPack == EOF)
				{
					eofFlag = true;														//EndOfFileを検出して
					break;																//ループを抜ける
				}
				if (characterPack != ',' && characterPack != '\n')						//区切りか改行でなければ
				{
					strcat_s(buffer, (const char*)&characterPack);						//strcat_s関数でbufferに連結し、const char関数で書き換える
				}
				else
				{
					num = atoi(buffer);													//atoi関数でbufferをint型に直して、ローカル変数numに代入
					cell[columnNum][rawNum].graphicHandle = chipgraphicHandle[num];		//num番目のチップ画像のハンドルを取得
					memset(buffer, 0, sizeof(buffer));									//bufferをリセット
					break;																//区切りか改行なのでループを抜ける
				}
			}
			if (eofFlag)																//1マップ分になったら
			{
				break;																	//ループを抜ける
			}
			if (characterPack == ',')													//区切りを検出したら
			{
				columnNum++;															//列の数を増やす
			}
			if (characterPack == '\n')													//改行だったら
			{
				rawNum++;																//行を増やす
				columnNum = 0;															//列を0にする
			}
		}
		fclose(filePointer);															//ファイルを閉じる
	}

	void View()
	{
		for (i = 0; i < CELL_NUM_X; i++)
		{
			for (j = 0; j < CELL_NUM_Y; j++)
			{
				DrawExtendGraph(i * CELL_WIDTH + tileImgX, j * CELL_HEIGHT, (i + 1) * CELL_WIDTH + tileImgX, (j + 1) * CELL_HEIGHT, cell[i][j].graphicHandle, TRUE);
			}
		}
	}

	void All()
	{
		View();
	}

};
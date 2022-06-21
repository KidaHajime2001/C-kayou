#pragma once

#define CELL_WIDTH 40													//タイルの幅
#define CELL_HEIGHT 40													//タイルの高さ
#define CELL_NUM_X 300													//タイルの横方向の数
#define CELL_NUM_Y 28													//タイルの縦方向の数
#define WINDOW_X 1600													//ウィンドウの幅
#define WINDOW_Y 480													//ウィンドウの高さ


class Stage																									//mapクラスを作る
{
public:									//構造体にタイルの横縦を格納する

	//初期化
	Stage();

	//削除
	~Stage();

	void View();

};
//統括
#include "Ui.h"
#include "Title.h"

//共有化
Ui ui;

//初期化
Ui::Ui()
	:posX(820.0f)
	,posY(400.0f)
	,sizeX(100.0f)
	,sizeY(100.0f)
{
	//画像の読み込み
	image = LoadGraph("img/start.png");
}

//削除
Ui::~Ui()
{
}

//描画処理
void Ui::Draw()
{
	//描画実行
	DrawGraph(posX, posY, image, true);
}
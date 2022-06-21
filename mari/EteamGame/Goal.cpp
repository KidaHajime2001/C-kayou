//“Š‡
#include "DxLib.h"
#include "Goal.h"
#include "Player.h"

//‹¤—L‰»
Goal goal;

//‰Šú‰»
Goal::Goal()
	:posX(10000.0f)
	,posY(0.0f)
	,sizeX(1.0f)
	,sizeY(2000.0f)
{
	image = LoadGraph("img/Goal.png");
}

//íœ
Goal::~Goal()
{
}

//•`‰æˆ—
void Goal::Draw()
{
	//•`‰æÀs
	DrawGraph(posX + sp, posY, image, true);
}

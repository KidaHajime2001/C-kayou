//“Š‡
#include "Ui.h"
#include "Title.h"

//‹¤—L‰»
Ui ui;

//‰Šú‰»
Ui::Ui()
	:posX(820.0f)
	,posY(400.0f)
	,sizeX(100.0f)
	,sizeY(100.0f)
{
	//‰æ‘œ‚Ì“Ç‚İ‚İ
	image = LoadGraph("img/start.png");
}

//íœ
Ui::~Ui()
{
}

//•`‰æˆ—
void Ui::Draw()
{
	//•`‰æÀs
	DrawGraph(posX, posY, image, true);
}
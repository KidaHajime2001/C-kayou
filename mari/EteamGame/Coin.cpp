//“Š‡
#include "DxLib.h"
#include "Coin.h"

//‹¤—L‰»
Coin coin[1000];
int coinCount = 0;

//‰Šú‰»
Coin::Coin()
	:posX(0)
	,posY(0)
	,sizeX(0)
	,sizeY(0)
	,Flag(true)
{
	coinCount = 0;
	LoadDivGraph("img/COIN.png", 3, 3, 1, 50, 50, image);
	/*int frameCount3;

	int timerCount = GetNowCount();int frameCount = timerCount % 8;
	frameCount3 = timerCount / 125 % 3;
	DrawRotaGraph(posX, posY, 1.0f, 0, image[frameCount3], TRUE);*/
}

//íœ
Coin::~Coin()
{
}
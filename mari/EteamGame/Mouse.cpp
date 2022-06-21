//統括
#include "Mouse.h"
#include "Ui.h"
#include "Title.h"
#include "Game.h"
#include "Collision.h"

//初期化
Mouse::Mouse()
	:posX(0.0f)
	,posY(0.0f)
	,sizeX(15.0f)
	,sizeY(15.0f)
	,uiFlag(false)
{
}

//削除
Mouse::~Mouse()
{
}

//更新
void Mouse::Update(Ui& ui)
{
	//マウスの位置を取得し代入する
	GetMousePoint(&posX, &posY);

	//もしもマウスがUiと当たった場合
	if (mCollision(posX, posY, sizeX, sizeY, ui.GetPosX() + 100, ui.GetPosY() + 100, ui.sizeX, ui.sizeY))
	{
		//フラグをオンにする
		uiFlag = true;
	}
}
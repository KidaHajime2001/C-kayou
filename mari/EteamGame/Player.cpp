//統括
#include "Player.h"
#include "Ui.h"
#include "Title.h"
#include "Game.h"
#include "Collision.h"
#include "Stage.h"
#include "block.h"
#include "Goal.h"
#include "Hit.h"
#include "Define.h"
#include <math.h>

//共有化
Player player;

float sp = 0.0f;

//初期化
Player::Player()
	:credit(3)
	,posX(50.0f)
	,posY(50.0f)
	,returnPosX(50.0f)
	,returnPosY(50.0f)
	,sizeX(32.0f)
	,sizeY(64.0f)
	,speedX(0.0f)
	,speedY(0.0f)
	,fClick(false)
	,fCheckPoint(false)
	,fGravity(true)
	,fTouching(false)
	,fTouching2(false)
	,fHiting(false)
	,fOut(false)
	,fGameOver(false)
	,fGameClear(false)
{
	sp = 0.0f;
	//画像読み込み
	image = LoadGraph("img/p3k.png");
	LoadDivGraph("img/playerImg.png",12,12,1,64,64,playerImg);
	LoadDivGraph("img/playerImgReverse.png", 12, 12, 1, 64, 64, playerImgReverse);
	NowImgNumber = 0;
	gonimage = LoadGraph("img/gOn.png");

	goffimage = LoadGraph("img/gOff.png");

	CycleImg = LoadGraph("img/CycleRink.png");
	GravityFontImg= LoadGraph("img/gravity.png");
	MouseImg= LoadGraph("img/Mouse.png");
	x = 0;
	y = 0;

	//セルの行数
	int cellLine;
	
	//ファイル
	int file;	  
	
	//ファイル名
	char fileName[32] = { "Data/player.csv" };

	//現在のセル
	int nowCell[64];

	//セルデータ
	char cellData[64];



	

	//ファイル読み込み開始
	file = FileRead_open(fileName);	

	//ファイルが無い場合
	if (file == NULL)
	{

		//"read error"と表示する
		printfDx("read error\n");

		//終了する
		return;

	}

	//ファイルの最初の2行間の間
	for (int i = 0; i < 2; i++)				
	{
		////改行までループする
		while (FileRead_getc(file) != '\n');
	}

	//セルの行数を0にする
	cellLine = 0;

	//実行中の間
	while (1)
	{
		for (int i = 0; i < 64; i++)
		{
			//1文字取得する
			cellData[i] = nowCell[i] = FileRead_getc(file);

			//もしもスラッシュがある場合
			if (cellData[i] == '/')								
			{

				//改行までループする
				while (FileRead_getc(file) != '\n');

				//iに-1を代入する
				i = -1;

				//続行する
				continue;
			}

			//もしもカンマか改行の場合
			if (nowCell[i] == ',' || nowCell[i] == '\n')			//カンマか改行なら
			{

				//文字列に変換する
				cellData[i] = '\0';

				//終了する
				break;
			}

			//もしもファイルが終わる場合
			if (nowCell[i] == EOF)
			{
				//EXFILE処理に移行する
				goto EXFILE;
			}
		}

		//セルの行数を条件式にする
		switch (cellLine)
		{

		//セルの行数が0の場合
		case 0:

			//X軸の速さにセル内の数値を代入する
			speedX = atoi(cellData);

			//終了する
			break;

		//セルの行数が1の場合
		case 1:

			//Y軸の速さにセル内の数値を代入する
			speedY = atoi(cellData); 

			//終了する
			break;

		}

		//セルの行数に1を足す
		cellLine++;

		//セルの行数が2の場合
		if (cellLine == 2)
		{
			//セルの行数を0にする
			cellLine = 0;

		}
	}

	//EXFILE処理:ファイル読み込み終了
	EXFILE:FileRead_close(file);
	
}

//削除
Player::~Player()
{
}

//更新処理
void Player::Update()
{	
	if (CheckHitKey(KEY_INPUT_UP))
	{
		y--;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		y++;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		x--;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		x++;
	}
	//もしも左クリックをした場合
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0 )
	{
		//もしも、クリックされていない状態の場合
		if (!fClick)
		{
			//左クリックしている状態にする
			fClick = true;

			//もしも、ブロックに当たっている状態の場合
			if (fTouching)
			{
				//当たっていない状態にする
				fTouching = false;
				
				//もしも重力が働いている状態の場合
				if (fGravity)
				{
					//重力が働いていない状態にする
					fGravity = false;
				}
				else
				{
					//重力が働いている状態にする
					fGravity = true;
				}
			}
		}
	}
	//もしも左クリックをしていない場合
	else
	{
		//左クリックしていない状態にする
		fClick = false;
	}
	
	if (posX >= 960)
	{
		posX = 960;
	}

	//もしもブロックと当たっていない場合
	if (!fTouching)
	{
		//もしも重力が働いている場合
		if (fGravity)
		{
			//縦座標に縦速度を加算し続ける
			posY += speedY;
		}
		else
		{
			//縦座標に縦速度を減算し続ける
			posY -= speedY;
		}
		sp -= 0;
	}
	//もしもブロックと当たっている場合
	else
	{
		//横座標に横速度を加算し続ける
		if (posX < 960)
		{
			posX += speedX;
			
		}
		
		if (posX >= 960)
		{
			sp -= speedX;
		}
	}

	//
	if (posY <= -100 || posY >= 1100)
	{
		fOut = true;
	}

	//もしもプレイヤーのY座標が画面外に出たか、ミサイルかトゲに当たった場合
	if (fOut || fHiting)
	{

		//残機を一つ減らす
		credit -= 1;

		//重力をリセットする
		fGravity = true;

		fTouching = false;

		sp = 0;

		//300F待つ
		WaitTimer(300);

		//もしも中間地点を突破していない場合
		if (!fCheckPoint)
		{
			//位置に復帰位置を代入する
			posX = returnPosX;
			posY = returnPosY;
		}
		//もしも中間地点を突破している場合
		else
		{
			//復帰位置に中間地点の位置を代入する
			

			//位置に初期位置を代入する
			posX = returnPosX;
			posY = returnPosY;
		}

		//ミサイルにもトゲにも当たっていない状態にする
		fHiting = false;

		////ミサイルにもトゲにも当たっていない状態にする
		//fOut = false;
	}

	//もしも残機が0以下になった場合
	if (credit <= 0)
	{

		//ゲームオーバーにする
		fGameOver = true;

	}

	//もしもプレイヤーとゴールが当たった場合
	if (mCollision(posX - 300, posY, sizeX, sizeY,
		goal.posX + sp, goal.posY, goal.sizeX, goal.sizeY))
	{

		//ゲームクリアにする
		fGameClear = true;

	}

}

//描画処理
void Player::Draw()
{
	bool beforFlag=fGravity;
	//描画実行
	DrawFormatString(50, 100, GetColor(255, 255, 255), "残機%d", credit);
	DrawFormatString(50,150, GetColor(255, 255, 255),"x:%d",x);
	DrawFormatString(50, 200, GetColor(255, 255, 255), "y:%d", y);
	if (fGravity)
	{
		//描画実行
		DrawGraph(posX, posY, playerImg[NowImgNumber / 5], true); DrawRotaGraph(1350+x, 110+y, 1.0, 3.14 / 4, CycleImg, TRUE);

	}
	else
	{
		//描画実行
		DrawGraph(1800, 100, goffimage, false);
		DrawGraph(posX, posY, playerImgReverse[NowImgNumber / 5], true);
		DrawRotaGraph(1350, 100, 1.0, 3.14 / 4, CycleImg, TRUE);
	}

	DrawExtendGraph(1450, 60, 1450 + 500, 60 + 200, GravityFontImg, true);//1450,60
	DrawGraph(1750, 60, MouseImg, true);//1300,50
	if (beforFlag!=fGravity)
	{
		DrawRotaGraph(1300, 50, 2.0, 3.14 / 4,CycleImg, TRUE);
		
	}
	NowImgNumber++;
	if (NowImgNumber>=12*5)
	{
		NowImgNumber = 0;
	}
}

//統括
#include "DxLib.h"
#include "Missile.h"
#include "Player.h"
#include "Collision.h"

//共有化
Missile missile[1000];
int missileCount = 0;

//初期化
Missile::Missile()
	:sizeX(64)
	,sizeY(32)
{
	//画像読み込み
	image = LoadGraph("img/missile.png");

	//セルの行数
	int cellLine;

	//ファイル
	int file;

	//ファイル名
	char fileName[32] = { "Data/missile.csv" };

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

	//ミサイルの総数を0にする
	total = 0;

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

			//X座標にセル内の数値を代入する
			posX[total] = atoi(cellData);
			returnPosX[total] = atoi(cellData);
			//終了する
			break;

			//セルの行数が1の場合
		case 1:

			//Y座標にセル内の数値を代入する
			posY[total] = atoi(cellData);
			returnPosY[total] = atoi(cellData);
			//終了する
			break;

		case 2:

			//X軸の速さにセル内の数値を代入する
			speedX[total] = atoi(cellData);

			//終了する
			break;

		}

		//セルの行数に1を足す
		cellLine++;

		//セルの行数が2の場合
		if (cellLine == 3)
		{
			//セルの行数を0にする
			cellLine = 0;

			//ミサイルの総数に1を足す
			total++;

		}
	}

	//EXFILE処理:ファイル読み込み終了
EXFILE:FileRead_close(file);

}

//削除
Missile::~Missile()
{
}

//更新処理
void Missile::Update(Player& player)
{
	for (int i = 0; i < total; i++)
	{
		//横座標に横速度を加算し続ける
		posX[i] -= speedX[i];

		//もしもミサイルとプレイヤーが当たった場合
		if (mCollision(posX[i] + sp + 32, posY[i], sizeX*2, sizeY*2,
			player.GetPosX(), player.GetPosY(), player.sizeX, player.sizeY))
		{
			//ゲームクリアにする
			player.fHiting = true;

			/*player.fTouching = false;*/
			
		}

		if (player.GetPosY() <= -100 || player.GetPosY() >= 1100)
		{
			player.fOut = true;
		}

		for (int j = 0; j < total; j++)
		{
			if (player.fHiting || player.fOut)
			{
				posX[j] = returnPosX[j];
				posY[j] = returnPosY[j];
				player.fOut = false;
			}
		}

	}
}

//描画処理
void Missile::Draw()
{
	for (int i = 0; i < total; i++)
	{
		//描画実行
		DrawGraph(posX[i]+sp, posY[i], image, true);
	}
}

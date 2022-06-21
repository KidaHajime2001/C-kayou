//統括
#include "Over.h"
#include "Game.h"
#include "Title.h"
#include "Mouse.h"
#include "Ui.h"
#include "Player.h"

//初期化
Over::Over()
	: Scene()
{
	//オーバー画像を呼び込む
	image = LoadGraph("img/over.png");

	//UI生成
	ui = new Ui();

	//マウス生成
	mouse = new Mouse;

}

//削除
Over::~Over()
{
}


//更新処理
Scene* Over::Update(float _deltaTime)
{

	int m, a, b;
	m = GetMouseInput();
	GetMousePoint(&a, &b);

	//もしもマウスのフラグがオンの状態で、かつ左クリックをした場合
	if (mouse->uiFlag && m & MOUSE_INPUT_LEFT != 0)
	{
		//300F待つ
		WaitTimer(300);

		//タイトル画面へ移行する
		return new Title();
	}

	//マウス更新処理
	mouse->Update(*ui);

	//続行
	return this;

}

//描画処理
void Over::Draw()
{
	//描画実行
	DrawGraph(0, 0, image, true);

	//ui描画処理
	ui->Draw();

	DrawFormatString(960, 540, GetColor(255, 255, 255), "スコア%d", sp);
}
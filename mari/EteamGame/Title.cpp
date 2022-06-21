//統括
#include "Title.h"
#include "Game.h"
#include "Ui.h"
#include "Mouse.h"

//初期化
Title::Title()
	: Scene()
{

	//タイトル画像の読み込み
	image = LoadGraph("img/title.png");

	//UI生成
	ui = new Ui();

	//マウス生成
	mouse = new Mouse;

}

//削除
Title::~Title()
{
}

//更新処理
Scene* Title::Update(float _deltaTime)
{
	int m,a,b;
	m = GetMouseInput();
	GetMousePoint(&a, &b);

	//もしもマウスのフラグがオンの状態で、かつ左クリックをした場合
	if (mouse->uiFlag && m & MOUSE_INPUT_LEFT != 0)
	{
		//300F待つ
		WaitTimer(300);

		//ゲーム画面へ移行する
		return new Game();

	}

	//マウス更新処理
	mouse->Update(*ui);

	//続行
	return this;

}

//描画処理
void Title::Draw()
{
	//描画実行
	DrawGraph(0, 0, image, true);

	//ui描画処理
	ui->Draw();
}
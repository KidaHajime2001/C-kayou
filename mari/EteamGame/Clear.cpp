//統括
#include "Clear.h"
#include "Game.h"
#include "Mouse.h"
#include "Title.h"
#include "Ui.h"

//初期化
Clear::Clear()
	: Scene()
{
	//クリア画像を呼び込む
	image = LoadGraph("img/clear.png");

	//UI生成
	ui = new Ui();

	//マウス生成
	mouse = new Mouse;

}

//削除
Clear::~Clear()
{
}

//更新処理
Scene* Clear::Update(float _deltaTime)
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
void Clear::Draw()
{

	//描画実行
	DrawGraph(0, 0, image, true);

	//ui描画処理
	ui->Draw();

}
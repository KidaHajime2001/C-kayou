//統括
#include "Game.h"
#include "Title.h"
#include "Ui.h"
#include "Mouse.h"
#include "Player.h"
#include "Missile.h"
#include "Goal.h"
#include "Over.h"
#include "Clear.h"
#include "Stage.h"
#include "Collision.h"

//初期化
Game::Game()
	: Scene()
{

	//画像の読み込み
	image = LoadGraph("img/title.png");

	//ステージ生成
	stage = new Stage();
	
	collision = new Collision();

	//ゴール生成
	goal = new Goal;

	//プレイヤーを生成
	player = new Player();

	missile = new Missile;

	//UI生成
	ui = new Ui();
	ui->posX = 0;
	ui->posY = 0;

	//マウス生成
	mouse = new Mouse;

}

//削除
Game::~Game()
{
}

//更新処理
Scene* Game::Update(float _deltaTime)
{


	//プレイヤーの更新処理
	player->Update();

	missile->Update(*player);

		//ステージの更新処理
	collision->ColBox(*player);
	int m, a, b;
	m = GetMouseInput();
	GetMousePoint(&a, &b);

	//もしもマウスのフラグがオンの状態で、かつ左クリックをした場合
	if (mouse->uiFlag && m & MOUSE_INPUT_LEFT != 0)
	{
		//タイトル画面へ移行する
		return new Title();
	}

	//もしもプレイヤーのゲームオーバーフラグがオンの状態の場合
	if (player->fGameOver)
	{
		//オーバー画面へ移行する
		return new Over();
	}

	//もしもプレイヤーのゲームクリアフラグがオンの状態の場合
	if (player->fGameClear)
	{
		//クリア画面へ移行する
		return new Clear();
	}

	//マウス更新処理
	mouse->Update(*ui);

	//続行
	return this;
}

//描画処理
void Game::Draw()
{
	//描画実行
	DrawGraph(0, 0, image, true);

	//ステージ描画処理
	stage->View();

	//プレイヤー描画処理
	player->Draw();

	missile->Draw();

	//ゴール描画処理
	goal->Draw();

	//Ui描画処理
	ui->Draw();

}
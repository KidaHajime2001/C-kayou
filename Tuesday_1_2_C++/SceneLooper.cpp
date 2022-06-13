#include "SceneLooper.h"

SceneLooper::SceneLooper()
{
	
}
SceneLooper::~SceneLooper()
{
	
}

bool SceneLooper::Init()
{
	scene = new Title;
	if (!scene)
	{
		OutputDebugString("SceneBaseのメモリ動的確保の失敗");//出力にそう書く
		return false;
	}
	sceneMng = new SceneManeger;
	if (!sceneMng)
	{
		OutputDebugString("SceneManegerのメモリ動的確保の失敗");//出力にそう書く
		return false;
	}
	return true;
}

void SceneLooper::Run()
{

	ChangeWindowMode(true);
	SetGraphMode(640, 480, 16);
	// 描画先画面を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);
	while (!CheckHitKey(KEY_INPUT_ESCAPE)&&!ProcessMessage())
	{
		
		// 画面を初期化する
		ClearDrawScreen();
		scene->Update();

		scene->Draw();

		if (scene->GetNextSceneFlag())//シーン移行の判定
		{
			auto beforeScene = scene;//前シーン削除の仮置き
			
			scene = sceneMng->ScenePasser(scene);//次シーンをマネージャーが渡す
			if (!scene)//nullptrでエラー吐いたら終了
			{
				OutputDebugString("ScenePasserError");//出力にそう書く
				return;
			}
			delete beforeScene;//仮置きしておいたメモリを開放
			WaitTimer(500);
		}
		// 裏画面の内容を表画面に反映させる
		ScreenFlip();
		
	}
}

bool SceneLooper::Terminate()
{
	delete scene;
	delete sceneMng;
	return true;
}

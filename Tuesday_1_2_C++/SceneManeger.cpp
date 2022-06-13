#include "SceneManeger.h"
#include"Title.h"
#include"Game.h"
#include"GameClear.h"
#include"GameOver.h"
SceneBase* SceneManeger::ScenePasser(SceneBase* scenebase)
{
	//タグ名で判別
	if (scenebase->GetSceneTag()==SceneTag::Title)
	{
		//タイトルの次はゲームメイン
		return new Game();
	}
	if (scenebase->GetSceneTag() == SceneTag::GameMain)
	{
		//クリアフラグ立ってたらクリアリザルトへ
		if (scenebase->GetClearFlag())
		{
			return new GameClear();
		}
		//ゲームオーバーフラグ立ってたらゲームオーバーリザルトへ
		if (scenebase->GetGameoverFlag())
		{
			return new GameOver();
		}
	}
	//GameClear(Over)の次はタイトル
	if (scenebase->GetSceneTag()== SceneTag::GameClear
		|| scenebase->GetSceneTag() == SceneTag::GameOver)
	{
		return new Title();
	}

	//タグついてなかったらnullptr(エラー)
	return nullptr;
}


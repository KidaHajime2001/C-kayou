#pragma once
#include"SceneBase.h"
#include"SceneTag.h"
class Title;
class Game;
//現在のシーンを監視して適切な次クラスを渡す、フローの役割
class SceneManeger
{
public:
	/// <summary>
	/// 入力を見て次のシーンを渡す
	/// シーン切り替えのフラグがたったら呼び出される
	/// </summary>
	/// <param name="nowScene">今のシーンを受け取る</param>
	/// <returns> 次のシーンを返す</returns>
	SceneBase* ScenePasser(SceneBase* scenebase);

};


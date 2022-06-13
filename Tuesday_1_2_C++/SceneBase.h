#pragma once
#include"DxLib.h"
#include"SceneTag.h"
//SceneLoopを想定した継承用の基底のクラス
class SceneBase
{
public:
	

	//コンストラクタ
	SceneBase();
	
	//コピーの明示的禁止
	SceneBase(const SceneBase&) = delete;//コピーコンストラクタ
	//コピーの明示的禁止
	SceneBase& operator=(const SceneBase&) = delete;//コピー代入演算子
	
	//デストラクタ
	virtual ~SceneBase();
	
	//描画処理
	virtual void Draw();

	/// <summary>
	/// 毎フレームごとの処理
	/// </summary>
	/// <returns>返り値を監視してシーンの遷移を感知する</returns>
	virtual void Update();

	//次のシーンに映るかを判定するフラグを返す
	bool GetNextSceneFlag() { return nextSceneFlag; };

	bool GetClearFlag() { return clearFlag; };
	bool GetGameoverFlag() { return gameoverFlag; };

	//今度のシーンかをタグで返す
	SceneTag GetSceneTag() { return tag; };

protected:
	//今のシーンを判別するタグ
	SceneTag tag;

	//次のシーンに映るかを判定するフラグ
	bool nextSceneFlag = false;

	//リザルト移行用のフラグ
	bool clearFlag = false;
	bool gameoverFlag = false;
};


#pragma once
#include"SceneManeger.h"
#include"SceneBase.h"
#include"Title.h"
#include"DxLib.h"
class SceneManager;
//SceneLooperが実質的にシーンを回す
//また初期化、実行、終了処理のみ行うためシーンベースにはほぼかかわらない
class SceneLooper
{
public:
	SceneLooper();
	~SceneLooper();
	//
	bool Init();//初期化
	void Run();//実行
	bool Terminate();//終了処理
	SceneBase* scene;//親クラスとしてupdateとdrawを回す、実際の処理は継承した子クラスのものになる
	SceneManeger* sceneMng;
};


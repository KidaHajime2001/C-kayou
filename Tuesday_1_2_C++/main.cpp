#include "DxLib.h"
#include"SceneLooper.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow)
{
	

	// ＤＸライブラリ初期化
	if( DxLib_Init() == -1 )	// ＤＸライブラリ初期化処理
	{
		return -1;				// エラーが起きたら直ちに終了
	}

	SceneLooper* sL = new SceneLooper();
	if (!sL->Init())
	{
		return -1;
	}


	sL->Run();


	if (!sL->Terminate())
	{
		return -1;
	}
	// ＤＸライブラリ使用の終了
	DxLib_End();
	delete sL;
	// ソフトの終了
	return 0;
}
#include "DxLib.h"
#include"SceneLooper.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow)
{
	

	// �c�w���C�u����������
	if( DxLib_Init() == -1 )	// �c�w���C�u��������������
	{
		return -1;				// �G���[���N�����璼���ɏI��
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
	// �c�w���C�u�����g�p�̏I��
	DxLib_End();
	delete sL;
	// �\�t�g�̏I��
	return 0;
}
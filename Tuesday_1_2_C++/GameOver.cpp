#include"GameOver.h"
GameOver::GameOver()
{
	tag = SceneTag::GameOver;
}

GameOver::~GameOver()
{
}

void GameOver::Update()
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		this->nextSceneFlag = true;

	}
}

void GameOver::Draw()
{
	DrawFormatString(100, 100, GetColor(255, 255, 255), "Gameover");
}

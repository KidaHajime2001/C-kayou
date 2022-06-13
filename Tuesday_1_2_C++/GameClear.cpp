#include "GameClear.h"

GameClear::GameClear()
{
	tag = SceneTag::GameClear;

}

GameClear::~GameClear()
{
}

void GameClear::Update()
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		this->nextSceneFlag = true;

	}
}

void GameClear::Draw()
{

	DrawFormatString(100, 100, GetColor(255, 255, 255), "GameClear");
}

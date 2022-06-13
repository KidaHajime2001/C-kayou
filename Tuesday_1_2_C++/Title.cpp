#include "Title.h"

Title::Title()
{
	tag = SceneTag::Title;
}

Title::~Title()
{
}

void Title::Update()
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		this->nextSceneFlag = true;
	}
}

void Title::Draw()
{

	DrawFormatString(100, 100, GetColor(255, 255, 255), "Title");
}

#pragma once
#include "SceneBase.h"
class GameClear : public SceneBase
{
public:
	GameClear();
	~GameClear()override;
	void Update()override;
	void Draw()override;
};


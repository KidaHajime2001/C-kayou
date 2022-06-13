#pragma once
#include"SceneBase.h"
class GameOver:public SceneBase
{
public:
	GameOver();
	~GameOver()override;
	void Update()override;
	void Draw()override;

private:
	 
};


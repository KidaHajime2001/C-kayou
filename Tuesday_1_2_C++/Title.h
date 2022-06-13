#pragma once
#include"SceneBase.h"
class Title:public SceneBase
{
public:
	//コンストラクタ
	Title();
	//デストラクタ
	~Title();
	void Update()override;
	void Draw()override;
};


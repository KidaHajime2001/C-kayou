#pragma once
#include"Actor.h"
class Player:public Actor
{
public:
	Player();
	~Player();
	void Update()override;
	void Draw()override;
	void OnCollisionEnter(Collision* otherCollison)override;
	bool OnColiFlag = false;
};


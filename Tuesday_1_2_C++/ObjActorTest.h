#pragma once
#include"Actor.h"
class ObjActorTest: public Actor
{
public:
	ObjActorTest(int x,int y);
	~ObjActorTest();
	void Update()override;
	void Draw()override;

	void OnCollisionEnter(Collision* otherCollison)override;
};


#pragma once
#include"Collision.h"
class Actor
{
public:
	Actor();
	virtual ~Actor();
	virtual void Update();
	virtual void Draw();
	CollisionTag GetTag() { return tag; };
	virtual void OnCollisionEnter(class Collision* otherCollision);
	class Collision* mCollision;
	CollisionTag tag;
	VECTOR pos;
};


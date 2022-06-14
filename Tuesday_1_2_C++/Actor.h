#pragma once
#include"Collision.h"
class Actor
{
public:
	Actor();
	virtual ~Actor();
	virtual void Update();
	virtual void Draw();
	virtual void OnCollisionEnter(class Collision* otherCollision);

	CollisionTag GetTag() { return tag; };
	VECTOR GetPos() { return  pos; };
	Collision* GetCollision() { return mCollision; };
protected:
	class Collision* mCollision;
	CollisionTag tag;
	VECTOR pos;
};


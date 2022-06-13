#include "ObjActorTest.h"

ObjActorTest::ObjActorTest(int x, int y)
{

	tag = CollisionTag::Enemy;
	pos.x = x;
	pos.y = y;
	mCollision = new Collision(this, 100, 100);

}

ObjActorTest::~ObjActorTest()
{
}

void ObjActorTest::Update()
{
}

void ObjActorTest::Draw()
{
	DrawBox(pos.x, pos.y, pos.x + mCollision->mData.Width, pos.y + mCollision->mData.Height, GetColor(0,255, 0), false);
	
}

void ObjActorTest::OnCollisionEnter(Collision* otherCollison)
{
	DrawFormatString(pos.x, pos.y, GetColor(0, 250, 0), "%d", tag);
}

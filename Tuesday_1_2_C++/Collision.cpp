#include "Collision.h"


Collision::Collision(Actor* parent, int Height, int Width)
	:mParent(parent)
{
	mData.Height = Height;
	mData.Width = Width;
	mData.posX=mParent->pos.x;
	mData.posY= mParent->pos.y;
	mTag = mParent->GetTag();
}

Collision::~Collision()
{
}

bool Collision::Cheak(Collision* otherObj)
{

	CollisionData otherData=otherObj->mData;

	if (
		((otherData.posX>mData.posX&&otherData.posX<mData.posX+mData.Width)||
		(mData.posX>otherData.posX&&mData.posX<otherData.posX+otherData.Width))
		&&
		((otherData.posY > mData.posY && otherData.posY < mData.posY + mData.Height) ||
		(mData.posY > otherData.posY && mData.posY < otherData.posY + otherData.Height))
		)
	{
		return true;
	}


	return false;
}

void Collision::Update()
{
	mData.posX = mParent->pos.x;
	mData.posY = mParent->pos.y;
}

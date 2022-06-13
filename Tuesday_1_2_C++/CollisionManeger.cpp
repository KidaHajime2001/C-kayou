#include "CollisionManeger.h"
CollisionManeger::CollisionManeger()
{
	collidePairs onepair = { CollisionTag::Player,CollisionTag::Enemy };
	pairsVec.push_back(onepair);
}

CollisionManeger::~CollisionManeger()
{
}

void CollisionManeger::AddCollision(Collision* collision)
{
	CollisionTag tag = collision->GetTag();
	mColliders[tag].emplace_back(collision);
}

void CollisionManeger::RemoveCollision(Collision* collision)
{
	CollisionTag tag = collision->GetTag();
	vector<Collision*>::iterator iter=find(mColliders[tag].begin(), mColliders[tag].end(),collision);
	if (iter != mColliders[tag].end())
	{
		mColliders[tag].erase(iter);
		return;
	}

}

void CollisionManeger::CollisionUpdate()
{
	for (auto onePair:pairsVec)
	{
		for (auto obj: mColliders[onePair.pair1])
		{
			for (auto reactionObj : mColliders[onePair.pair2])
			{
 				if (obj->Cheak(reactionObj))
				{
					reactionObj->GetParent()->OnCollisionEnter(obj);
					obj->GetParent()->OnCollisionEnter(reactionObj);
				}
			}
		}

	}
}

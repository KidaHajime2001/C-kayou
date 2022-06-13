#pragma once
#include"DxLib.h"
#include"CollisionTag.h"
#include"Actor.h"
#include<vector>
using namespace std;
//こいつのポインターをメンバーにする
class Collision
{
public:
	
	//縦と横の幅
	struct CollisionData
	{
		int posX;
		int posY;
		int Height;
		int Width;
	};

	Collision(class Actor* parent,int Height,int Width);
	~Collision();
	bool Cheak(class Collision* otherObj);
	void Update();
	CollisionTag GetTag() { return mTag; };
	Actor* GetParent() { return mParent; };
	CollisionTag mTag;
	CollisionData mData;
	Actor* mParent;
};


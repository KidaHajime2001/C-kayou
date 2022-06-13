#pragma once
#include"CollisionTag.h"
#include"Collision.h"
#include<vector>
#include<unordered_map>

using namespace std;
class CollisionManeger
{
public:
	struct collidePairs
	{
		CollisionTag pair1;
		CollisionTag pair2;
	};
	CollisionManeger();
	~CollisionManeger();
	void AddCollision(Collision* collider);
	void RemoveCollision(Collision* collider);
	void CollisionUpdate();
	vector<collidePairs> pairsVec;//�����蔻�肪��������Actor�̃y�A�@�^�O�Œ�`
	unordered_map<CollisionTag, std::vector<class Collision*>> mColliders;
private:

};

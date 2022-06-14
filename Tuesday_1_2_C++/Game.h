#pragma once
#include"SceneBase.h"
#include"Actor.h"
#include"Player.h"
#include"ObjActorTest.h"
#include"CollisionManeger.h"
#include"MapCollider.h"
class Game :public SceneBase
{
public:
	Game();
	~Game();
	void Update()override;
	void Draw()override;

	SceneTag GetSceneTag() { return tag; };
	vector<Actor*> Actors;
	class CollisionManeger* mCM;
	MapCollider* mapC;
};


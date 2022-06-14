#include "Game.h"
Game::Game()
{
	mCM = new CollisionManeger();
	mapC = new MapCollider();

	tag = SceneTag::GameMain;
	clearFlag = false;
	gameoverFlag = false;
	Actors.push_back(new Player());
	Actors.push_back(new ObjActorTest(0,0));
	Actors.push_back(new ObjActorTest(100,0));

	for (auto actor:Actors)
	{
		mCM->AddCollision(actor->GetCollision());
	}

    mapC->ReadFileStageSize("MAP/map.csv");
	mapC->SetStageData("MAP/map.csv");
}

Game::~Game()
{
}

void Game::Update()
{
	for (auto actor : Actors)
	{
		actor->Update();
	}
	mCM->CollisionUpdate();

	if (CheckHitKey(KEY_INPUT_1))
	{
		this->nextSceneFlag = true;
		this->clearFlag = true;

	}
	if (CheckHitKey(KEY_INPUT_2))
	{
		this->nextSceneFlag = true;
		this->gameoverFlag = true;
	}
}

void Game::Draw()
{
	for (auto actor : Actors)
	{
		actor->Draw();
	}
	DrawFormatString(100, 100, GetColor(255, 255, 255), "Game");
}


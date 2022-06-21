#pragma once

//“Š‡
#include "DxLib.h"

//‰æ–Ê
class Scene
{
public:
	
	//‰Šú‰»
	Scene();

	//íœ
	~Scene();

	//XVˆ—
	virtual Scene* Update(float _deltaTime) = 0;

	//•`‰æˆ—
	virtual void Draw() = 0;

protected:

	//‰æ‘œ
	int image;

};
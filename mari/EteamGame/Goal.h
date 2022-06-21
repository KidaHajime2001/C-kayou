#pragma once
class Goal
{
public:
	//‰Šú‰»
	Goal();

	//íœ
	~Goal();

	//ˆÊ’u
	float posX;
	float posY;

	//¡–@
	float sizeX;
	float sizeY;

	//‰æ‘œ
	int image;

	//•`‰æˆ—
	void Draw();
};

//‹¤—L‰»
extern Goal goal;
#include "Player.h"

Player::Player()
{
	mCollision = new Collision(this,100,100);
	pos.x = 0;
	pos.y = 0;
	tag = CollisionTag::Player;
}

Player::~Player()
{
	delete mCollision;
}

void Player::Update()
{
	this->mCollision->Update();
	OnColiFlag = false;
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		pos.x--;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		pos.x++;
	}
	if (CheckHitKey(KEY_INPUT_UP))
	{
		pos.y--;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		pos.y++;
	}
}

void Player::Draw()
{
	DrawBox(pos.x, pos.y, pos.x + mCollision->mData.Width, pos.y + mCollision->mData.Height, GetColor(255,0,0), false);

}


void Player::OnCollisionEnter(Collision* otherCollison)
{
	DrawFormatString(pos.x, pos.y, GetColor(255, 0, 0), "%d", tag);
}

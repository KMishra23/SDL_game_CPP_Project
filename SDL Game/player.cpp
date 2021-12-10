#include "player.h"
#include "Game.h"

Player::Player(const char* textureSheet, int x, int y, int scale) : GameObject(textureSheet, x, y, scale)
{}
void Player::Set(int x, int y)
{
	xpos = x;
	ypos = y;
}
void Player::assignAnimator(PlayerAnimationHandler* Animator)
{
	this->Animator = Animator;
}

void Player::MoveLeft()
{
	xpos -= speedMultiplier;
}

void Player::MoveRight()
{
	xpos += speedMultiplier;
}

void Player::MoveUp()
{
	ypos -= speedMultiplier;
}

void Player::MoveDown()
{
	ypos += speedMultiplier;
}

void Player::Update()
{
	srcRect.h = 16;
	srcRect.w = 16;
	srcRect.y = 0;
	
	/*
	if (SDL_GetTicks() - animationDelayer > 300)
	{
		animationDelayer = SDL_GetTicks();
		srcRect.x = Animator->downAnimationSelect();
	}
	*/
	
	srcRect.x = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 4;
	destRect.h = srcRect.h * 4;
}
int Player::GetPosX()
{
	return xpos;
}
int Player::GetPosY()
{
	return ypos;
}
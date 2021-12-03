#include "player.h"
#include "Game.h"

Player::Player(const char* textureSheet, int x, int y, int scale) : GameObject(textureSheet, x, y, scale)
{}

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

void Player::Sprinting()
{
	speedMultiplier = 24;
}

void Player::Walking()
{
	speedMultiplier = 16;
}

void Player::Update()
{
	srcRect.h = 26;
	srcRect.w = 16;
	srcRect.y = 1;
	
	if (SDL_GetTicks() - animationDelayer > 300)
	{
		animationDelayer = SDL_GetTicks();
		srcRect.x = Animator->downAnimationSelect();
	}
	
	//srcRect.x = 87;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}
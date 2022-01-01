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
	direction = 2;
	if (SDL_GetTicks() - animationDelayer > 300)
	{
		srcRect.h = 16;
		srcRect.w = 16;
		animationDelayer = SDL_GetTicks();
		srcRect.x = Animator->leftAnimationSelect()[animatorCount];
		srcRect.y = Animator->leftAnimationSelect()[animatorCount + 1];
		animatorCount += 2;
		if (animatorCount > 2) {
			animatorCount = 0;
		}
	}
	destRect.y = ypos;
	destRect.x = xpos;
	destRect.w = srcRect.w * 4;
	destRect.h = srcRect.h * 4;
	
}

void Player::MoveRight()
{
	xpos += speedMultiplier;
	direction = 3;
	if (SDL_GetTicks() - animationDelayer > 300)
	{
		srcRect.h = 16;
		srcRect.w = 16;
		animationDelayer = SDL_GetTicks();
		srcRect.x = Animator->rightAnimationSelect()[animatorCount];
		srcRect.y = Animator->rightAnimationSelect()[animatorCount + 1];
		animatorCount += 2;
		if (animatorCount > 2) {
			animatorCount = 0;
		}
	}
	destRect.y = ypos;
	destRect.x = xpos;
	destRect.w = srcRect.w * 4;
	destRect.h = srcRect.h * 4;
}

void Player::MoveUp()
{
	ypos -= speedMultiplier;
	direction = 0;
	if (SDL_GetTicks() - animationDelayer > 300)
	{
		srcRect.h = 16;
		srcRect.w = 16;
		animationDelayer = SDL_GetTicks();
		srcRect.x = Animator->upAnimationSelect()[animatorCount];
		srcRect.y = Animator->upAnimationSelect()[animatorCount + 1];
		animatorCount += 2;
		if (animatorCount > 2) {
			animatorCount = 0;
		}
	}
	destRect.y = ypos;
	destRect.x = xpos;
	destRect.w = srcRect.w * 4;
	destRect.h = srcRect.h * 4;
}

void Player::MoveDown()
{
	ypos += speedMultiplier;
	direction = 1;
	if (SDL_GetTicks() - animationDelayer > 300)
	{
		srcRect.h = 16;
		srcRect.w = 16;
		animationDelayer = SDL_GetTicks();
		srcRect.x = Animator->downAnimationSelect()[animatorCount];
		srcRect.y = Animator->downAnimationSelect()[animatorCount + 1];
		animatorCount += 2;
		if (animatorCount > 2) {
			animatorCount = 0;
		}
	}
	destRect.y = ypos;
	destRect.x = xpos;
	destRect.w = srcRect.w * 4;
	destRect.h = srcRect.h * 4;
}

void Player::AttackUp()
{
	if (SDL_GetTicks() - animationDelayer > 300)
	{
		srcRect.w = 16;
		srcRect.h = 27;
		animationDelayer = SDL_GetTicks();
		srcRect.x = Animator->upAttack()[animatorCount];
		srcRect.y = Animator->upAttack()[animatorCount + 1];
		animatorCount += 2;
		if (animatorCount > 6) {
			animatorCount = 0;
		}
	}
	destRect.y = ypos - 64;
	destRect.x = xpos;
	destRect.w = srcRect.w * 4;
	destRect.h = srcRect.h * 4;
}

void Player::AttackDown()
{
	if (SDL_GetTicks() - animationDelayer > 300)
	{
		srcRect.w = 16;
		srcRect.h = 27;
		animationDelayer = SDL_GetTicks();
		srcRect.x = Animator->downAttack()[animatorCount];
		srcRect.y = Animator->downAttack()[animatorCount + 1];
		animatorCount += 2;
		if (animatorCount > 6) {
			animatorCount = 0;
		}
	}
	destRect.y = ypos;
	destRect.x = xpos;
	destRect.w = srcRect.w * 4;
	destRect.h = srcRect.h * 4;
}

void Player::AttackLeft()
{

}

void Player::AttackRight()
{

}

void Player::Update()
{
	//srcRect.y = 0;
	
	/*
	if (SDL_GetTicks() - animationDelayer > 300)
	{
		animationDelayer = SDL_GetTicks();
		srcRect.x = Animator->downAnimationSelect();
	}
	*/
	
	//srcRect.x = 0;

	//player_health->Update_Meter();

}
int Player::GetPosX()
{
	return xpos;
}
int Player::GetPosY()
{
	return ypos;
}
int Player::getDirection()
{
	return direction;
}
/*
void Player::renderHearts()
{
	player_health->Render();
}

void Player::Damage_1()
{
	player_health->Decrease_1();
}

void Player::Regenerate_1()
{
	player_health->Increase_1();
}
*/

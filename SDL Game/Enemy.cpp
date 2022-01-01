#include "Enemy.h"
#include "Game.h"

Enemy::Enemy(const char* textureSheet, int x, int y, int scale, int direction) : GameObject(textureSheet, x, y, scale)
{
	//this->mapNumber = mapNum;
	this->direction = direction; //1=moving down, -1=moving up
}

void Enemy::SetPos(int x, int y, int direction)
{
	xpos = x;
	ypos = y;
	this->direction = direction;
}

void Enemy::Update()
{

	//srcRect.x = 69;
	//srcRect.y = 58;
	srcRect.h = 16;
	srcRect.w = 16;
	destRect.w = srcRect.w * 4;
	destRect.h = srcRect.h * 4;
	
	if (direction == 1) {
		ypos+=speedMultiplier;
		if (SDL_GetTicks() - animationDelayer > 300)
		{
			srcRect.h = 16;
			srcRect.w = 16;
			animationDelayer = SDL_GetTicks();
			srcRect.x = mvDown[animatorCount];
			srcRect.y = mvDown[animatorCount + 1];
			animatorCount += 2;
			if (animatorCount > 2) {
				animatorCount = 0;
			}
		}

	}
	else if (direction == -1) {
		ypos-=speedMultiplier;
		if (SDL_GetTicks() - animationDelayer > 300)
		{
			srcRect.h = 16;
			srcRect.w = 16;
			animationDelayer = SDL_GetTicks();
			srcRect.x = mvUp[animatorCount];
			srcRect.y = mvUp[animatorCount + 1];
			animatorCount += 2;
			if (animatorCount > 2) {
				animatorCount = 0;
			}
		}
	}
	else if (direction == 2) {
		xpos+=speedMultiplier;
		if (SDL_GetTicks() - animationDelayer > 300)
		{
			srcRect.h = 16;
			srcRect.w = 16;
			animationDelayer = SDL_GetTicks();
			srcRect.x = mvRight[animatorCount];
			srcRect.y = mvRight[animatorCount + 1];
			animatorCount += 2;
			if (animatorCount > 2) {
				animatorCount = 0;
			}
		}
	}
	else {
		xpos-=speedMultiplier;
		if (SDL_GetTicks() - animationDelayer > 300)
		{
			srcRect.h = 16;
			srcRect.w = 16;
			animationDelayer = SDL_GetTicks();
			srcRect.x = mvLeft[animatorCount];
			srcRect.y = mvLeft[animatorCount + 1];
			animatorCount += 2;
			if (animatorCount > 2) {
				animatorCount = 0;
			}
		}
	}

	if ((ypos > 576-64 || ypos < 128) && (direction == 1 || direction == -1)) {
		direction = -direction;
	}

	if ((xpos > 1024-256 || xpos < 128+64) && (direction == 2 || direction == -2)) {
		direction = -direction;
	}


	destRect.x = xpos;
	destRect.y = ypos;
}
int Enemy::GetPosX()
{
	return xpos;
}
int Enemy::GetPosY()
{
	return ypos;
}


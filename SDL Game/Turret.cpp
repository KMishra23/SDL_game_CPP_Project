#include "Turret.h"
#include "Game.h"

Turret::Turret(const char* textureSheet, int x, int y, int scale, int direction) : GameObject(textureSheet, x, y, scale)
{
	//this->mapNumber = mapNum;
	this->direction = direction; //1=moving down, -1=moving up
}

void Turret::SetPos(int x, int y, int direction)
{
	xpos = x;
	ypos = y;
	this->direction = direction;
}

void Turret::Update()
{

	//srcRect.x = 69;
	//srcRect.y = 58;
	srcRect.h = 16;
	srcRect.w = 16;
	destRect.w = srcRect.w * 4;
	destRect.h = srcRect.h * 4;

	if (direction == 1) {
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
	destRect.x = xpos;
	destRect.y = ypos;
}
int Turret::GetPosX()
{
	return xpos;
}
int Turret::GetPosY()
{
	return ypos;
}

int Turret::getDirection()
{
	return direction;
}


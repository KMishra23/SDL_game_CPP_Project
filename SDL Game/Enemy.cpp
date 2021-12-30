#include "Enemy.h"
#include "Game.h"

Enemy::Enemy(const char* textureSheet, int x, int y, int scale) : GameObject(textureSheet, x, y, scale)
{
	this->mapNumber = mapNum;
	direction = 1; //1=moving down, -1=moving up
}

void Enemy::Update()
{
	srcRect.x = 0; 
	srcRect.y = 0;
	srcRect.h = 128;
	srcRect.w = 128;
	destRect.w = srcRect.w * 0.45;
	destRect.h = srcRect.h * 0.45;
	if (direction == 1)
		ypos++;
	else
		ypos--;
	destRect.x = xpos;
	destRect.y = ypos;
	/*
	if (IsCollidingWithWalls(direction,)){
		direction=direction*(-1);
	}
	*/
}
int Enemy::GetPosX()
{
	return xpos;
}
int Enemy::GetPosY()
{
	return ypos;
}


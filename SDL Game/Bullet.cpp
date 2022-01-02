#include "Bullet.h"
#include "Game.h"

Bullet::Bullet(const char* textureSheet, int x, int y, int scale, int direction, Enemy* enemy) : GameObject(textureSheet, x, y, scale)
{
	this->direction = direction;
}

void Bullet::Update()
{
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = 64;
	srcRect.w = 64;
	destRect.w = srcRect.w * 4;
	destRect.h = srcRect.h * 4;

	if (direction == 1) {
		ypos += speedMultiplier;
	}
	else if (direction == -1) {
		ypos -= speedMultiplier;
	}
	else if (direction == 2) {
		xpos += speedMultiplier;
	}
	else if (direction == -2) {
		xpos -= speedMultiplier;
	}

	destRect.x = xpos;
	destRect.y = ypos;
	
}
int Bullet::GetPosX()
{
	return xpos;
}
int Bullet::GetPosY()
{
	return ypos;
}


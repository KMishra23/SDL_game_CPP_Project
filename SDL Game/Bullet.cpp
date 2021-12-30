#include "Bullet.h"
#include "Game.h"

Bullet::Bullet(const char* textureSheet, int x, int y, int scale) : GameObject(textureSheet, x, y, scale)
{}

void Bullet::Update()
{
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = 64;
	srcRect.w = 64;
	destRect.w = srcRect.w * 0.40;
	destRect.h = srcRect.h * 0.60;
	
	xpos--;
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


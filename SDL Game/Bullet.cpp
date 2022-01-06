#include "Bullet.h"
#include "Game.h"

Bullet::Bullet(const char* textureSheet, int x, int y, int scale, int direction) : GameObject(textureSheet, x, y, scale)
{
	this->direction = direction;
}

void Bullet::addTurret(Turret* turret) {
	direction = turret->getDirection();
	if (direction == 1) {
		xpos = turret->GetPosX() + 16;
		ypos = turret->GetPosY() + 64;
		initposx = xpos;
		initposy = ypos;
	}
	else if (direction == -1) {
		xpos = turret->GetPosX() + 16;
		ypos = turret->GetPosY() - 64;
		initposx = xpos;
		initposy = ypos;
	}
	else if (direction == 2) {
		xpos = turret->GetPosX() + 64;
		ypos = turret->GetPosY();
		initposx = xpos;
		initposy = ypos;
	}
	else {
		xpos = turret->GetPosX() - 64;
		ypos = turret->GetPosY() + 16;
		initposx = xpos;
		initposy = ypos;
	}
}

void Bullet::Update()
{
	srcRect.x = 69;
	srcRect.y = 11;
	srcRect.h = 15;
	srcRect.w = 7;
	destRect.w = srcRect.w * 4;
	destRect.h = srcRect.h * 4;
	width = destRect.w;
	height = destRect.h;

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
	if (xpos > 1024 - 192 || ypos > 576 - 64 || xpos < 128 || ypos < 128) {
		xpos = initposx;
		ypos = initposy;
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


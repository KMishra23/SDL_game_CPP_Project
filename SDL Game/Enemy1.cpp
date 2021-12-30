#include "Enemy1.h"
#include "Game.h"

Enemy1 :: Enemy1(const char* textureSheet, int x, int y, int scale, int mapNum) : GameObject(textureSheet, x, y, scale)
{
	this->mapNumber = mapNum;
}
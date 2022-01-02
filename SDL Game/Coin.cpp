#include "Coin.h"

Coin::Coin(const char* textureSheet, int x, int y, int scale) : GameObject(textureSheet, x, y, scale)
{}


bool Coin::CollectionQuery()
{
	return true;
}
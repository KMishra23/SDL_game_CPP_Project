#pragma once

#ifndef Coin_HEADER
#define Coin_HEADER

#include "Game.h"
#include "GameObject.h"

class Coin : public GameObject
{
private:


public:
	Coin(const char* textureSheet, int x, int y, int scale);
	~Coin();
	
	bool CollectionQuery();
};

#endif

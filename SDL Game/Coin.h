#pragma once

#ifndef Coin_HEADER
#define Coin_HEADER

#include "Game.h"
#include "GameObject.h"

class Coin : public GameObject
{
private:


public:
	Coin();
	~Coin();
	
	bool CollectionQuery();
	
};

#endif

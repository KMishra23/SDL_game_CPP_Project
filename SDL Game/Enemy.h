#pragma once
#ifndef enemy_HEADER
#define enemy_HEADER
#include "GameObject.h"
#include"Map.h"
#include "PlayerAnimationHandler.h"
#include"Game.h"
class Enemy : public GameObject
{
public:
	Enemy(const char* textureSheet, int x, int y, int scale);
	~Enemy();

	void Update();
	int GetPosX();
	int GetPosY();
	//bool IsCollidingWithWalls(int direction, Map* mymap, int CurrMapNumber);
private:
	int direction;
	int mapNumber;
};

#endif

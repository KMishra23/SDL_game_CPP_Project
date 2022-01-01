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
	Enemy(const char* textureSheet, int x, int y, int scale, int direction);
	~Enemy();

	void SetPos(int x, int y, int direction);
	void Update();
	int GetPosX();
	int GetPosY();
	//bool IsCollidingWithWalls(int direction, Map* mymap, int CurrMapNumber);
private:
	int direction;
	int mapNumber;
	Uint32 animationDelayer = SDL_GetTicks();
	int animatorCount = 0;
	int speedMultiplier = 1;
	int mvDown[4] = { 69, 58, 90, 58 };
	int mvUp[4] = { 107, 58, 52, 58 };
	int mvRight[4] = { 124, 58, 141, 58 };
	int mvLeft[4] = { 18, 58, 35, 58 };
};

#endif

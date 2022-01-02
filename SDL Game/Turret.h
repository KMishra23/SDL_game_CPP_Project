#pragma once
#ifndef turret_HEADER
#define turret_HEADER
#include "GameObject.h"
#include"Map.h"
#include "PlayerAnimationHandler.h"
#include"Game.h"
class Turret : public GameObject
{
public:
	Turret(const char* textureSheet, int x, int y, int scale, int direction);
	~Turret();

	void SetPos(int x, int y, int direction);
	void Update();
	int GetPosX();
	int GetPosY();
	int getDirection();
	//bool IsCollidingWithWalls(int direction, Map* mymap, int CurrMapNumber);
private:
	int direction;
	int mapNumber;
	Uint32 animationDelayer = SDL_GetTicks();
	int animatorCount = 0;
	int speedMultiplier = 1;
	int mvDown[4] = {1, 11, 18, 11};
	int mvUp[4] = {113, 11, 130, 11};
	int mvRight[4] = {79, 11, 96, 11};
	int mvLeft[4] = {35, 11, 52, 11};
};

#endif

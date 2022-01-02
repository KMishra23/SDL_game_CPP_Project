#pragma once
#ifndef bullet_HEADER
#define bullet_HEADER
#include "GameObject.h"
#include"Map.h"
#include "PlayerAnimationHandler.h"
#include"Game.h"
#include "Enemy.h"
class Bullet : public GameObject
{
public:
	Bullet(const char* textureSheet, int x, int y, int scale, int direction, Enemy* enemy);
	~Bullet();

	void SetPos(int x, int y, int direction);
	void Update();
	int GetPosX();
	int GetPosY();
	
private:
	int direction;
	int mapNumber;
	Uint32 animationDelayer = SDL_GetTicks();
	int animatorCount = 0;
	int speedMultiplier = 3;
	int mvDown[4] = { 69, 58, 90, 58 };
	int mvUp[4] = { 107, 58, 52, 58 };
	int mvRight[4] = { 124, 58, 141, 58 };
	int mvLeft[4] = { 18, 58, 35, 58 };
};

#endif

#pragma once
#ifndef bullet_HEADER
#define bullet_HEADER
#include "GameObject.h"
#include"Map.h"
#include "PlayerAnimationHandler.h"
#include"Game.h"
#include "Turret.h"
class Bullet : public GameObject
{
public:
	Bullet(const char* textureSheet, int x, int y, int scale, int direction);
	~Bullet();

	void Update();
	int GetPosX();
	int GetPosY();
	void addTurret(Turret* turret);
	
private:
	int direction;
	int mapNumber;
	Uint32 animationDelayer = SDL_GetTicks();
	int animatorCount = 0;
	int speedMultiplier = 3;
	int initposx;
	int initposy;
};

#endif

#pragma once
#ifndef bullet_HEADER
#define bullet_HEADER
#include "GameObject.h"
#include"Map.h"
#include "PlayerAnimationHandler.h"
#include"Game.h"
class Bullet : public GameObject
{
public:
	Bullet(const char* textureSheet, int x, int y, int scale);
	~Bullet();

	void Update();
	int GetPosX();
	int GetPosY();
	
private:
	
};

#endif

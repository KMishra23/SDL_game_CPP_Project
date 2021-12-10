#pragma once
#ifndef player_HEADER
#define player_HEADER
#include "GameObject.h"
#include"Map.h"
#include "PlayerAnimationHandler.h"
#include"Game.h"
class Player : public GameObject
{
public:
	Player(const char* textureSheet, int x, int y, int scale);
	~Player();

	void assignAnimator(PlayerAnimationHandler* Animator);
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void Update();
	int GetPosX();
	int GetPosY();
	bool IsCollidingWithWalls(int direction, Map* mymap,int CurrMapNumber);
	int IsChangingMap(int direction, Map* mymap, int CurrMapNumber);
	void Set(int x, int y);

private:
	int speedMultiplier = 2;
	bool movingDown = false;
	PlayerAnimationHandler* Animator;
	Uint32 animationDelayer = SDL_GetTicks();
};

#endif
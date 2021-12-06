#pragma once
#ifndef player_HEADER
#define player_HEADER
#include "GameObject.h"
#include "PlayerAnimationHandler.h"

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

private:
	int speedMultiplier = 32;
	bool movingDown = false;
	PlayerAnimationHandler* Animator;
	Uint32 animationDelayer = SDL_GetTicks();
};

#endif
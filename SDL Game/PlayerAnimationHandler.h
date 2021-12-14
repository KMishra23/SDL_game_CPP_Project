#pragma once
#ifndef PlayerAnimationHandler_HEADER
#define PlayerAnimationHandler_HEADER

#include "Game.h"

class PlayerAnimationHandler
{
public:
	PlayerAnimationHandler(const char* textureSheet);
	~PlayerAnimationHandler();

	void resetAnimations();
	int* downAnimationSelect();
	int* upAnimationSelect();
	int* rightAnimationSelect();
	int* leftAnimationSelect();
	
	int downAttack();
	int upAttack();
	int rightAttack();
	int leftAttack();

private:
	SDL_Texture* baseTexture = NULL;
	int mvDown[4] = { 0, 0, 17, 0 };
	int mvUp[4] = { 68, 0, 85, 0 };
	int mvRight[4] = { 34, 0, 51, 0 };
	int mvLeft[4] = { 107, 0, 124, 0 };

	int atkDown[4] = {};
	int atkUp[4] = {};
	int atkRight[4] = {};
	int atkLeft[4] = {};
};

#endif
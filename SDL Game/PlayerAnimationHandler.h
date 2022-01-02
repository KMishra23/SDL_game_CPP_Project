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
	
	int* downAttack();
	int* upAttack();
	int* rightAttack();
	int* leftAttack();
	int* Attackwidth();

private:
	SDL_Texture* baseTexture = NULL;
	int mvDown[4] = { 0, 0, 17, 0 };
	int mvUp[4] = { 68, 0, 85, 0 };
	int mvRight[4] = { 34, 0, 51, 0 };
	int mvLeft[4] = { 107, 0, 124, 0 };

	int atkDown[8] = {0, 16, 17, 16, 35, 16, 52, 16};
	int atkUp[8] = { 0, 59, 17, 59, 35, 59, 52, 59 };
	int atkRight[8] = {0, 44, 17, 44, 45, 44, 69, 43};
	int atkLeft[8] = {164, 44, 135, 44, 111, 44, 92, 43};
	int width[8] = {16, 0, 26, 0, 22, 0, 17, 0};
};

#endif
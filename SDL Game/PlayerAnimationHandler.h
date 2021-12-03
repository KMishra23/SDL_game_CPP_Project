#pragma once
#ifndef PlayerAnimationHandler_HEADER
#define PlayerAnimationHandler_HEADER

#include "Game.h"

class PlayerAnimationHandler
{
public:
	PlayerAnimationHandler();
	~PlayerAnimationHandler();

	void resetAnimations();
	int downAnimationSelect();

private:
	SDL_Texture* baseTexture = NULL;
	int mvDownX[6] = { 2, 19, 36, 53, 70, 87 };
	int downIterator = 1;

};

#endif
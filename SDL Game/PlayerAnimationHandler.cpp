#include "PlayerAnimationHandler.h"
#include "player.h"
#include "Game.h"

PlayerAnimationHandler::PlayerAnimationHandler() {}
PlayerAnimationHandler::~PlayerAnimationHandler() {}

void PlayerAnimationHandler::resetAnimations()
{
	downIterator = 1;
}

int PlayerAnimationHandler::downAnimationSelect()
{
	//cout << downIterator + 1 << endl;
	return mvDownX[downIterator++ % 6];
}
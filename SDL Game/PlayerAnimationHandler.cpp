#include "PlayerAnimationHandler.h"
#include "player.h"
#include "Game.h"

PlayerAnimationHandler::PlayerAnimationHandler() {}
PlayerAnimationHandler::~PlayerAnimationHandler() {}

void PlayerAnimationHandler::resetAnimations()
{
	return;
}

int PlayerAnimationHandler::downAnimationSelect()
{
	//cout << downIterator + 1 << endl;
	return mvDown[0];
}
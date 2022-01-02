#include "PlayerAnimationHandler.h"
#include "player.h"
#include "Game.h"
#include "TextureManager.h"

PlayerAnimationHandler::PlayerAnimationHandler(const char* textureSheet) {
	baseTexture = TextureManager::LoadTexture(textureSheet);
	if (baseTexture == NULL)
	{
		cout << "Player texture not loaded" << endl;
	}
}
PlayerAnimationHandler::~PlayerAnimationHandler() {}

void PlayerAnimationHandler::resetAnimations()
{
	return;
}

int* PlayerAnimationHandler::downAnimationSelect()
{
	//cout << downIterator + 1 << endl;
	return mvDown;
}

int* PlayerAnimationHandler::upAnimationSelect()
{
	//cout << downIterator + 1 << endl;
	return mvUp;
}

int* PlayerAnimationHandler::leftAnimationSelect()
{
	//cout << downIterator + 1 << endl;
	return mvLeft;
}

int* PlayerAnimationHandler::rightAnimationSelect()
{
	//cout << downIterator + 1 << endl;
	return mvRight;
}

int* PlayerAnimationHandler::upAttack()
{
	return atkUp;
}

int* PlayerAnimationHandler::downAttack()
{
	return atkDown;
}
int* PlayerAnimationHandler::leftAttack()
{
	return atkLeft;
}
int* PlayerAnimationHandler::rightAttack()
{
	return atkRight;
}

int* PlayerAnimationHandler::Attackwidth() {
	return width;
}
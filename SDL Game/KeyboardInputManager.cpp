#include "KeyboardInputManager.h"
#include "Game.h"

KeyboardManager::KeyboardManager()
{}
KeyboardManager::~KeyboardManager()
{}

void KeyboardManager::KeyInputEvent(Player* player, const Uint8* keystates,Map* mymap)
{
	if ((keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W]) && SDL_GetTicks() - delayUp > delayUnit)
	{
		delayUp = SDL_GetTicks();
		if (!IscollidingWithWalls(0,player->GetPosX(),player->GetPosY(),mymap))
		{
			player->MoveUp();
		}
	}
	if ((keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S]) && SDL_GetTicks() - delayDown > delayUnit)
	{
		delayDown = SDL_GetTicks();
		if(!IscollidingWithWalls(2, player->GetPosX(), player->GetPosY(),mymap))
		player->MoveDown();
	}
	if ((keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D]) && SDL_GetTicks() - delayRight > delayUnit)
	{
		delayRight = SDL_GetTicks();
		if (!IscollidingWithWalls(1, player->GetPosX(), player->GetPosY(), mymap))
		player->MoveRight();
	}
	if ((keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A]) && SDL_GetTicks() - delayLeft > delayUnit)
	{
		delayLeft = SDL_GetTicks();
		if (!IscollidingWithWalls(3, player->GetPosX(), player->GetPosY(),mymap))
		player->MoveLeft();
	}
	/*
	if (keystates[SDL_SCANCODE_LSHIFT])
	{
		delayUnit = 10;
	}
	else if (!keystates[SDL_SCANCODE_LSHIFT])
	{
		delayUnit = 20;
	}
	*/
}
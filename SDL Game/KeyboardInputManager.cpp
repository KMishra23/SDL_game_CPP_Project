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
		if (!player->IsCollidingWithWalls(0,mymap))
		player->MoveUp();
	}
	if ((keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S]) && SDL_GetTicks() - delayDown > delayUnit)
	{
		delayDown = SDL_GetTicks();
		if(!player->IsCollidingWithWalls(2,mymap))
		player->MoveDown();
	}
	if ((keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D]) && SDL_GetTicks() - delayRight > delayUnit)
	{
		delayRight = SDL_GetTicks();
		if (!player->IsCollidingWithWalls(1, mymap))
		player->MoveRight();
	}
	if ((keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A]) && SDL_GetTicks() - delayLeft > delayUnit)
	{
		delayLeft = SDL_GetTicks();
		if (!player->IsCollidingWithWalls(3,mymap))
		player->MoveLeft();
	}
}
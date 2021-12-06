#pragma once
#ifndef keymanager_HEADER 
#define keymanager_HEADER

#include "player.h"
#include"Map.h"
class KeyboardManager
{
public:
	KeyboardManager();
	~KeyboardManager();

	void KeyInputEvent(Player* player, const Uint8 *keystates,Map* mymap);
	bool IscollidingWithWalls(int direction, int x, int y, Map* mymap);

private:
	SDL_Event event;
	Uint32 delayUp = SDL_GetTicks();
	Uint32 delayDown = SDL_GetTicks();
	Uint32 delayRight = SDL_GetTicks();
	Uint32 delayLeft = SDL_GetTicks();
	Uint32 delayUnit = 50;
};

#endif
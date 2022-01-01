#pragma once
#ifndef keymanager_HEADER 
#define keymanager_HEADER

#include "player.h"
#include"Map.h"
#include "Enemy.h"
class KeyboardManager
{
public:
	KeyboardManager();
	~KeyboardManager();

	int KeyInputEvent(Player* player, Enemy* enemy, const Uint8 *keystates,Map* mymap,int CurrentMapNumber);
	//bool IscollidingWithWalls(int direction, int x, int y, Map* mymap);
private:
	SDL_Event event;
	Uint32 delayUp = SDL_GetTicks();
	Uint32 delayDown = SDL_GetTicks();
	Uint32 delayRight = SDL_GetTicks();
	Uint32 delayLeft = SDL_GetTicks();
	int delayUnit = 1;
};

#endif
#pragma once
#ifndef Map_HEADER
#define Map_HEADER

#include "Game.h"

class Map
{
public:
	Map();
	~Map();

	void LoadMap(int arr[11][16]);
	void DrawMap();
	bool CollisionQuery(int x, int y);
	
private:
	SDL_Rect src, dest;

	SDL_Texture* Map_1 = NULL;

	int map[11][16];

};

#endif 



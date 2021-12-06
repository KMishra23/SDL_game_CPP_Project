#pragma once
#ifndef Map_HEADER
#define Map_HEADER

#include "Game.h"

class Map
{
public:
	Map();
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap();
	bool CollisionQuery(int x, int y);
	
private:
	SDL_Rect src, dest;

	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][25];

};

#endif 



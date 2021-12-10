#pragma once
#ifndef Map_HEADER
#define Map_HEADER

#include "Game.h"

class Map
{
public:
	Map(int num);
	~Map();

	void LoadMap(int num);
	void DrawMap(int num);
	int CollisionQuery(int x, int y,int CurrMapNumber);
	
private:
	SDL_Rect src, dest;

	SDL_Texture* Map_1 = NULL;
	SDL_Texture* Map_2 = NULL;
	SDL_Texture* Map_3 = NULL;

	int map[11][16];
	int maps[2][4] = { {2,2,2,2},
					   {1,1,1,1} 
					 };
	int count = 0;

};

#endif 



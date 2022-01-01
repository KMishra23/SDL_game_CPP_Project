#pragma once

#ifndef Health_HEADER
#define Health_HEADER

#include "Game.h"
#include <vector>

class Health
{
public:
	Health(int init_val);
	~Health();

	void Decrease_1();
	void Increase_1();

	int health_query();
	void Update_Meter();
	void Render();

private:
	int health_points = 0;
	int max_health = 0;
	vector<int> hearts;

	SDL_Texture* hearts_sheet;
	SDL_Rect full_heart_src, half_heart_src, empty_heart_src;
	SDL_Rect destRect;

	int xpos = 32;
	int xReset = 32;
	int ypos = 736;
};

#endif
#pragma once

#ifndef Game_HEADER
#define Game_HEADER

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include<math.h>
using namespace std;

class Game
{
public:
	Game();
	~Game();

	void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void HandleEvents();
	void Update();
	void Render();
	void Clean();
	void KeyInManager();
	 int getCurrMapNumber()
	{
		return map_number;
	}
	static SDL_Renderer* renderer;
	bool Running()
	{
		return isRunning;
	}
	//bool IsCollidingWithEnemy(Player *player,);
private:
	int count = 0;
	int map_number=1;
	int prev=1;
	bool isRunning;
	SDL_Window* window;
	SDL_Event event;
	const Uint8* keystates;

};

#endif


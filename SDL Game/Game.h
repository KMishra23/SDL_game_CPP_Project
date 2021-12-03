#pragma once

#ifndef Game_HEADER
#define Game_HEADER

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

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

	static SDL_Renderer* renderer;

	bool Running()
	{
		return isRunning;
	}

private:
	int count = 0;
	bool isRunning;
	SDL_Window* window;
	SDL_Event event;
	const Uint8* keystates;

};

#endif


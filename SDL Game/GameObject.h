#pragma once

#ifndef GameObject_HEADER
#define GameObject_HEADER

#include "Game.h"

class GameObject
{

public:
	GameObject(const char* textureSheet, int x, int y, int scale);
	~GameObject();

	void Update();
	void Render();

protected:
	int xpos = 0;
	int ypos = 0;
	int objectSizeScale = 4;

	SDL_Texture* objectTexture= NULL;
	SDL_Rect srcRect, destRect;
	
	//SDL_Renderer* renderer;
};

#endif
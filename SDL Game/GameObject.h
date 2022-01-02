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
	int xPosQuery();
	int yPosQuery();

protected:
	int xpos = 80;
	int ypos = 80;
	int objectSizeScale = 1;

	SDL_Texture* objectTexture= NULL;
	SDL_Rect srcRect, destRect;

};

#endif
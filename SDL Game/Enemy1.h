#pragma once
#ifndef Enemy1_HEADER
#define Enemy1_HEADER

#include "GameObject.h"

class Enemy1 : public GameObject
{
public:
	Enemy1(const char* textureSheet, int x, int y, int scale);
	~Enemy1();

private:
	
};

#endif // !Enemy1_HEADER


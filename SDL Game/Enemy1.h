#pragma once
#ifndef Enemy1_HEADER
#define Enemy1_HEADER

#include "GameObject.h"

class Enemy1 : public GameObject
{
public:
	Enemy1(const char* textureSheet, int x, int y, int scale, int mapNum)
		;
	~Enemy1();
	int GetPosX() { return xpos; }
	int GetPosY() { return ypos; }
	int GetDirection() { return direction; }

	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();

private:
	int direction = 0;
	int spawnX;
	int spawnY;
	int mapNumber;
};

#endif // !Enemy1_HEADER


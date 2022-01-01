#pragma once
#ifndef player_HEADER
#define player_HEADER
#include "GameObject.h"
#include"Map.h"
#include "PlayerAnimationHandler.h"
#include"Game.h"
//#include "Health.h"

class Player : public GameObject
{
public:
	Player(const char* textureSheet, int x, int y, int scale);
	~Player();

	void assignAnimator(PlayerAnimationHandler* Animator);
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void AttackUp();
	void AttackDown();
	void AttackLeft();
	void AttackRight();
	void Update();
	int GetPosX();
	int GetPosY();
	int getDirection();
	bool IsCollidingWithWalls(int direction, Map* mymap,int CurrMapNumber);
	int IsChangingMap(int direction, Map* mymap, int CurrMapNumber);
	void Set(int x, int y);
	void renderHearts();
	void Damage_1();
	void Regenerate_1();

private:
	int speedMultiplier = 2;
	int max_health = 5;
	int animatorCount = 0;
	int direction = 0;
	bool movingDown = false;
	PlayerAnimationHandler* Animator;
	bool attackupflag = false;
	Uint32 animationDelayer = SDL_GetTicks();
	//Health *player_health = new Health(max_health);
};

#endif
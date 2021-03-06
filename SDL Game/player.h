#pragma once
#ifndef player_HEADER
#define player_HEADER
#include "GameObject.h"
#include"Map.h"
#include "PlayerAnimationHandler.h"
#include"Game.h"
#include "Health.h"
#include "Scoreboard.h"
#include "Bullet.h"
#include "Enemy.h"

class Player : public GameObject
{
public:
	Player(const char* textureSheet, int x, int y, int scale);
	~Player();

	void initHealth();
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
	bool IsCollidingWithBullet(int BulletX, int BulletY);
	bool IsCollidingWithEnemy(int EnemyX,int EnemyY);
	bool IsCollidingWithWalls(int direction, Map* mymap,int CurrMapNumber);
	bool IsCollectingCoin(int CoinX, int CoinY);
	bool BulletCollisionCheck(Bullet* bullet);
	bool EnemyCollisionCheck(Enemy* enemy);
	int IsChangingMap(int direction, Map* mymap, int CurrMapNumber);
	void Set(int x, int y);
	void renderHearts();
	void Damage_1();
	void Regenerate_1();
	int healthQuery();

private:
	int speedMultiplier = 2;
	int max_health = 5;
	int animatorCount = 0;
	int direction = 0;
	bool movingDown = false;
	PlayerAnimationHandler* Animator;
	Uint32 animationDelayer = SDL_GetTicks();
	Health* player_health;
};

#endif
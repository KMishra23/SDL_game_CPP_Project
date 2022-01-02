#include "KeyboardInputManager.h"
#include "Game.h"
#include "Enemy.h"

KeyboardManager::KeyboardManager()
{}
KeyboardManager::~KeyboardManager()
{}

int KeyboardManager::KeyInputEvent(Player* player, Enemy* enemy, const Uint8* keystates,Map* mymap,int CurrentMapNumber)
{
	if ((keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W]) && SDL_GetTicks() - delayUp > delayUnit)
	{
		delayUp = SDL_GetTicks();
		
		if (!player->IsCollidingWithWalls(0,mymap,CurrentMapNumber) && !player->IsCollidingWithEnemy(enemy->GetPosX(), enemy->GetPosY()))
		player->MoveUp();
		return player->IsChangingMap(0, mymap,CurrentMapNumber);
	}
	if ((keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S]) && SDL_GetTicks() - delayDown > delayUnit)
	{
		delayDown = SDL_GetTicks();
		if(!player->IsCollidingWithWalls(2,mymap,CurrentMapNumber)  && !player->IsCollidingWithEnemy(enemy->GetPosX(), enemy->GetPosY()))
		player->MoveDown();
		return player->IsChangingMap(2, mymap,CurrentMapNumber);
	}
	if ((keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D]) && SDL_GetTicks() - delayRight > delayUnit)
	{
		delayRight = SDL_GetTicks();
		if (!player->IsCollidingWithWalls(1, mymap,CurrentMapNumber) && !player->IsCollidingWithEnemy(enemy->GetPosX(), enemy->GetPosY()))
		player->MoveRight();
		return player->IsChangingMap(1, mymap,CurrentMapNumber);
	}
	if ((keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A]) && SDL_GetTicks() - delayLeft > delayUnit)
	{
		delayLeft = SDL_GetTicks();
		if (!player->IsCollidingWithWalls(3,mymap,CurrentMapNumber) && !player->IsCollidingWithEnemy(enemy->GetPosX(), enemy->GetPosY()))
		player->MoveLeft();
		return player->IsChangingMap(3, mymap,CurrentMapNumber);
	}
	if ((keystates[SDL_SCANCODE_SPACE]) && player->getDirection() == 0 && SDL_GetTicks()) {
		//delayLeft = SDL_GetTicks();

		if (!player->IsCollidingWithWalls(0, mymap, CurrentMapNumber)) {
			player->AttackUp();
			if (player->IsCollidingWithEnemy(enemy->GetPosX(), enemy->GetPosY())) {
				enemy->SetPos(1024, 1024, 1);
			}
		}
	}
	if ((keystates[SDL_SCANCODE_SPACE]) && player->getDirection() == 1 && SDL_GetTicks()) {
		//delayLeft = SDL_GetTicks();
		if (!player->IsCollidingWithWalls(2, mymap, CurrentMapNumber)) {
			player->AttackDown();
			if (player->IsCollidingWithEnemy(enemy->GetPosX(), enemy->GetPosY())) {
				enemy->SetPos(1024, 1024, 1);
			}
		}
	}
	if ((keystates[SDL_SCANCODE_SPACE]) && player->getDirection() == 2 && SDL_GetTicks()) {
		//delayLeft = SDL_GetTicks();
		if (!player->IsCollidingWithWalls(1, mymap, CurrentMapNumber)) {
			player->AttackLeft();
			if (player->IsCollidingWithEnemy(enemy->GetPosX(), enemy->GetPosY())) {
				enemy->SetPos(1024, 1024, 1);
			}
		}
	}
	if ((keystates[SDL_SCANCODE_SPACE]) && player->getDirection() == 3 && SDL_GetTicks()) {
		//delayLeft = SDL_GetTicks();
		if (!player->IsCollidingWithWalls(3, mymap, CurrentMapNumber)) {
			player->AttackRight();
			if (player->IsCollidingWithEnemy(enemy->GetPosX(), enemy->GetPosY())) {
				enemy->SetPos(1024, 1024, 1);
			}
		}
	}
	if (keystates[SDL_SCANCODE_Q])
	{
		//player->Damage_1();
	}
	if (keystates[SDL_SCANCODE_E])
	{
		//player->Regenerate_1();
	}
	return CurrentMapNumber;
}
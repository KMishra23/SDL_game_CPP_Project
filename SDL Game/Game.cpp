#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "player.h"
#include "KeyboardInputManager.h"
#include "Enemy1.h"
#include "Health.h"
#include "Enemy.h"
#include "Turret.h"
#include "Bullet.h"
//#include "Scoreboard.h"

Player* player;
Enemy* enemy1;
Turret* turret1;
Bullet* bullet1;
Map* map;
KeyboardManager* KIM;
SDL_Renderer* Game::renderer = nullptr;
Health* temporary;

Game::Game(Scoreboard* scoreboard) 
{
	score = scoreboard;
}
Game::~Game() {}

void Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flag = 0;
	map_number = 1;
	if (fullscreen) flag = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "Subsystems initialized . . . " << endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
		if (window)
		{
			cout << "Window created" << endl;
		}
		
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << "Renderer created" << endl;
		}
		
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	//temporary = new Health(5);
	player = new Player("Assets/Movement_Attack.png", 192, 192, 4);
	enemy1 = new Enemy("Assets/Enemies.png", 1024 - 192, 256, 4, 1);
	turret1 = new Turret("Assets/Enemies.png", 128, 576, 4, -1);
	bullet1 = new Bullet("Assets/Enemies.png", 192, 64, 4, turret1->getDirection());
	bullet1->addTurret(turret1);
	
	PlayerAnimationHandler* PlayerAnimator = new PlayerAnimationHandler("Assets/Movement_Attack.png");
	player->assignAnimator(PlayerAnimator);
	map = new Map(1);
	KIM = new KeyboardManager();

	/*
	SDL_Surface* black = IMG_Load("Assets/Black.png");
	SDL_Texture* black_surface = SDL_CreateTextureFromSurface(renderer, black);
	SDL_FreeSurface(black);
	SDL_Rect blk_src, blk_dest;
	blk_dest.x = 0;
	blk_dest.y = 704;
	blk_dest.w = 1024;
	blk_dest.h = 100;
	blk_src.x = 0;
	blk_src.y = 0;
	blk_src.w = 1024;
	blk_src.h = 100;
	SDL_RenderCopy(renderer, black_surface, &blk_src, &blk_dest);
	*/
}

void Game::HandleEvents()
{
	SDL_PollEvent(&event);
	keystates = SDL_GetKeyboardState(NULL);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			cout << "Closing game . . ." << endl;
			isRunning = false;
			break;
		default:
			if (event.type == SDL_KEYDOWN)
			{
				map_number = KIM->KeyInputEvent(player, enemy1, keystates, map,map_number, score);
			}
			break;
		}
	default:
		break;
	}

	if (player->IsCollidingWithEnemy(enemy1->GetPosX(), enemy1->GetPosY()) || player->IsCollidingWithBullet(bullet1->GetPosX(), bullet1->GetPosY())) {
		if (map_number == 1) {
			player->Set(1024 - 64 * 3, 256 + 64);
		}
		if (map_number == 2) {
			player->Set(512 - 32, 704 - 3 * 64);
		}
		else {
			player->Set(512 - 32, 704 - 3 * 64);
		}
	}

	if (map_number != prev)
	{
		if (player->GetPosX() <= 128)
		{
			//map3
			player->Set(1024 - 64 * 3, 256+64);
			enemy1->SetPos(128+64, 64*5, 2);
			turret1->SetPos(128 - 64, 192, 2);
			bullet1->addTurret(turret1);
		}
		else if (player->GetPosX() >= 14 * 64)
		{
			//map1
			player->Set(128, 256+64);
			enemy1->SetPos(1024 - 192, 256, 1);
			turret1->SetPos(128, 576, -1);
			bullet1->addTurret(turret1);
		}
		else if (player->GetPosY() <= 128)
		{
			//map2
			player->Set(512 - 32, 704 - 3 * 64);
			enemy1->SetPos(128+64, 64*3, 2);
			turret1->SetPos(64, 576 - 128, 2);
			bullet1->addTurret(turret1);
		}
		else
		{
			player->Set(512 - 32, 128);
			enemy1->SetPos(192, 256, 1);
			turret1->SetPos(128, 576, -1);
			bullet1->addTurret(turret1);
		}
		prev = map_number;
	}
}

void Game::Update() 
{
	//count++;

	player->Update();
	enemy1->Update();
	turret1->Update();
	bullet1->Update();

	//cout << count << endl;
}

void Game::Render() 
{
	SDL_RenderClear(renderer);
	//player->renderHearts();
	map->DrawMap(map_number);
	map->LoadMap(map_number);
	player->Render();
	enemy1->Render();
	turret1->Render();
	bullet1->Render();
	SDL_RenderPresent(renderer);
}

void Game::Clean() 
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	cout << "Game Cleared" << endl;
}
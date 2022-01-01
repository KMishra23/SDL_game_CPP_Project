#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "player.h"
#include "KeyboardInputManager.h"
#include "Enemy1.h"
<<<<<<< HEAD
#include "Health.h"
=======
#include "Enemy.h"
>>>>>>> e35e0e1d8a88fab0fb6b67c6ef3445fc0e603b91

Player* player;
Enemy* enemy1;
Map* map;
KeyboardManager* KIM;
SDL_Renderer* Game::renderer = nullptr;
Health* temporary;

Game::Game() {}
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
				map_number = KIM->KeyInputEvent(player, enemy1, keystates, map,map_number);
			}
			break;
		}

	default:
		break;
	}
	if (player->IsCollidingWithEnemy(enemy1->GetPosX(), enemy1->GetPosY())) {
		cout << "boom" << endl;
	}

	if (map_number != prev)
	{
		if (player->GetPosX() <= 128)
		{
			//map3
			player->Set(1024 - 64 * 3, 256+64);
			enemy1->SetPos(128+64, 64*5, 2);
		}
		else if (player->GetPosX() >= 14 * 64)
		{
			//map1
			player->Set(128, 256+64);
			enemy1->SetPos(1024 - 192, 256, 1);
		}
		else if (player->GetPosY() <= 128)
		{
			//map2
			player->Set(512 - 32, 704 - 3 * 64);
			enemy1->SetPos(128+64, 64*3, 2);
		}
		else
		{
			player->Set(512 - 32, 128);
			enemy1->SetPos(192, 256, 1);
		}
		prev = map_number;
	}
}

void Game::Update() 
{
	//count++;

	player->Update();
	enemy1->Update();

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
	SDL_RenderPresent(renderer);
}

void Game::Clean() 
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	cout << "Game Cleared" << endl;
}
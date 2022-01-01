#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "player.h"
#include "KeyboardInputManager.h"
#include "Enemy1.h"

Player* player;
Map* map;
KeyboardManager* KIM;
SDL_Renderer* Game::renderer = nullptr;

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

	player = new Player("Assets/Movement_Attack.png", 192, 192, 4);
	Enemy1 *testEnemy = new Enemy1("Assets/Enemies.png", 240,240, 4, 0);
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
				map_number = KIM->KeyInputEvent(player, keystates, map,map_number);
			}
			break;
		}

	default:
		break;
	}
	if (map_number != prev)
	{
		if (player->GetPosX() <= 128)
		{
			player->Set(1024 - 64 * 3, 256+64);
		}
		else if (player->GetPosX() >= 14 * 64)
		{
			player->Set(128, 256+64);
		}
		else if (player->GetPosY() <= 128)
		{
			player->Set(512 - 32, 704 - 3 * 64);
		}
		else
		{
			player->Set(512 - 32, 128);
		}
		prev = map_number;
	}
}

void Game::Update() 
{
	//count++;

	player->Update();

	//cout << count << endl;
}

void Game::Render() 
{
	SDL_RenderClear(renderer);
	//player->renderHearts();
	map->DrawMap(map_number);
	map->LoadMap(map_number);
	player->Render();
	SDL_RenderPresent(renderer);
}

void Game::Clean() 
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);	
	SDL_Quit();

	cout << "Game Cleared" << endl;
}
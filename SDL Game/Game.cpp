#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "player.h"
#include "KeyboardInputManager.h"

Player* player;
Map* map;
KeyboardManager* KIM;

SDL_Renderer* Game::renderer = nullptr;

Game::Game() {}
Game::~Game() {}

void Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flag = 0;
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
	PlayerAnimationHandler* PlayerAnimator = new PlayerAnimationHandler();
	player->assignAnimator(PlayerAnimator);
	map = new Map();
	KIM = new KeyboardManager();
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
				KIM->KeyInputEvent(player, keystates,map);
			}
			break;
		}

	default:
		break;
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
	map->DrawMap();
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


#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "player.h"
#include "KeyboardInputManager.h"
#include <SDL.h>
//#include "Enemy1.h"
//#include "Health.h"
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
//Health* temporary;

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
	turret1 = new Turret("Assets/Enemies.png", 192, 64, 4, 1);

	player->initHealth();
	
	turret1 = new Turret("Assets/Enemies.png", 128, 576, 4, -1);
	bullet1 = new Bullet("Assets/Enemies.png", 192, 64, 4, turret1->getDirection());
	bullet1->addTurret(turret1);
	
	PlayerAnimationHandler* PlayerAnimator = new PlayerAnimationHandler("Assets/Movement_Attack.png");
	player->assignAnimator(PlayerAnimator);
	map = new Map(1);
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
			cout << "Key Pressed" << endl;
			switch (event.key.keysym.sym)
			{
			/*
			case SDLK_ESCAPE:
				cout << "Opening Menu" << endl;
				ShowMenu();
				cout << "Exiting Menu" << endl;
				cout << "is Running ->"<<isRunning << endl;
			break;
			*/
			default:
				if (event.type == SDL_KEYDOWN)
				{
					map_number = KIM->KeyInputEvent(player, enemy1, keystates, map,map_number, score);
				}
			break;
			}
		break;

		case SDL_MOUSEBUTTONDOWN:
			SDL_Rect Rect;
			Rect.x = 800;
			Rect.y = 900 - 195;
			Rect.w = 195;
			Rect.h = 80;
			int Mx, My;
			SDL_GetMouseState(&Mx, &My);
			if (Mx >= Rect.x && Mx <= Rect.x + Rect.w && My >= Rect.y && My <= Rect.y + Rect.h)
			{
				ShowMenu();
			}
		break;
	}
	if(player->EnemyCollisionCheck(enemy1) && player->getHeight() < 17 * 4 && player->getWidth() < 17 * 4) {
		player->Damage_1();
		score->UpdateScore(-1);

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

	if(player->BulletCollisionCheck(bullet1)) {
		player->Damage_1();
		score->UpdateScore(-1);

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

	if(map_number != prev)
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
	if (isRunning){
		//count++;
		player->Update();
		enemy1->Update();
		turret1->Update();
		bullet1->Update();
		//cout << count << endl;
	}
}

void Game::Render() 
{
	if (isRunning){
		SDL_RenderClear(renderer);
		player->renderHearts();
		map->DrawMap(map_number);
		map->LoadMap(map_number);
		player->Render();
		enemy1->Render();
		turret1->Render();
		bullet1->Render();
		Pause();
		SDL_RenderPresent(renderer);
	}
}

void Game::Clean() 
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	cout << "Game Cleared" << endl;
}

void Game::ShowMenu(){
	int Mx, My;
	isRunning = false;

	SDL_Texture* background = IMG_LoadTexture(renderer, "Assets/bg.png");
	SDL_Rect background_rect;
	background_rect.x = 0;
	background_rect.y = 0;
	background_rect.w = 1024;
	background_rect.h = 804;
	SDL_RenderCopy(renderer, background,NULL, &background_rect);

	const int NUMMENU = 2;
	SDL_Texture* menuText[NUMMENU];
	SDL_Surface* menu[NUMMENU];
	
	if (TTF_Init() == -1) {
		std::cout << "Could not initailize SDL2_ttf, error: " << TTF_GetError() << std::endl;
		return;
	}
	TTF_Font* Font = TTF_OpenFont("Assets/Game Of Squids.ttf", 200);
	if (Font == nullptr) {
		std::cout << "Could not load font" << std::endl;
		return;
	}
	
	menu[0] = TTF_RenderText_Solid(Font, "Continue Game", {255,255,255});
	menuText[0] = SDL_CreateTextureFromSurface(renderer, menu[0]);
	SDL_FreeSurface(menu[0]);

	menu[1] = TTF_RenderText_Solid(Font, "Exit", { 255,255,255 });
	menuText[1] = SDL_CreateTextureFromSurface(renderer, menu[1]);
	SDL_FreeSurface(menu[1]);
	
	SDL_Rect MenuRect[NUMMENU];
	
	SDL_Rect continueGame_Rect, exit_Rect;
	continueGame_Rect.x = 512 - 507 / 2;
	continueGame_Rect.y = 402 - 80;
	continueGame_Rect.w = 580;
	continueGame_Rect.h = 100;
	exit_Rect.x = 512 - 156 / 2;
	exit_Rect.y = 402 + 80;
	exit_Rect.w = 200;
	exit_Rect.h = 100;

	MenuRect[0] = continueGame_Rect;
	MenuRect[1] = exit_Rect;

	for (int i = 0; i < NUMMENU; i += 1) {
		SDL_SetTextureColorMod(menuText[i], 250, 250, 250);
		SDL_RenderCopy(renderer, menuText[i], NULL, &MenuRect[i]);
	}
	SDL_RenderPresent(renderer);

	SDL_Event e;
	while (1) {
		while (SDL_PollEvent(&e)) {
			switch (e.type){
				case SDL_QUIT:
					isRunning = false;
					return;
				break;
				case SDL_MOUSEBUTTONDOWN:
					SDL_GetMouseState(&Mx, &My);
					for (int i = 0; i < NUMMENU; i += 1) {
						if (Mx >= MenuRect[i].x && Mx <= MenuRect[i].x + MenuRect[i].w && My >= MenuRect[i].y && My <= MenuRect[i].y + MenuRect[i].h)
						{
							if (i == 0) {
								isRunning = true;
								for (int i = 0; i < NUMMENU; i += 1) {
									SDL_DestroyTexture(menuText[i]);
								}
								SDL_DestroyTexture(background);
								return;
							}
							else {
								isRunning = false;
								return;
							}
						}
					}
				break;
			}
		}
	}
	TTF_CloseFont(Font);
	TTF_Quit();
}

void Game::Pause(){
	if (TTF_Init() == -1) {
		std::cout << "Could not initailize SDL2_ttf, error: " << TTF_GetError() << std::endl;
		return;
	}
	TTF_Font* Font = TTF_OpenFont("Assets/Food Zone.ttf", 130);
	if (Font == nullptr) {
		std::cout << "Could not load font" << std::endl;
		return;
	}
	
	SDL_Surface* TextSurface = TTF_RenderText_Solid(Font, "Pause", {0,250,0 });
	SDL_Texture* TextTexture = SDL_CreateTextureFromSurface(renderer, TextSurface);
	SDL_FreeSurface(TextSurface);
	SDL_Rect Rect;
	Rect.x = 800;
	Rect.y = 900 - 195;
	Rect.w = 210;
	Rect.h = 100;
	SDL_RenderCopy(renderer, TextTexture, NULL, &Rect);
	TTF_CloseFont(Font);
	TTF_Quit();
}
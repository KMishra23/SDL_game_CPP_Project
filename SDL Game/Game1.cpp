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
			cout << "Menu" << endl;
			ShowMenu();
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
	player->renderHearts();
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

int Game::ShowMenu(){

	//WE CREATE THE COORDINATES OF THE MOUSE
	int Mx;
	int My;
	bool isRunning = false;

	//Let's make the menu's background
	SDL_Texture* background = IMG_LoadTexture(renderer, "Assets/bg.png");
	//Now the Background's rect, it should give us power to control it's size and location
	SDL_Rect background_rect;
	background_rect x = 0;   //X COORDINATE
	background_rect y = 0;   //Y COORDINATE
	background_rect w = 1024; //WIDTH
	background_rect h = 804; //HEIGHT
	/*Now, our background should start from the top left since it's coordinates are in
	(0, 0) and it should stretch 400 to the right and 400 down making it a square, 400X400*/

	//The New Game button
	const int NUMMENU = 2;
	const char* labels[NUMMENU] = {"Start Game","Exit" };
	SDL_Texture* menus[NUMMENU];
	SDL_Texture* newGame = IMG_LoadTexture(renderer, "FilePath");
	menus[0]=newGame;
	//The game button's rect
	SDL_Rect MenuRect[NUMMENU];
	SDL_Rect newGame_Rect;
	newGame_Rect.x = 0;
	newGame_Rect.y = 100;
	newGame_Rect.w = 50;
	newGame_Rect.h = 25;
	
	SDL_Texture* exit = IMG_LoadTexture(renderer, "FilePath");
	menus[1]=exit;
	//The exit button's rect
	SDL_Rect exit_Rect;
	exit_Rect.x = 0;
	exit_Rect.y = 200;
	exit_Rect.w = 50;
	exit_Rect.h = 25;
	
	MenuRect[0]=newGame_Rect;
	MenuRect[1]=exit_Rect;
	
	for(int i=0; i< NUMMENU; i += 1>)
			SDL_SetTextureColorMod(menus[i], 250, 250, 250);

		//Let's make an if statement that checks if the mouse is touching the New Game Button
	SDL_Event event;
	while(1){
		while(SDL_PollEvent(&event)){
			switch(event.type) {
				case SDL_MOUSEMOTION:
					SDL_GetMouseState(&Mx, &My); //This would constantly input the the x coordinate into Mx and the y coordinate of the mouse into My
			        for(int i=0; i<NUMMENU; i += 1>){
						if (Mx >= Menu_Rect[i].x && Mx <= Menu_Rect[i].x + Menu_Rect[i].w && My >= Menu_Rect[i].y && My <= Menu_Rect[i].y + Menu_Rect[i].h)
						{
							SDL_SetTextureColorMod(menus[i], 250, 0, 0);
						}
						else
						{
							SDL_SetTextureColorMod(menus[i], 250, 250, 250);
						// Tints the texture white if the cursor isn't over the button
						}
					}	
				break;			
				case SDL_MOUSEBUTTONDOWN:
					SDL_GetMouseState(&Mx, &My);
					for(int i=0; i<NUMMENU; i += 1>){
						if (Mx >= Menu_Rect[i].x && Mx <= Menu_Rect[i].x + Menu_Rect[i].w && My >= Menu_Rect[i].y && My <= Menu_Rect[i].y + Menu_Rect[i].h)
						{
							if(i==0){
								isRunning = true;
								return;
							}	
							else{ 
								isRunning = false;
								return 1;
							}	
						}
					}	
				break;
				case SDL_KEYDOWN:
					if (event.key.keysym.sym == SDLK_ESCAPE)
					{
						isRunning=false;
						return 1;
					}
				break;	
		}
	}
}
/*
int Game::ShowMenu(SDL_Surface* screen, TTF_Font* font) {
	Uint32 time;
	int x, y;
	const int NUMMENU = 2;
	const char* labels[NUMMENU] = {"Start Game","Exit" };
	SDL_Surface* menus[NUMMENU];
	bool selected[NUMMENU] = { 0,0 };
	SDL_Color color[2] = { {255,255,255},{255,0,0} };

	menus[0] = TTF_RenderText_Solid(font, labels[0], color[0]);
	menus[1] = TTF_RenderText_Solid(font, labels[1], color[0]);
	SDL_Rect pos[NUMMENU];
	pos[0].x = screen->clip_rect.w / 2 - menus[0]->clip_rect.w / 2;
	pos[0].y = screen->clip_rect.h / 2 - menus[0]->clip_rect.h;
	pos[1].x = screen->clip_rect.w / 2 - menus[0]->clip_rect.w / 2;
	pos[1].y = screen->clip_rect.h / 2 + menus[0]->clip_rect.h;

	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0x00, 0x00, 0x00));

	SDL_Event event;
	while (1)
	{
		time = SDL_GetTicks();
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				SDL_FreeSurface(menus[0]);
				SDL_FreeSurface(menus[1]);
				return 1;
			case SDL_MOUSEMOTION:
				x = event.motion.x;
				y = event.motion.y;
				for (int i = 0; i < NUMMENU; i += 1) {
					if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + pos[i].h)
					{
						if (!selected[i])
						{
							selected[i] = 1;
							SDL_FreeSurface(menus[i]);
							menus[i] = TTF_RenderText_Solid(font, labels[i], color[1]);
						}
					}
					else
					{
						if (selected[i])
						{
							selected[i] = 0;
							SDL_FreeSurface(menus[i]);
							menus[i] = TTF_RenderText_Solid(font, labels[i], color[0]);
						}
					}
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				x = event.button.x;
				y = event.button.y;
				for (int i = 0; i < NUMMENU; i += 1) {
					if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + pos[i].h)
					{
						SDL_FreeSurface(menus[0]);
						SDL_FreeSurface(menus[1]);
						return i;
					}
				}
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					SDL_FreeSurface(menus[0]);
					SDL_FreeSurface(menus[1]);
					return 0;
				}
			}
		}
		for (int i = 0; i < NUMMENU; i += 1) {
			SDL_BlitSurface(menus[i], NULL, screen, &pos[i]);
		}
		/*
		if (1000 / 30 > (SDL_GetTicks() - time))
			SDL_Delay(1000 / 30 - (SDL_GetTicks() - time));
		*/
/*
	}
}
*/
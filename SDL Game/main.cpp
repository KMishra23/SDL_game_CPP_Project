#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Scoreboard.h"
#include <vector>

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 804; //704 tak main screen hai
Game* game = nullptr;
Scoreboard* scoreboard = nullptr;

int main(int argc, char* argv[])
{	
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	scoreboard = new Scoreboard();
	game = new Game(scoreboard);

	game->Init("Korok Dungeon Alpha 3.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);
	
	while (game->Running())
	{
		//get total ticks before game update
		frameStart = SDL_GetTicks();

		game->HandleEvents();
		game->Update();
		game->Render();

		//get ticks that have passed after the game update
		frameTime = SDL_GetTicks() - frameStart;
		
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	scoreboard->saveScore();

	game->Clean();

	return 0;
}
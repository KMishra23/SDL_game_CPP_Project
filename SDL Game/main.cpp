#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

Game* game = nullptr;


int main(int argc, char* argv[])
{	
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();

	game->Init("Korok Dungeon Alpha 1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

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

	game->Clean();

	return 0;
}
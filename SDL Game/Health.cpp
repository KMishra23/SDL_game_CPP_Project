#include "Health.h"
#include "TextureManager.h"

Health::Health(int init_val)
{
	health_points = init_val;
	max_health = init_val;
	
	for (int i = 0; i < init_val; i++)
	{
		hearts.push_back(1);
	}
	
	hearts_sheet = TextureManager::LoadTexture("Assets/Hearts.png");
	if (hearts_sheet == NULL) cout << "Hearts not loaded" << endl;

	full_heart_src.x = 64;
	full_heart_src.y = 39;
	full_heart_src.h = 8;
	full_heart_src.w = 8;

	half_heart_src.x = 73;
	half_heart_src.y = 39;
	half_heart_src.h = 8;
	half_heart_src.w = 8;

	empty_heart_src.x = 82;
	empty_heart_src.y = 39;
	empty_heart_src.h = 8;
	empty_heart_src.w = 8;

	destRect.w = 64;
	destRect.h = 64;
	destRect.x = xpos;
	destRect.y = ypos;

	cout << max_health << endl;
}


void Health::Decrease_1()
{
	health_points--;
	if (health_points < 0) health_points = 0;
}

void Health::Increase_1()
{
	health_points++;
	if (health_points > max_health) health_points = max_health;
}

int Health::health_query()
{
	return health_points;
}

void Health::Update_Meter()
{
	for (int i = 0; i < max_health; i++)
	{
		hearts[i] = 1;
	}
	for (int i = health_points; i < max_health; i++)
	{
		hearts[i] = 0;
	}
}

void Health::Render()
{
	for (int i = 0; i < max_health; i++)
	{
		if (hearts[i] == 1) //render full heart
		{
			SDL_RenderCopy(Game::renderer, hearts_sheet, &full_heart_src, &destRect);
		}
		else //render empty heart
		{
			SDL_RenderCopy(Game::renderer, hearts_sheet, &empty_heart_src, &destRect);
		}
		destRect.x += 64;
	}
	destRect.x = xReset;
}


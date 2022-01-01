#include "Map.h"
#include "TextureManager.h"
#include<math.h>
int lvl1[11][16] = {
	{1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,1,0,0,0,0,0,0,1,0,0,1,1},
	{1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1},
	{2,0,0,0,0,1,1,1,1,1,1,0,0,0,0,2},
	{1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1},
	{1,1,0,0,1,0,0,0,0,0,0,1,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1}, 
	{1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1}
};

int lvl2[11][16] = {
	{1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
	{1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1},
	{1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1},
	{1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
	{1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1},
	{1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1},
	{1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1}
};

int lvl3[11][16] = {
	{1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
	{1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1},
	{1,1,0,0,0,0,1,1,0,0,0,0,1,1,1,1},
	{2,0,0,1,1,1,1,1,1,1,1,0,1,0,0,1},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{2,0,0,1,0,1,1,1,1,1,1,1,1,0,0,2},
	{1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1}
};

Map::Map(int num)
{
	Map_1 = TextureManager::LoadTexture("Assets/Map/Map_1.png");
	Map_2 = TextureManager::LoadTexture("Assets/Map/Map_2.png");
	Map_3 = TextureManager::LoadTexture("Assets/Map/Map_3.png");
	if (Map_1 == NULL)
	{
		cout << "Map_1 not loaded" << endl;
	}
	if (Map_2 == NULL)
	{
		cout << "Map_2 not loaded" << endl;
	}
	if (Map_3 == NULL)
	{
		cout << "Map_3 not loaded" << endl;
	}

	LoadMap(num);

	src.x = src.y = 0;
	src.w = 256;
	src.h = 176;
	dest.h = 176 * 4;
	dest.w = 256 * 4;

	dest.x = dest.y = 0;
}

void Map::LoadMap(int num)
{
	int arr[11][16];
	if (num == 1)
	{
		for(int i=0;i<11;i++)
		{
			for (int j = 0; j < 16; j++)
			{
				arr[i][j] = lvl1[i][j];
			}
		}

	}
	else if (num == 2)
	{
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				arr[i][j] = lvl2[i][j];
			}
		}
	}
	else if(num==3)
	{ 
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				arr[i][j] = lvl3[i][j];
			}
		}
	}
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			map[i][j] = arr[i][j];
		}
	}
}

void Map::DrawMap(int num)
{
	if(num==1)
	TextureManager::Draw(Map_1, src, dest);
	else if(num==2)
		TextureManager::Draw(Map_2, src, dest);
	else if(num==3)
		TextureManager::Draw(Map_3, src, dest);
}

int Map::CollisionQuery(int x,int y,int CurrMapNumber)
{
	if (x % 64 == 1)
	{
		if (map[(int)ceil((float)y / 64)][(x + 63) / 64] == 2 || map[(int)floor((float)y / 64)][(x + 63) / 64] == 2)
		{
			count++;
			cout << "yo" << endl;
			cout << maps[CurrMapNumber-1][1] << endl;
			return maps[CurrMapNumber-1][1];
			//return 2;
			
		}
		if (map[(int)ceil((float)y / 64)][(x + 63) / 64] == 1 || map[(int)floor((float)y / 64)][(x + 63) / 64] == 1)
		{
			return -1;
		}
	}
	else if (x % 64 == 63)
	{
		if (map[(int)ceil((float)y / 64)][(x - 63) / 64] == 2 || map[(int)floor((float)y / 64)][(x - 63) / 64] == 2)
		{
			cout << "yo" << endl;
			count++;
			cout << maps[CurrMapNumber-1][3] << endl;
			return  maps[CurrMapNumber-1][3];
			//return 2;
		}
		if (map[(int)ceil((float)y / 64)][(x - 63) / 64] == 1 || map[(int)floor((float)y / 64)][(x - 63) / 64] == 1)
		{
			return -1;
		}
	}
	else if (y % 64 == 1)
	{
		if (map[(y + 63) / 64][(int)ceil((float)(x) / 64)] == 2 || map[(y + 63) / 64][(int)floor((float)(x) / 64)] == 2)
		{
			cout << "yo" << endl;
			count++;
			cout << maps[CurrMapNumber-1][2] << endl;
			return maps[CurrMapNumber-1][2];
			//return 2;
		}
		if (map[(y+63) / 64][(int)ceil((float)(x) / 64)] == 1 || map[(y + 63) / 64][(int)floor((float)(x) / 64)] == 1)
		{
			return -1;
		}
	}
	else if (y % 64 == 63)
	{
		if (map[(y - 63) / 64][(int)ceil((float)(x) / 64)] == 2 || map[(y - 63) / 64][(int)floor((float)(x) / 64)] == 2)
		{

			cout << "yo" << endl;
			count++;
			cout << maps[CurrMapNumber-1][0] << endl;
			return maps[CurrMapNumber-1][0];
			//return 2;
		}
		if (map[(y - 63) / 64][(int)ceil((float)(x) / 64)] == 1 || map[(y - 63) / 64][(int)floor((float)(x) / 64)] == 1)
		{
			return -1;
		}

	}
		return 0;
}
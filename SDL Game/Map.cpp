#include "Map.h"
#include "TextureManager.h"
#include<math.h>
int lvl1[11][16] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,0,0,1,0,0,0,0,0,0,1,0,0,1,1},
	{1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1},
	{1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1},
	{1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1},
	{1,1,0,0,1,0,0,0,0,0,0,1,0,0,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int lvl2[11][16] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1},
	{1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1},
	{1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
	{1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1},
	{1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

Map::Map()
{
	Map_1 = TextureManager::LoadTexture("Assets/Map/Map_1.png");
	Map_2 = TextureManager::LoadTexture("Assets/Map/Map_2.png");
	if (Map_1 == NULL)
	{
		cout << "Map_1 not loaded" << endl;
	}
	if (Map_2 == NULL)
	{
		cout << "Map_2 not loaded" << endl;
	}

	LoadMap(lvl2);

	src.x = src.y = 0;
	src.w = 256;
	src.h = 176;
	dest.h = 176 * 4;
	dest.w = 256 * 4;

	dest.x = dest.y = 0;
}

void Map::LoadMap(int arr[11][16])
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			map[i][j] = arr[i][j];
		}
	}
}

void Map::DrawMap()
{
	TextureManager::Draw(Map_2, src, dest);
}

bool Map::CollisionQuery(int x,int y)
{
	//cout << x << " " << y << endl;
	//cout << x / 64 << " " << y / 64 << " " << map[x / 64][y / 64] << endl;
	//cout << x % 64 << " " << y % 64 << endl;
	if (x % 64 == 1)
	{
		//cout << (x + 63)/64 << " " << (int)ceil((float)y/64) << ' ';
		//cout << map[(int)ceil((float)y/64)][(x + 63) / 64] << endl;
		if (map[(int)ceil((float)y / 64)][(x + 63) / 64] == 1 || map[(int)floor((float)y / 64)][(x + 63) / 64] == 1)
		{
			return true;
		}
	}
	else if (x % 64 == 63)
	{
		//cout << (x - 63)/64 << " " << (int)ceil((float)y/64)<< " ";
		//cout << map[(int)ceil((float)y / 64)][(x-63) / 64] << endl;
		if (map[(int)ceil((float)y / 64)][(x - 63) / 64] == 1 || map[(int)floor((float)y / 64)][(x - 63) / 64] == 1)
		{
			return true;
		}
	}
	else if (y % 64 == 1)
	{
		//cout << (int)ceil((float)x/64) << " " << (y + 63)/64<< ' ';
		//cout << map[(y +63) / 64][(int)ceil((float)(x) / 64)] << endl;;
		if (map[(y+63) / 64][(int)ceil((float)(x) / 64)] == 1 || map[(y + 63) / 64][(int)floor((float)(x) / 64)] == 1)
		{
			return true;
		}
	}
	else if (y % 64 == 63)
	{
		//cout << (int)ceil((float)x/64) << (y - 63)/64 << " ";
		//cout << map[(y - 63) / 64][(int)ceil((float)(x) / 64)] << endl;;
		if (map[(y - 63) / 64][(int)ceil((float)(x) / 64)] == 1 || map[(y - 63) / 64][(int)floor((float)(x) / 64)] == 1)
		{
			return true;
		}
	}
	//cout << "collision nhi ho rha at " << x << " " << y << endl;

		return false;
}
#include "Map.h"
#include "TextureManager.h"

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

Map::Map()
{
	Map_1 = TextureManager::LoadTexture("Assets/Map/Map_1.png");
	if (Map_1 == NULL)
	{
		cout << "Map_1 not loaded" << endl;
	}

	LoadMap(lvl1);

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
	TextureManager::Draw(Map_1, src, dest);
}
bool Map::CollisionQuery(int x,int y)
{
	cout << x << " " << y << endl;
	cout << x / 64 << " " << y / 64 << " " << map[x / 64][y / 64] << endl;
	if (x < 0 || y < 0)
	{
		return true;
	}
	else if (map[x / 64][y/ 64] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
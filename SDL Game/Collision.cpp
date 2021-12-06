#include"KeyboardInputManager.h"
bool KeyboardManager::IscollidingWithWalls(int direction,int x,int y,Map* mymap)
{

	if (direction == 0 && mymap->CollisionQuery(x,y-32))
	{
		cout << "collision ho rha hai" << endl;
		return true;
	}
	else if (direction == 1 && mymap->CollisionQuery(x + 32, y))
	{
		cout << "collision ho rha hai" << endl;
		return true;
	}
	else if (direction == 2 && mymap->CollisionQuery(x, y +32))
	{
		cout << "collision ho rha hai" << endl;
		return true;
	}
	else if (direction == 3 && mymap->CollisionQuery(x - 32, y))
	{
		cout << "collision ho rha hai" << endl;
		return true;
	}
	return false;
}
bool IsCollidingWithBullet()
{
	return true;
}
bool IsCollidingWithEnemy()
{
	return false;
}
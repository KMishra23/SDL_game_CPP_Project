#include"player.h"
bool Player::IsCollidingWithWalls(int direction,Map* mymap)
{
	
	if (direction == 0 && mymap->CollisionQuery(GetPosX(), GetPosY() - 1))
	{
		//cout << "collision ho rha hai" << endl;
		return true;
	}
	else if (direction == 1 && mymap->CollisionQuery(GetPosX() + 1, GetPosY()))
	{
		//cout << "collision ho rha hai" << endl;
		return true;
	}
	else if (direction == 2 && mymap->CollisionQuery(GetPosX(), GetPosY() +1))
	{
		//cout << "collision ho rha hai" << endl;
		return true;
	}
	else if (direction == 3 && mymap->CollisionQuery(GetPosX() - 1, GetPosY()))
	{
		//cout << "collision ho rha hai" << endl;
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
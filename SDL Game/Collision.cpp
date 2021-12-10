#include"player.h"
bool Player::IsCollidingWithWalls(int direction,Map* mymap,int CurrMapNumber)
{
	
	if (direction == 0 && (mymap->CollisionQuery(GetPosX(), GetPosY() - 1, CurrMapNumber)==-1 ))
	{
		return true;
	}
	else if (direction == 1 && (mymap->CollisionQuery(GetPosX() + 1, GetPosY(), CurrMapNumber)==-1))
	{
		return true;
	}
	else if (direction == 2 && (mymap->CollisionQuery(GetPosX(), GetPosY() +1, CurrMapNumber))==-1)
	{
		return true;
	}
	else if (direction == 3 && (mymap->CollisionQuery(GetPosX() - 1, GetPosY(), CurrMapNumber))==-1)
	{
		return true;
	}
	return false;
}
int Player::IsChangingMap(int direction, Map* mymap, int CurrMapNumber)
{
	if (direction == 0 && (mymap->CollisionQuery(GetPosX(), GetPosY() - 1,CurrMapNumber))>0)
	{
		return (mymap->CollisionQuery(GetPosX(), GetPosY() - 1, CurrMapNumber));
		//return 2;
	}
	else if (direction == 1 && (mymap->CollisionQuery(GetPosX() + 1, GetPosY(), CurrMapNumber) )>0)
	{		
		return  (mymap->CollisionQuery(GetPosX() + 1, GetPosY(), CurrMapNumber));
		//return 2;
	}
	else if (direction == 2 && (mymap->CollisionQuery(GetPosX(), GetPosY() + 1, CurrMapNumber))>0)
	{
		return(mymap->CollisionQuery(GetPosX(), GetPosY() + 1, CurrMapNumber));
		//return 2;
	}
	else if (direction == 3 && (mymap->CollisionQuery(GetPosX() - 1, GetPosY(), CurrMapNumber))>0)
	{
		return (mymap->CollisionQuery(GetPosX() - 1, GetPosY(), CurrMapNumber));
		//return 2;
	}
	return CurrMapNumber;
}
bool IsCollidingWithBullet()
{
	return true;
}
bool IsCollidingWithEnemy()
{
	return false;
}
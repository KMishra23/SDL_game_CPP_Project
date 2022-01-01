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
bool Player::IsCollidingWithBullet(int BulletX,int BulletY)
{
	if (BulletX-GetPosX() ==64 && (BulletY>=GetPosY()-32 && BulletY<=GetPosY()+64 ))
	{
		return true;
	}
	else if (GetPosX() - BulletX == 32 && (BulletY >= GetPosY() - 32 && BulletY <= GetPosY() + 64))
	{
		return true;
	}
	else if (GetPosY() - BulletY == 32 && (BulletX >= GetPosX() - 32 && BulletX <= GetPosX() + 64))
	{
		return true;
	}
	else if (BulletY - GetPosY() == 64 && (BulletX >= GetPosX() - 32 && BulletX <= GetPosX() + 64))
	{
		return true;
	}
	return false;
}
bool Player::IsCollidingWithEnemy(int EnemyX,int EnemyY)
{
	if (EnemyX - GetPosX() == 64 && (EnemyY >= GetPosY() - 64 && EnemyY <= GetPosY() + 64))
	{
		return true;
	}
	else if (GetPosX() - EnemyX == 64 && (EnemyY >= GetPosY() - 64 && EnemyY <= GetPosY() + 64))
	{
		return true;
	}
	else if (GetPosY() - EnemyY == 64 && (EnemyX >= GetPosX() - 64 && EnemyX <= GetPosX() + 64))
	{
		return true;
	}
	else if (EnemyY - GetPosY() == 64 && (EnemyX >= GetPosX() - 64 && EnemyX <= GetPosX() + 64))
	{
		return true;
	}
	return false;
}
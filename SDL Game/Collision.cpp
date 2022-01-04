#include "player.h"
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
	if (BulletX - GetPosX() == 64 && (BulletY >= GetPosY() - 32 && BulletY <= GetPosY() + 64))
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

bool Player::IsCollectingCoin(int CoinX, int CoinY)
{
	if (CoinX - GetPosX() == 64 && (CoinY >= GetPosY() - 64 && CoinY <= GetPosY() + 64))
	{
		return true;
	}
	else if (GetPosX() - CoinX == 64 && (CoinY >= GetPosY() - 64 && CoinY <= GetPosY() + 64))
	{
		return true;
	}
	else if (GetPosY() - CoinY == 64 && (CoinX >= GetPosX() - 64 && CoinX <= GetPosX() + 64))
	{
		return true;
	}
	else if (CoinY - GetPosY() == 64 && (CoinX >= GetPosX() - 64 && CoinX <= GetPosX() + 64))
	{
		return true;
	}
	return false;
}

bool Player::BulletCollisionCheck(Bullet* bullet) 
{
	return
		bullet->GetPosX() + bullet->getWidth() > GetPosX() &&
		bullet->GetPosY() + bullet->getHeight() > GetPosY() &&
		GetPosX() + getWidth() > bullet->GetPosX() &&
		GetPosY() + getHeight() > bullet->GetPosY();
}

bool Player::EnemyCollisionCheck(Enemy* enemy) 
{
	return
		(enemy->GetPosX()+2) + (enemy->getWidth()+2) > GetPosX() &&
		(enemy->GetPosY()+2)+ (enemy->getHeight()+2) > GetPosY() &&
		GetPosX() + getWidth() > (enemy->GetPosX()+2) &&
		GetPosY() + getHeight() > (enemy->GetPosY()+2);
}
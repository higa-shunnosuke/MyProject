#include "Collinder.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Player.h"
#include "math.h"
#include "DxLib.h"

bool HitCheck()
{
	int ret = false;
	double x = pow(GetBulletX() - GetEnemyX(), 2);
	double y = pow(GetBulletY() - GetEnemyY(), 2);
	double r = pow(GetBulletR() + GetEnemyR(), 2);

	if (x + y < r)
	{
		ret = true;
	}

	return ret;

}
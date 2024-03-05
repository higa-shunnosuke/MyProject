#include "Common.h"
#include "Collinder.h"
#include "Bullet.h"
#include "Player.h"
#include "DxLib.h"
#include "math.h"


float BulletX;     //バレットのX座標
float BulletY;     //バレットのY座標
float BulletR;     //バレットの半径
float BulletSpeedX;     //バレットのX座標移動距離
float BulletSpeedY;     //バレットのY座標移動距離
float g;				//重力
unsigned int BulletColor;     //バレットの色
int ReflectionCount;	//反射回数
bool Is_Delet;		//消滅フラグ

//初期化処理
void Bullet_Initialize(float x, float y)
{
	BulletX = x;
	BulletY = y;
	BulletR = 20.0f;
	g = 1.0f;
	ReflectionCount = 0;	//反射回数
	Is_Delet = false;

	switch (GetType())
	{
	case 1:
		BulletSpeedX = 20.0f;
		BulletSpeedY = 20.0f;
		BulletColor = 0xffffff;     //バレットの色
		break;

	case 2:
		BulletSpeedX = 20.0f;
		BulletSpeedY = 20.0f;
		BulletColor = 0xff;     //バレットの色
		break;
	default:
		break;
	}
}


//更新処理
void Bullet_Update(double r)
{
	
	Bullet_Vector(r);
	DeletCheck();

	switch (GetType())
	{
	case 1:
		//反射処理
		if (BulletX + BulletR > SCREEN_RIGHT)
		{
			BulletSpeedX *= -1;
			ReflectionCount++;
		}
		if (BulletX - BulletR < SCREEN_LEFT)
		{
			BulletSpeedX *= -1;
			ReflectionCount++;
		}
		if (BulletY + BulletR > SCREEN_UNDER)
		{
			BulletSpeedY *= -1;
			ReflectionCount++;
		}
		if (BulletY - BulletR < SCREEN_UPPER)
		{
			BulletSpeedY *= -1;
			ReflectionCount++;
		}
		break;
	case 2:
		//反射処理
		if (BulletX + BulletR >= SCREEN_RIGHT)
		{
			ReflectionCount=6;
		}
		if (BulletX - BulletR < SCREEN_LEFT)
		{
			ReflectionCount=6;
		}
		if (BulletY + BulletR > SCREEN_UNDER)
		{
			ReflectionCount=6;
		}
		if (BulletY - BulletR < SCREEN_UPPER)
		{
			ReflectionCount=6;
		}
		break;
	default:
		break;
	}
}

//描画処理
void Bullet_Draw()
{
	DrawCircleAA(BulletX, BulletY, BulletR, 100, BulletColor, TRUE);

	DrawFormatString(450, 50, GetColor(255, 255, 255), "反射回数：%d", ReflectionCount);
	DrawFormatString(850, 50, GetColor(255, 255, 255), "x：%f", BulletX);
	DrawFormatString(850, 100, GetColor(255, 255, 255), "y：%f", BulletY);
}


//移動処理
void Bullet_Vector(double Radian)
{
	BulletX += BulletSpeedX * cos(Radian);
	BulletY -= BulletSpeedY * sin(Radian);
}

//反射回数取得処理
int GetBRC()
{
	return ReflectionCount;
}

float GetBulletX()
{
	return BulletX;
}
float GetBulletY()
{
	return BulletY;
}
float GetBulletR()
{
	return BulletR;
}

bool DeletCheck()
{
	if (HitCheck())
	{
		Is_Delet = true;
	}
	return Is_Delet;
}

void Delet()
{

}
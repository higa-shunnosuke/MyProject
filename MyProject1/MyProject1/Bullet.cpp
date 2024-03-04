#include "Bullet.h"
#include "DxLib.h"
#include "math.h"
#include "Common.h"
#include "Player.h"


float BulletX;     //バレットのX座標
float BulletY;     //バレットのY座標
float BulletR;     //バレットの半径
float BulletSpeedX;     //バレットのX座標移動距離
float BulletSpeedY;     //バレットのY座標移動距離
float g;				//重力
unsigned int BulletColor1;     //バレットの色
unsigned int BulletColor2;     //バレットの色
unsigned int BulletColor3;     //バレットの色
int ReflectionCount;	//反射回数

//初期化処理
void Bullet_Initialize(float x, float y)
{
	BulletX = x;
	BulletY = y;
	BulletR = 20.0f;
	BulletSpeedX = 20.0f;
	BulletSpeedY = 20.0f;
	g = 1.0f;
	BulletColor1 = 0xffffff;     //バレットの色
	BulletColor2 = 0xffff;     //バレットの色
	BulletColor3 = 0xff;     //バレットの色
	ReflectionCount = 0;	//反射回数
}


//更新処理
void Bullet_Update(double r,int type)
{
	
	Bullet_Vector(r);

	switch (type)
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
		BulletSpeedX = 30.0f;
		BulletSpeedY = 30.0f;
		//反射処理
		if (BulletX + BulletR > SCREEN_RIGHT)
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
	case 3:
		//反射処理
		if (BulletX + BulletR > SCREEN_RIGHT)
		{
			BulletSpeedX *= -1;
		}
		if (BulletX - BulletR < SCREEN_LEFT)
		{
			BulletSpeedX *= -1;
		}
		if (BulletY + BulletR > SCREEN_UNDER)
		{
			BulletSpeedY *= -1;
		}
		else
		{
			Fall();
		}
		if (BulletY - BulletR < SCREEN_UPPER)
		{
			BulletSpeedY *= -1;
		}
		break;
	default:
		break;
	}
}

//描画処理
void Bullet_Draw(int type)
{
	switch (type)
	{
	case 1:
		DrawCircleAA(BulletX, BulletY, BulletR, 100, BulletColor1, TRUE);
		break;
	case 2:
		DrawCircleAA(BulletX, BulletY, BulletR, 100, BulletColor2, TRUE);
		break;
	case 3:
		DrawCircleAA(BulletX, BulletY, BulletR, 100, BulletColor3, TRUE);
		break;
	default:
		break;
	}

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

//落下処理
void Fall()
{
	BulletY += g;
	g++;
}

//反射回数取得処理
int GetBRC()
{
	return ReflectionCount;
}

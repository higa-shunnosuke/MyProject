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
unsigned int BulletColor;     //バレットの色
int ReflectionCount;	//反射回数

//初期化処理
void Bullet_Initialize(float x, float y)
{
	BulletX = x;
	BulletY = y;
	BulletR = 20.0f;
	BulletSpeedX = 20.0f;
	BulletSpeedY = 20.0f;
	BulletColor = 0xffffff;     //バレットの色
	ReflectionCount = 0;	//反射回数
}


//更新処理
void Bullet_Update(double r)
{
	
	Bullet_Vector(r);

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

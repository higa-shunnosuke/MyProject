#include "Common.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "DxLib.h"
#include "math.h"


float BulletX;     //バレットのX座標
float BulletY;     //バレットのY座標
float BulletR;     //バレットの半径
float BulletSpeedX;     //バレットのX座標移動距離
float BulletSpeedY;     //バレットのY座標移動距離
unsigned int BulletColor;     //バレットの色
int ReflectionCount;	//反射回数
int BulletCount;	//反射回数
bool Is_Delet;		//消滅フラグ

//初期化処理
void Bullet_Initialize()
{
	BulletX = GetPlayerX();
	BulletY = GetPlayerY();
	BulletR = 15.0f;
	ReflectionCount = 0;
	BulletCount = 0;
	Is_Delet = false;

	switch (GetType())
	{
	case 1:
		BulletSpeedX = 20.0f;
		BulletSpeedY = 20.0f;
		BulletColor = 0xffffff;     //バレットの色
		break;
	case 2:
		BulletSpeedX = 30.0f;
		BulletSpeedY = 30.0f;
		BulletColor = 0xff;     //バレットの色
		break;
	default:
		break;
	}
}


//更新処理
void Bullet_Update()
{
	Bullet_Vector();
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
			SetDelet(true);
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

	/*if (GetDeth() == true)
	{
		Delet();
	}*/
}

//描画処理
void Bullet_Draw()
{
	/*if (Is_Delet==false)
	{*/
		DrawCircleAA(BulletX, BulletY, BulletR, 100, BulletColor, TRUE);
	/*}*/

	DrawFormatString(450, 0, GetColor(255, 255, 255), "反射回数：%d", ReflectionCount);
	/*DrawFormatString(850, 50, GetColor(255, 255, 255), "x：%f", BulletX);
	DrawFormatString(850, 100, GetColor(255, 255, 255), "y：%f", BulletY);
	DrawFormatString(850, 150, GetColor(255, 255, 255), "flg：%d", Is_Delet);
	if (HitCheck()==true)
	{
		DrawFormatString(850, 200, GetColor(255, 255, 255), "当たり");
	}*/
}


//移動処理
void Bullet_Vector()
{
	BulletX += BulletSpeedX * cos(GetRadian());
	BulletY -= BulletSpeedY * sin(GetRadian());
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

bool GetDelet()
{
	return Is_Delet;
}

void SetDelet(int flg)
{
	Is_Delet = flg;
}

bool DeletCheck()
{
	for (int i = 0; i < 3; i++)
	{
		if (HitCheck(i) == true)
		{
			if (GetType() == 1)
			{
				SetDelet(true);
				break;
			}
		}
	}
	
	return Is_Delet;
}

#include "Common.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "DxLib.h"
#include "math.h"

/****************************************************
*変数宣言
*****************************************************/
float BulletX;			//バレットのX座標
float BulletY;			//バレットのY座標
float BulletR;			//バレットの半径
float BulletSpeedX;		//バレットのX座標移動速度
float BulletSpeedY;		//バレットのY座標移動速度
unsigned int BulletColor;	//バレットの色
int ReflectionCount;	//反射回数
int BulletCount;		//反射回数
bool Is_Delet;			//消滅フラグ

/****************************************************
*バレット：初期化処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void Bullet_Initialize()
{
	BulletX = GetPlayerX();
	BulletY = GetPlayerY();
	BulletR = 15.0f;
	ReflectionCount = 0;
	BulletCount = 0;
	Is_Delet = false;

	//それぞれのタイプの弾の初期化
	switch (GetType())
	{
	case 1:
		BulletSpeedX = 20.0f;
		BulletSpeedY = 20.0f;
		BulletColor = 0xffffff;
		break;
	case 2:
		BulletSpeedX = 30.0f;
		BulletSpeedY = 30.0f;
		BulletColor = 0xff;
		break;
	default:
		break;
	}
}

/****************************************************
*バレット：更新処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void Bullet_Update()
{
	int reflection;

	Bullet_Vector();
	DeletCheck();

	switch (GetType())
	{
	case 1:
		//反射弾処理
		for (int i = 0; i < 4; i++)
		{
			reflection = 0;

			if (BulletX + BulletR > SCREEN_RIGHT)
			{
				reflection = 1;
				break;
			}
			if (BulletX - BulletR < SCREEN_LEFT)
			{
				reflection = 1;
				break;
			}
			if (BulletY + BulletR > SCREEN_UNDER)
			{
				reflection = 2;
				break;
			}
			if (BulletY - BulletR < SCREEN_UPPER)
			{
				reflection = 2;
				break;
			}
		}
		if (reflection == 1)
		{
			BulletSpeedX *= -1;
			ReflectionCount++;
		}
		else if (reflection==2)
		{
			BulletSpeedY *= -1;
			ReflectionCount++;
		}
		break;
	case 2:
		//貫通弾処理
		for (int i = 0; i < 4; i++)
		{
			reflection = 0;

			if (BulletX + BulletR > SCREEN_RIGHT)
			{
				reflection = 1;
				break;
			}
			if (BulletX - BulletR < SCREEN_LEFT)
			{
				reflection = 1;
				break;
			}
			if (BulletY + BulletR > SCREEN_UNDER)
			{
				reflection = 1;
				break;
			}
			if (BulletY - BulletR < SCREEN_UPPER)
			{
				reflection = 1;
				break;
			}
		}
		if (reflection == 1)
		{
			ReflectionCount = 6;
			for (int i = 0; i < 3; i++)
			{
				SetHit(i);
			}
		}
		break;
	default:
		break;
	}
}

/****************************************************
*バレット：描画処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void Bullet_Draw()
{
	DrawCircleAA(BulletX, BulletY, BulletR, 100, BulletColor, TRUE);
	DrawFormatString(450, 0, GetColor(255, 255, 255), "反射回数：%d", ReflectionCount);
}

/****************************************************
*バレット：移動処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void Bullet_Vector()
{
	BulletX += BulletSpeedX * cos(GetRadian());
	BulletY -= BulletSpeedY * sin(GetRadian());
}

/****************************************************
*バレット：フラグ設定処理
* 引　数：flg(true=消す,false=消さない)
* 戻り値：なし
*****************************************************/
void SetDelet(int flg)
{
	Is_Delet = flg;
}

/****************************************************
*バレット：反射回数取得処理
* 引　数：なし
* 戻り値：反射回数
*****************************************************/
int GetBRC()
{
	return ReflectionCount;
}
/****************************************************
*バレット：X座標取得処理
* 引　数：なし
* 戻り値：X座標
*****************************************************/
float GetBulletX()
{
	return BulletX;
}
/****************************************************
*バレット：Y座標取得処理
* 引　数：なし
* 戻り値：Y座標
*****************************************************/
float GetBulletY()
{
	return BulletY;
}
/****************************************************
*バレット：半径取得処理
* 引　数：なし
* 戻り値：半径
*****************************************************/
float GetBulletR()
{
	return BulletR;
}
/****************************************************
*バレット：消滅フラグ取得処理
* 引　数：なし
* 戻り値：消滅フラグ
*****************************************************/
bool GetDelet()
{
	return Is_Delet;
}
/****************************************************
*バレット：ヒット判定処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void DeletCheck()
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
}

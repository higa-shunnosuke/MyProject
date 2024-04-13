#include "Enemy.h"
#include "Common.h"
#include "Bullet.h"
#include "Player.h"
#include "DxLib.h"
#include "math.h"
#include"StageSelectScene.h"

/****************************************************
*型定義
*****************************************************/
typedef struct
{
	int type;
	float x;
	float y;
	float r;
	int hit;
}Enemy;

/****************************************************
*変数宣言
*****************************************************/
bool Is_Deth;		//死亡フラグ
Enemy enemy[3];
int HitCount;		//ヒット回数

/****************************************************
*エネミー：初期化処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void Enemy_Initialize()
{
	switch (GetStageNum())
	{
	case 1:
		enemy[0] = 
		{0,980.0f,645.0f,25.0f,0};
		enemy[1] = 
		{1,1080.0f,645.0f,25.0f,0};
		break;
	case 2:
	
		break;
	case 3:
		
		break;
	case 4:
		
		break;
	case 5:
	
		break;
	case 6:
	
		break;
	case 7:
	
		break;
	case 8:
	
		break;
	default:
		break;
	}

	HitCount = 0;
	Is_Deth = false;
}

/****************************************************
*エネミー：更新処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void Enemy_Update()
{
	DamageCheck();
}

/****************************************************
*エネミー：描画処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void Enemy_Draw()
{
		for (int j = 0; j < 3; j++)
		{
			if (enemy[j].type>0)
			{
				DrawCircleAA(enemy[j].x, enemy[j].y, enemy[j].r, 100, 0xfff000, TRUE);
			}
			else
			{
				DrawCircleAA(enemy[j].x, enemy[j].y, enemy[j].r, 100, 0xff0000, TRUE);
			}
		}
}

/****************************************************
*エネミー：X座標取得処理
* 引　数：なし
* 戻り値：X座標
*****************************************************/
float GetEnemyX(int i)
{
	return enemy[i].x;
}
/****************************************************
*エネミー：Y座標取得処理
* 引　数：なし
* 戻り値：Y座標
*****************************************************/
float GetEnemyY(int i)
{
	return enemy[i].y;
}
/****************************************************
*エネミー：半径取得処理
* 引　数：なし
* 戻り値：半径
*****************************************************/
float GetEnemyR(int i)
{
	return enemy[i].r;
}
/****************************************************
*エネミー：ダメージ処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void DamageCheck()
{
	for (int i = 0; i < 3; i++)
	{
		if (HitCheck(i) == true)
		{
			if (GetType() == 1)
			{
				if (enemy[i].type>0)
				{
					enemy[i].type--;
					Bullet_Initialize();
					break;
				}
				else
				{
					Deth(i);
					if (GetType() == 1)
					{
						Bullet_Initialize();
					}
				}
			}
			else
			{
				if (enemy[i].hit == 0)
				{
					if (enemy[i].type > 0)
					{
						enemy[i].hit = 1;
						enemy[i].type--;
					}
					else
					{
						Deth(i);
					}
				}
			}
		}
	}
}

/****************************************************
*エネミー：死亡処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void Deth(int i)
{
	enemy[i].x = 10.0f;
	enemy[i].y = 10.0f;
}

/****************************************************
*エネミー：ヒットチェック処理
* 引　数：なし
* 戻り値：ture=当たった,false=当たっていない
*****************************************************/
bool HitCheck(int i)
{
	int ret = false;
	double x = pow(GetBulletX() - enemy[i].x, 2);
	double y = pow(GetBulletY() - enemy[i].y, 2);
	double r = pow(GetBulletR() + enemy[i].r, 2);

	if (x + y < r)
	{
		ret = true;
	}

	return ret;
}

/****************************************************
*エネミー：ヒット設定処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void SetHit(int i)
{
	enemy[i].hit = 0;
}
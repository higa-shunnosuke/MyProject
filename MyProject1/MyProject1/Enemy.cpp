#include "Enemy.h"
#include "Common.h"
#include "Bullet.h"
#include "Player.h"
#include "DxLib.h"
#include "math.h"
#include"StageSelectScene.h"

typedef struct
{
	int type;
	float x;
	float y;
	float r;
}Enemy;

//float EnemyX;		//敵のX座標
//float EnemyY;		//敵のY座標
//float EnemyR;		//敵の半径
bool Is_Deth;		//死亡フラグ
Enemy enemy[10];

//初期化処理
void Enemy_Initialize()
{
	switch (GetStageNum())
	{
	case 1:
		enemy[0] = 
		{1,980.0f,645.0f,25.0f};
		enemy[1] = 
		{1,980.0f,545.0f,25.0f};
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

	Is_Deth = false;
}

//プレイヤー更新処理
void Enemy_Update()
{
	DethCheck();
}

//プレイヤー描画処理
void Enemy_Draw()
{
	if (GetDeth() != true)
	{
		for (int i = 0; i < 3; i++)
		{
			DrawCircleAA(enemy[i].x, enemy[i].y, enemy[i].r, 100, 0xff0000, TRUE);
		}
	}
}

float GetEnemyX()
{
	return enemy[1].x;
}
float GetEnemyY()
{
	return enemy[1].y;
}
float GetEnemyR()
{
	return enemy[1].r;
}

bool GetDeth()
{
	return Is_Deth;
}

bool DethCheck()
{
	if (HitCheck()==true)
	{
		Is_Deth = true;
		Deth();
	}
	return Is_Deth;
}

void Deth()
{
	enemy[1].x = 10.0f;
	enemy[1].y = 10.0f;
	//Is_Deth == false;
}

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
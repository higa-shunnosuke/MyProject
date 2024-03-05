#include "Enemy.h"
#include "Common.h"
#include "Bullet.h"
#include "Player.h"
#include "DxLib.h"
#include "math.h"
#include"StageSelectScene.h"
#include"Collinder.h"


float EnemyX;		//敵のX座標
float EnemyY;		//敵のY座標
float EnemyR;		//敵の半径
bool Is_Deth;		//死亡フラグ

//初期化処理
void Enemy_Initialize()
{
	switch (GetStageNum())
	{
	case 1:
		EnemyX = 980.0f;
		EnemyY = 645.0f;

		break;
	case 2:
		EnemyX = 300.0f;
		EnemyY = 645.0f;

		break;
	case 3:
		EnemyX = 300.0f;
		EnemyY = 645.0f;

		break;
	case 4:
		EnemyX = 300.0f;
		EnemyY = 645.0f;

		break;
	case 5:
		EnemyX = 300.0f;
		EnemyY = 645.0f;

		break;
	case 6:
		EnemyX = 300.0f;
		EnemyY = 645.0f;

		break;
	case 7:
		EnemyX = 300.0f;
		EnemyY = 645.0f;

		break;
	case 8:
		EnemyX = 300.0f;
		EnemyY = 645.0f;

		break;
	default:
		break;
	}

	EnemyR = 25.0f;
	Is_Deth = false;

}

//プレイヤー更新処理
void Enemy_Update()
{

	Enemy_Control();

}

//プレイヤー描画処理
void Enemy_Draw()
{
	DrawCircleAA(EnemyX,EnemyY, EnemyR, 100, 0xff0000, TRUE);
}


void Enemy_Control()
{
	
}

float GetEnemyX()
{
	return EnemyX;
}
float GetEnemyY()
{
	return EnemyY;
}
float GetEnemyR()
{
	return EnemyR;
}

bool DethCheck()
{
	if (HitCheck())
	{
		Is_Deth = true;
	}
	return Is_Deth;
}
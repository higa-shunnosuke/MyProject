#include "Enemy.h"
#include "Common.h"
#include "Bullet.h"
#include "Player.h"
#include "DxLib.h"
#include "math.h"
#include"StageSelectScene.h"
#include"Collinder.h"


float EnemyX;		//�G��X���W
float EnemyY;		//�G��Y���W
float EnemyR;		//�G�̔��a
bool Is_Deth;		//���S�t���O

//����������
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

//�v���C���[�X�V����
void Enemy_Update()
{

	/*Enemy_Control();*/

	/*if (DethCheck() == true)
	{
		Deth();
	}*/

}

//�v���C���[�`�揈��
void Enemy_Draw()
{
	DrawCircleAA(EnemyX,EnemyY, EnemyR, 100, 0xff0000, TRUE);
	if (GetDeth() == true)
	{
		DrawFormatString(850, 250, GetColor(255, 255, 255), "deth");
	}
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

bool GetDeth()
{
	return Is_Deth;
}

bool DethCheck()
{
	if (HitCheck()==true)
	{
		Is_Deth = true;
	}
	return Is_Deth;
}

void Deth()
{
	EnemyX = 0.0f;
	EnemyY = 0.0f;
	//Is_Deth == false;
}

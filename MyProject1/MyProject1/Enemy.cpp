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

//float EnemyX;		//�G��X���W
//float EnemyY;		//�G��Y���W
//float EnemyR;		//�G�̔��a
bool Is_Deth;		//���S�t���O
Enemy enemy[3];
int HitCount;		//�q�b�g��

//�G�l�~�[����������
void Enemy_Initialize()
{
	switch (GetStageNum())
	{
	case 1:
		enemy[0] = 
		{0,980.0f,645.0f,25.0f};
		enemy[1] = 
		{1,1080.0f,645.0f,25.0f};
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

//�G�l�~�[�X�V����
void Enemy_Update()
{
	DamageCheck();
}

//�G�l�~�[�`�揈��
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

float GetEnemyX(int i)
{
	return enemy[i].x;
}
float GetEnemyY(int i)
{
	return enemy[i].y;
}
float GetEnemyR(int i)
{
	return enemy[i].r;
}

void DamageCheck()
{
	for (int i = 0; i < 3; i++)
	{
		if (HitCheck(i) == true)
		{
			if (enemy[i].type>0)
			{
				enemy[i].type--;
				if (GetType() == 1)
				{
					Bullet_Initialize();
				}
				else
				{
					HitCount = 1;
				}
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
	}
}

void Deth(int i)
{
	enemy[i].x = 10.0f;
	enemy[i].y = 10.0f;
}

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
#include "Enemy.h"
#include "Common.h"
#include "Bullet.h"
#include "Player.h"
#include "DxLib.h"
#include "math.h"
#include"StageSelectScene.h"

/****************************************************
*�^��`
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
*�ϐ��錾
*****************************************************/
bool Is_Deth;		//���S�t���O
Enemy enemy[3];
int HitCount;		//�q�b�g��

/****************************************************
*�G�l�~�[�F����������
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
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
*�G�l�~�[�F�X�V����
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void Enemy_Update()
{
	DamageCheck();
}

/****************************************************
*�G�l�~�[�F�`�揈��
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
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
*�G�l�~�[�FX���W�擾����
* ���@���F�Ȃ�
* �߂�l�FX���W
*****************************************************/
float GetEnemyX(int i)
{
	return enemy[i].x;
}
/****************************************************
*�G�l�~�[�FY���W�擾����
* ���@���F�Ȃ�
* �߂�l�FY���W
*****************************************************/
float GetEnemyY(int i)
{
	return enemy[i].y;
}
/****************************************************
*�G�l�~�[�F���a�擾����
* ���@���F�Ȃ�
* �߂�l�F���a
*****************************************************/
float GetEnemyR(int i)
{
	return enemy[i].r;
}
/****************************************************
*�G�l�~�[�F�_���[�W����
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
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
*�G�l�~�[�F���S����
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void Deth(int i)
{
	enemy[i].x = 10.0f;
	enemy[i].y = 10.0f;
}

/****************************************************
*�G�l�~�[�F�q�b�g�`�F�b�N����
* ���@���F�Ȃ�
* �߂�l�Fture=��������,false=�������Ă��Ȃ�
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
*�G�l�~�[�F�q�b�g�ݒ菈��
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void SetHit(int i)
{
	enemy[i].hit = 0;
}
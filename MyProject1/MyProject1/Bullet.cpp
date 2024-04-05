#include "Common.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "DxLib.h"
#include "math.h"


float BulletX;     //�o���b�g��X���W
float BulletY;     //�o���b�g��Y���W
float BulletR;     //�o���b�g�̔��a
float BulletSpeedX;     //�o���b�g��X���W�ړ�����
float BulletSpeedY;     //�o���b�g��Y���W�ړ�����
unsigned int BulletColor;     //�o���b�g�̐F
int ReflectionCount;	//���ˉ�
int BulletCount;	//���ˉ�
bool Is_Delet;		//���Ńt���O

//����������
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
		BulletColor = 0xffffff;     //�o���b�g�̐F
		break;
	case 2:
		BulletSpeedX = 30.0f;
		BulletSpeedY = 30.0f;
		BulletColor = 0xff;     //�o���b�g�̐F
		break;
	default:
		break;
	}
}


//�X�V����
void Bullet_Update()
{
	Bullet_Vector();
	DeletCheck();

	switch (GetType())
	{
	case 1:
		//���ˏ���
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
		//���ˏ���
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
}

//�`�揈��
void Bullet_Draw()
{
	DrawCircleAA(BulletX, BulletY, BulletR, 100, BulletColor, TRUE);
	DrawFormatString(450, 0, GetColor(255, 255, 255), "���ˉ񐔁F%d", ReflectionCount);
}


//�ړ�����
void Bullet_Vector()
{
	BulletX += BulletSpeedX * cos(GetRadian());
	BulletY -= BulletSpeedY * sin(GetRadian());
}

//���ˉ񐔎擾����
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

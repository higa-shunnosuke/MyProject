#include "Bullet.h"
#include "DxLib.h"
#include "math.h"
#include "Common.h"
#include "Player.h"


float BulletX;     //�o���b�g��X���W
float BulletY;     //�o���b�g��Y���W
float BulletR;     //�o���b�g�̔��a
float BulletSpeedX;     //�o���b�g��X���W�ړ�����
float BulletSpeedY;     //�o���b�g��Y���W�ړ�����
float g;				//�d��
unsigned int BulletColor1;     //�o���b�g�̐F
unsigned int BulletColor2;     //�o���b�g�̐F
unsigned int BulletColor3;     //�o���b�g�̐F
int ReflectionCount;	//���ˉ�

//����������
void Bullet_Initialize(float x, float y)
{
	BulletX = x;
	BulletY = y;
	BulletR = 20.0f;
	BulletSpeedX = 20.0f;
	BulletSpeedY = 20.0f;
	g = 1.0f;
	BulletColor1 = 0xffffff;     //�o���b�g�̐F
	BulletColor2 = 0xffff;     //�o���b�g�̐F
	BulletColor3 = 0xff;     //�o���b�g�̐F
	ReflectionCount = 0;	//���ˉ�
}


//�X�V����
void Bullet_Update(double r,int type)
{
	
	Bullet_Vector(r);

	switch (type)
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
		BulletSpeedX = 30.0f;
		BulletSpeedY = 30.0f;
		//���ˏ���
		if (BulletX + BulletR > SCREEN_RIGHT)
		{
			ReflectionCount=6;
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
	case 3:
		//���ˏ���
		if (BulletX + BulletR > SCREEN_RIGHT)
		{
			BulletSpeedX *= -1;
		}
		if (BulletX - BulletR < SCREEN_LEFT)
		{
			BulletSpeedX *= -1;
		}
		if (BulletY + BulletR > SCREEN_UNDER)
		{
			BulletSpeedY *= -1;
		}
		else
		{
			Fall();
		}
		if (BulletY - BulletR < SCREEN_UPPER)
		{
			BulletSpeedY *= -1;
		}
		break;
	default:
		break;
	}
}

//�`�揈��
void Bullet_Draw(int type)
{
	switch (type)
	{
	case 1:
		DrawCircleAA(BulletX, BulletY, BulletR, 100, BulletColor1, TRUE);
		break;
	case 2:
		DrawCircleAA(BulletX, BulletY, BulletR, 100, BulletColor2, TRUE);
		break;
	case 3:
		DrawCircleAA(BulletX, BulletY, BulletR, 100, BulletColor3, TRUE);
		break;
	default:
		break;
	}

	DrawFormatString(450, 50, GetColor(255, 255, 255), "���ˉ񐔁F%d", ReflectionCount);
	DrawFormatString(850, 50, GetColor(255, 255, 255), "x�F%f", BulletX);
	DrawFormatString(850, 100, GetColor(255, 255, 255), "y�F%f", BulletY);
}


//�ړ�����
void Bullet_Vector(double Radian)
{
	BulletX += BulletSpeedX * cos(Radian);
	BulletY -= BulletSpeedY * sin(Radian);
}

//��������
void Fall()
{
	BulletY += g;
	g++;
}

//���ˉ񐔎擾����
int GetBRC()
{
	return ReflectionCount;
}

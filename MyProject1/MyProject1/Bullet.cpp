#include "Common.h"
#include "Collinder.h"
#include "Bullet.h"
#include "Player.h"
#include "DxLib.h"
#include "math.h"


float BulletX;     //�o���b�g��X���W
float BulletY;     //�o���b�g��Y���W
float BulletR;     //�o���b�g�̔��a
float BulletSpeedX;     //�o���b�g��X���W�ړ�����
float BulletSpeedY;     //�o���b�g��Y���W�ړ�����
float g;				//�d��
unsigned int BulletColor;     //�o���b�g�̐F
int ReflectionCount;	//���ˉ�
bool Is_Delet;		//���Ńt���O

//����������
void Bullet_Initialize(float x, float y)
{
	BulletX = x;
	BulletY = y;
	BulletR = 20.0f;
	g = 1.0f;
	ReflectionCount = 0;	//���ˉ�
	Is_Delet = false;

	switch (GetType())
	{
	case 1:
		BulletSpeedX = 20.0f;
		BulletSpeedY = 20.0f;
		BulletColor = 0xffffff;     //�o���b�g�̐F
		break;

	case 2:
		BulletSpeedX = 20.0f;
		BulletSpeedY = 20.0f;
		BulletColor = 0xff;     //�o���b�g�̐F
		break;
	default:
		break;
	}
}


//�X�V����
void Bullet_Update(double r)
{
	
	Bullet_Vector(r);
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
	default:
		break;
	}
}

//�`�揈��
void Bullet_Draw()
{
	DrawCircleAA(BulletX, BulletY, BulletR, 100, BulletColor, TRUE);

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

bool DeletCheck()
{
	if (HitCheck())
	{
		Is_Delet = true;
	}
	return Is_Delet;
}

void Delet()
{

}
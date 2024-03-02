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
unsigned int BulletColor;     //�o���b�g�̐F
int ReflectionCount;	//���ˉ�

//����������
void Bullet_Initialize(float x, float y)
{
	BulletX = x;
	BulletY = y;
	BulletR = 20.0f;
	BulletSpeedX = 20.0f;
	BulletSpeedY = 20.0f;
	BulletColor = 0xffffff;     //�o���b�g�̐F
	ReflectionCount = 0;	//���ˉ�
}


//�X�V����
void Bullet_Update(double r)
{
	
	Bullet_Vector(r);

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

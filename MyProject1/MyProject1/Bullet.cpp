#include "Bullet.h"
#include "DxLib.h"
#include "math.h"
#include "Common.h"

//�����t���̃R���X�g���N�^
Bullet::Bullet(double x, double y, double r)
{
	location.x=x;
	location.y=y;
	area.height = 40.0f;
	area.width = 40.0f;
	BulletSpeedX = 10.0f;
	BulletSpeedY = 10.0f;
	BulletColor = 0x0;
	Radian = r;
	ReflectionCount = 0;
}

//�f�X�g���N�^
Bullet::~Bullet() {}

//�X�V����
void Bullet::Bullet_Update()
{
	Bullet_Vector();
	if (location.x + area.width/2 > SCREEN_RIGHT)
	{
		BulletSpeedX *= -1;
		ReflectionCount++;
	}
	if (location.x - area.width/2 < SCREEN_LEFT)
	{
		BulletSpeedX *= -1;
		ReflectionCount++;
	}
	if (location.y + area.height/2 > SCREEN_UNDER)
	{
		BulletSpeedY *= -1;
		ReflectionCount++;
	}
	if (location.y - area.height/2 < SCREEN_UPPER)
	{
		BulletSpeedY *= -1;
		ReflectionCount++;
	}
}

//�`�揈��
void Bullet::Bullet_Draw() const
{
	DrawCircleAA(location.x, location.y, 20, 100, GetColor(255, 0, 0), TRUE);
	DrawFormatString(450, 50, GetColor(255, 255, 255), "���ˉ񐔁F%d", ReflectionCount);
}


//�ړ�����
void Bullet::Bullet_Vector()
{
	location.x += BulletSpeedX * cos(Radian);
	location.y -= BulletSpeedY * sin(Radian);
}

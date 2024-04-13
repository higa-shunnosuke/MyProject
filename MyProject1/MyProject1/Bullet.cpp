#include "Common.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "DxLib.h"
#include "math.h"

/****************************************************
*�ϐ��錾
*****************************************************/
float BulletX;			//�o���b�g��X���W
float BulletY;			//�o���b�g��Y���W
float BulletR;			//�o���b�g�̔��a
float BulletSpeedX;		//�o���b�g��X���W�ړ����x
float BulletSpeedY;		//�o���b�g��Y���W�ړ����x
unsigned int BulletColor;	//�o���b�g�̐F
int ReflectionCount;	//���ˉ�
int BulletCount;		//���ˉ�
bool Is_Delet;			//���Ńt���O

/****************************************************
*�o���b�g�F����������
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void Bullet_Initialize()
{
	BulletX = GetPlayerX();
	BulletY = GetPlayerY();
	BulletR = 15.0f;
	ReflectionCount = 0;
	BulletCount = 0;
	Is_Delet = false;

	//���ꂼ��̃^�C�v�̒e�̏�����
	switch (GetType())
	{
	case 1:
		BulletSpeedX = 20.0f;
		BulletSpeedY = 20.0f;
		BulletColor = 0xffffff;
		break;
	case 2:
		BulletSpeedX = 30.0f;
		BulletSpeedY = 30.0f;
		BulletColor = 0xff;
		break;
	default:
		break;
	}
}

/****************************************************
*�o���b�g�F�X�V����
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void Bullet_Update()
{
	int reflection;

	Bullet_Vector();
	DeletCheck();

	switch (GetType())
	{
	case 1:
		//���˒e����
		for (int i = 0; i < 4; i++)
		{
			reflection = 0;

			if (BulletX + BulletR > SCREEN_RIGHT)
			{
				reflection = 1;
				break;
			}
			if (BulletX - BulletR < SCREEN_LEFT)
			{
				reflection = 1;
				break;
			}
			if (BulletY + BulletR > SCREEN_UNDER)
			{
				reflection = 2;
				break;
			}
			if (BulletY - BulletR < SCREEN_UPPER)
			{
				reflection = 2;
				break;
			}
		}
		if (reflection == 1)
		{
			BulletSpeedX *= -1;
			ReflectionCount++;
		}
		else if (reflection==2)
		{
			BulletSpeedY *= -1;
			ReflectionCount++;
		}
		break;
	case 2:
		//�ђʒe����
		for (int i = 0; i < 4; i++)
		{
			reflection = 0;

			if (BulletX + BulletR > SCREEN_RIGHT)
			{
				reflection = 1;
				break;
			}
			if (BulletX - BulletR < SCREEN_LEFT)
			{
				reflection = 1;
				break;
			}
			if (BulletY + BulletR > SCREEN_UNDER)
			{
				reflection = 1;
				break;
			}
			if (BulletY - BulletR < SCREEN_UPPER)
			{
				reflection = 1;
				break;
			}
		}
		if (reflection == 1)
		{
			ReflectionCount = 6;
			for (int i = 0; i < 3; i++)
			{
				SetHit(i);
			}
		}
		break;
	default:
		break;
	}
}

/****************************************************
*�o���b�g�F�`�揈��
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void Bullet_Draw()
{
	DrawCircleAA(BulletX, BulletY, BulletR, 100, BulletColor, TRUE);
	DrawFormatString(450, 0, GetColor(255, 255, 255), "���ˉ񐔁F%d", ReflectionCount);
}

/****************************************************
*�o���b�g�F�ړ�����
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void Bullet_Vector()
{
	BulletX += BulletSpeedX * cos(GetRadian());
	BulletY -= BulletSpeedY * sin(GetRadian());
}

/****************************************************
*�o���b�g�F�t���O�ݒ菈��
* ���@���Fflg(true=����,false=�����Ȃ�)
* �߂�l�F�Ȃ�
*****************************************************/
void SetDelet(int flg)
{
	Is_Delet = flg;
}

/****************************************************
*�o���b�g�F���ˉ񐔎擾����
* ���@���F�Ȃ�
* �߂�l�F���ˉ�
*****************************************************/
int GetBRC()
{
	return ReflectionCount;
}
/****************************************************
*�o���b�g�FX���W�擾����
* ���@���F�Ȃ�
* �߂�l�FX���W
*****************************************************/
float GetBulletX()
{
	return BulletX;
}
/****************************************************
*�o���b�g�FY���W�擾����
* ���@���F�Ȃ�
* �߂�l�FY���W
*****************************************************/
float GetBulletY()
{
	return BulletY;
}
/****************************************************
*�o���b�g�F���a�擾����
* ���@���F�Ȃ�
* �߂�l�F���a
*****************************************************/
float GetBulletR()
{
	return BulletR;
}
/****************************************************
*�o���b�g�F���Ńt���O�擾����
* ���@���F�Ȃ�
* �߂�l�F���Ńt���O
*****************************************************/
bool GetDelet()
{
	return Is_Delet;
}
/****************************************************
*�o���b�g�F�q�b�g���菈��
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void DeletCheck()
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
}

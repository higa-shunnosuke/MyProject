#include "Player.h"
#include "DxLib.h"
#include "math.h"
#include "Common.h"
#include "InputControl.h"
#include "Bullet.h"
#include "Guide.h"
#include"StageSelectScene.h"


float PlayerX;		//�v���C���[��X���W
float PlayerY;		//�v���C���[��Y���W
float PlayerR;		//�v���C���[�̔��a
double Radian;		//���W�A��
double Degree;		//�p�x
bool Is_Bullet;		//�o���b�g�𐶐��\���H
int type;			//�e�̃^�C�v
int count;			//�e�J�E���g

//����������
void Player_Initialize()
{
	switch (GetStageNum())
	{
	case 1:
		PlayerX = 300.0f;
		PlayerY = 645.0f;

		break;
	case 2:
		PlayerX = 300.0f;
		PlayerY = 645.0f;

		break;
	case 3:
		PlayerX = 300.0f;
		PlayerY = 645.0f;

		break;
	case 4:
		PlayerX = 300.0f;
		PlayerY = 645.0f;

		break;
	case 5:
		PlayerX = 300.0f;
		PlayerY = 645.0f;

		break;
	case 6:
		PlayerX = 300.0f;
		PlayerY = 645.0f;

		break;
	case 7:
		PlayerX = 300.0f;
		PlayerY = 645.0f;

		break;
	case 8:
		PlayerX = 300.0f;
		PlayerY = 645.0f;

		break;
	default:
		break;
	}
	
	PlayerR = 25.0f;
	Degree = 0.0f;
	Is_Bullet = true;
	type = 1;
	count = 0;
	//�o���b�g����������
	Bullet_Initialize();
	//�K�C�h����������
	Guide_Initialize();
}

//�v���C���[�X�V����
void Player_Update()
{

	Player_Control();

	//�^�C�v�ύX
	if (GetButtonDown(XINPUT_BUTTON_LEFT_SHOULDER) == TRUE && Is_Bullet == true)
	{
		if (type>1)
		{
			type--;
		}
		else
		{
			type = 2;
		}
	}
	if (GetButtonDown(XINPUT_BUTTON_RIGHT_SHOULDER) == TRUE && Is_Bullet == true)
	{
		if (type < 2)
		{
			type++;
		}
		else
		{
			type = 1;
		}
	}

	//�o���b�g����
	if (GetButtonDown(XINPUT_BUTTON_A) == TRUE && Is_Bullet == true)
	{
		SetBullet(false);
		//�o���b�g����������
		Bullet_Initialize();
		count++;
	}
	
	//�o���b�g�X�V����
	if (Is_Bullet==false)
	{
		Bullet_Update();
	}

	//�o���b�g��5�񔽎˂����������
	if (GetBRC() > 5)
	{
		SetBullet(true);

		//�o���b�g����������
		Bullet_Initialize();
	}
	else if (GetDelet()==true)
	{
		SetBullet(true);
	}
}

//�v���C���[�`�揈��
void Player_Draw()
{
	//�o���b�g�`�揈��
	Bullet_Draw();
	if (Is_Bullet==true)
	{
		Guide_Draw();
	}
	DrawCircleAA(PlayerX, PlayerY, PlayerR, 100, 0xffffff, TRUE);
	DrawFormatString(450, 50, GetColor(255, 255, 255), "type�F%d", type);
	DrawFormatString(450, 100, GetColor(255, 255, 255), "�J�E���g�F%d", count);
}


void Player_Control()
{
	if (GetButton(XINPUT_BUTTON_DPAD_LEFT) == TRUE && Is_Bullet == true)
	{
		PlayerX--;
	}
	if (GetButton(XINPUT_BUTTON_DPAD_RIGHT) == TRUE && Is_Bullet == true)
	{
		PlayerX++;
	}
	if (GetButton(XINPUT_BUTTON_DPAD_UP) == TRUE && Is_Bullet==true)
	{
		if (Degree >= 360)
		{
			Degree = 0;
		}
		else
		{
			Degree++;
		}
	}
	if (GetButton(XINPUT_BUTTON_DPAD_DOWN) == TRUE && Is_Bullet==true)
	{
		if (Degree <= 0)
		{
			Degree = 359;
		}
		else
		{
			Degree--;
		}
	}
	Radian = Degree * (M_PI / 180);
}

//�o���b�g�t���O�ݒ菈��(true=���Ă�,false=���ĂȂ�)
void SetBullet(bool flg)
{
	Is_Bullet = flg;

}

//�^�C�v�擾����
int GetType()
{
	return type;
}

float GetPlayerX()
{
	return PlayerX;
}
float GetPlayerY()
{
	return PlayerY;
}
float GetPlayerR()
{
	return PlayerR;
}
float GetRadian()
{
	return Radian;
}
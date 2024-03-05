#include "Player.h"
#include "DxLib.h"
#include "math.h"
#include "Common.h"
#include "InputControl.h"
#include "Bullet.h"
#include"StageSelectScene.h"


float PlayerX;		//�v���C���[��X���W
float PlayerY;		//�v���C���[��Y���W
float PlayerR;		//�v���C���[�̔��a
double Radian;		//���W�A��
double Degree;		//�p�x
bool Is_Bullet;		//�o���b�g�𐶐��\���H
int type;			//�e�̃^�C�v

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
	//�o���b�g����������
	Bullet_Initialize(PlayerX, PlayerY);
}

//�v���C���[�X�V����
void Player_Update()
{

	Player_Control();

	//�^�C�v�ύX
	if (GetButtonDown(XINPUT_BUTTON_LEFT_SHOULDER) == TRUE && Is_Bullet == TRUE)
	{
		if (type>1)
		{
			type--;
		}
		else
		{
			type = 2;
		}
		//�o���b�g����������
		Bullet_Initialize(PlayerX, PlayerY);
	}
	if (GetButtonDown(XINPUT_BUTTON_RIGHT_SHOULDER) == TRUE && Is_Bullet == TRUE)
	{
		if (type < 2)
		{
			type++;
		}
		else
		{
			type = 1;
		}
		//�o���b�g����������
		Bullet_Initialize(PlayerX, PlayerY);
	}


	//�o���b�g����
	if (GetButtonDown(XINPUT_BUTTON_A) == TRUE)
	{
		SetBullet(false);
	}
	
	//�o���b�g�X�V����
	if (Is_Bullet==false)
	{
		Bullet_Update(Radian);
	}

	//�o���b�g����������
	if (GetBRC() > 5)
	{
		Is_Bullet = true;

		//�o���b�g����������
		Bullet_Initialize(PlayerX, PlayerY);
	}
}

//�v���C���[�`�揈��
void Player_Draw()
{
	//�o���b�g�`�揈��
	if (Is_Bullet == false /*&& DeletCheck() == false*/)
	{
		Bullet_Draw();
	}

	DrawCircleAA(PlayerX, PlayerY, PlayerR, 100, 0xffffff, TRUE);
	DrawFormatString(450, 100, GetColor(255, 255, 255), "�� �F%f", Degree);
	DrawFormatString(450, 150, GetColor(255, 255, 255), "cos�F%f", cos(Radian));
	DrawFormatString(450, 200, GetColor(255, 255, 255), "sin�F%f", sin(Radian));
	DrawFormatString(450, 250, GetColor(255, 255, 255), "rad�F%f", Radian);
	DrawFormatString(450, 300, GetColor(255, 255, 255), "flg�F%d", Is_Bullet);
	DrawFormatString(450, 350, GetColor(255, 255, 255), "type�F%d", type);
	DrawFormatString(450, 400, GetColor(255, 255, 255), "y�F%f", PlayerY);
}


void Player_Control()
{
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
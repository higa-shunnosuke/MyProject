#include "Player.h"
#include "DxLib.h"
#include "math.h"
#include "Common.h"
#include "InputControl.h"
#include "Bullet.h"
#include "Guide.h"
#include"StageSelectScene.h"

/****************************************************
*�ϐ��錾
*****************************************************/
float PlayerX;		//�v���C���[��X���W
float PlayerY;		//�v���C���[��Y���W
float PlayerR;		//�v���C���[�̔��a
double Radian;		//���W�A��
double Degree;		//�p�x
bool Is_Bullet;		//�o���b�g�𐶐��\���H(true:�\,false:�s�\)
int type;			//�e�̃^�C�v
int count;			//�e�J�E���g

/****************************************************
*�v���C���[�F����������
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
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
	
	Bullet_Initialize();	//�o���b�g����������
	Guide_Initialize();		//�K�C�h����������
}

/****************************************************
*�v���C���[�F�X�V����
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void Player_Update()
{
	//�^�C�v�ύX
	if (Is_Bullet == true)	//���ˉ\�Ȃ�
	{
		Player_Control();	//���ˊp�x���쏈��

		//���V�����_�[�������ꂽ��Atype�����炷
		if (GetButtonDown(XINPUT_BUTTON_LEFT_SHOULDER) == TRUE)
		{
			if (type > 1)
			{
				type--;
			}
			else
			{
				type = 2;
			}
		}
		//�E�V�����_�[�������ꂽ��Atype�𑝂₷
		if (GetButtonDown(XINPUT_BUTTON_RIGHT_SHOULDER) == TRUE)
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
		//A�{�^���������ꂽ��A�e�𔭎�
		if (GetButtonDown(XINPUT_BUTTON_A) == TRUE)
		{
			SetBullet(false);	//���˃t���O��false�ɂ���
			
			Bullet_Initialize();	//�o���b�g����������
		}
	}
	else	//�e�����˒��Ȃ�
	{
		Bullet_Update();	//�o���b�g�X�V����
	}

	//�e��5�񔽎˂����������
	if (GetBRC() > 5)
	{
		SetBullet(true);	//���˃t���O��true�ɂ���

		//�o���b�g����������
		Bullet_Initialize();
	}
	//�e�����̂ɓ�����Ə�����
	else if (GetDelet()==true)
	{
		SetBullet(true);	//���˃t���O��true�ɂ���
	}
}

/****************************************************
*�v���C���[�F�`�揈��
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void Player_Draw()
{
	Bullet_Draw();	//�o���b�g�`�揈��

	//�e�����˒��Ȃ�K�C�h����`��
	if (Is_Bullet==true)
	{
		Guide_Draw();
	}
	DrawCircleAA(PlayerX, PlayerY, PlayerR, 100, 0xffffff, TRUE);
	DrawFormatString(450, 50, GetColor(255, 255, 255), "type�F%d", type);
	DrawFormatString(450, 100, GetColor(255, 255, 255), "�J�E���g�F%d", count);
}

/****************************************************
*�v���C���[�F���ˊp�x���쏈��
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void Player_Control()
{
	if (GetButton(XINPUT_BUTTON_DPAD_LEFT) == TRUE)
	{
		PlayerX--;
	}
	if (GetButton(XINPUT_BUTTON_DPAD_RIGHT) == TRUE)
	{
		PlayerX++;
	}
	//��{�^������������A�p�x��傫������
	if (GetButton(XINPUT_BUTTON_DPAD_UP) == TRUE)
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
	//���{�^������������A�p�x������������
	if (GetButton(XINPUT_BUTTON_DPAD_DOWN) == TRUE)
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
	//�p�x�����W�A���ɕϊ�
	Radian = Degree * (M_PI / 180);
}

/****************************************************
*�v���C���[�F�t���O�ݒ菈��
* ���@���Fflg(true=���Ă�,false=���ĂȂ�)
* �߂�l�F�Ȃ�
*****************************************************/
void SetBullet(bool flg)
{
	Is_Bullet = flg;
}

/****************************************************
*�v���C���[�F�^�C�v�擾����
* ���@���F�Ȃ�
* �߂�l�Ftype(���˒eor�ђʒe)
*****************************************************/
int GetType()
{
	return type;
}
/****************************************************
*�v���C���[�FX���W�擾����
* ���@���F�Ȃ�
* �߂�l�FX���W
*****************************************************/
float GetPlayerX()
{
	return PlayerX;
}
/****************************************************
*�v���C���[�FY���W�擾����
* ���@���F�Ȃ�
* �߂�l�FY���W
*****************************************************/
float GetPlayerY()
{
	return PlayerY;
}
/****************************************************
*�v���C���[�F���a�擾����
* ���@���F�Ȃ�
* �߂�l�F���a
*****************************************************/
float GetPlayerR()
{
	return PlayerR;
}
/****************************************************
*�v���C���[�F���W�A���擾����
* ���@���F�Ȃ�
* �߂�l�F���W�A��
*****************************************************/
float GetRadian()
{
	return Radian;
}
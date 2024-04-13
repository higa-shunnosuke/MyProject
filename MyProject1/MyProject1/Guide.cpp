#include "Guide.h"
#include "Player.h"
#include "Enemy.h"
#include "DxLib.h"
#include "math.h"

/****************************************************
*�ϐ��錾
*****************************************************/
float GuideX;		//���C����X
float GuideY;		//���C����Y
float GuideR;		//���C���̕�
float Guidelength;	//���C���̒���
unsigned int GuideColor;	//���C���̐F
int Is_guide;

/****************************************************
*�K�C�h�F����������
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void Guide_Initialize()
{
	GuideX = 0.0f;
	GuideY = 0.0f;
	GuideR = 1.0f;
	Guidelength = 1300.f;
	GuideColor = 0x00ff00;
	Is_guide=0;
}

/****************************************************
*�K�C�h�F�`�揈��
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void Guide_Draw()
{
	Is_guide = 0;
	for (float i = 0; i < Guidelength; i++)
	{
		GuideX = GetPlayerX() + (cos(-GetRadian())) * i;
		GuideY = GetPlayerY() + (sin(-GetRadian())) * i;
		DrawCircleAA(GuideX, GuideY, GuideR, 100, GuideColor, TRUE);
		for (int i = 0; i < 3; i++)
		{
			if (LengthCheck(i) == true)
			{
				Is_guide=1;
				break;
			}
		}
		if (Is_guide==1)
		{
			break;
		}
	}
}

/****************************************************
*�K�C�h�F�������菈��
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
bool LengthCheck(int i)
{
	int ret = false;
	double x = pow(GuideX - GetEnemyX(i), 2);
	double y = pow(GuideY - GetEnemyY(i), 2);
	double r = pow( + GetEnemyR(i), 2);

	if (x + y < r)
	{
		ret = true;
	}

	return ret;
}
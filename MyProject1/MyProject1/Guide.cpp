#include "Guide.h"
#include "Player.h"
#include "Enemy.h"
#include "DxLib.h"
#include "math.h"


float GuideX;		//ラインのX
float GuideY;		//ラインのY
float GuideR;		//ラインの幅
float Guidelength;	//ラインの長さ
unsigned int GuideColor;		//ラインの色

void Guide_Initialize()
{
	GuideX = 0.0f;
	GuideY = 0.0f;
	GuideR = 1.0f;
	Guidelength = 1300.f;
	GuideColor = 0x00ff00;
}

void Guide_Draw()
{
	for (float i = 0; i < Guidelength; i++)
	{
		GuideX = GetPlayerX() + (cos(-GetRadian())) * i;
		GuideY = GetPlayerY() + (sin(-GetRadian())) * i;
		DrawCircleAA(GuideX, GuideY, GuideR, 100, GuideColor, TRUE);
		if (LengthCheck() == true)
		{
			break;
		}
	}
	//DrawFormatString(850, 250, GetColor(255, 255, 255), "Line");
}

bool LengthCheck()
{
	int ret = false;
	double x = pow(GuideX - GetEnemyX(), 2);
	double y = pow(GuideY - GetEnemyY(), 2);
	double r = pow( + GetEnemyR(), 2);

	if (x + y < r)
	{
		ret = true;
	}

	return ret;
}
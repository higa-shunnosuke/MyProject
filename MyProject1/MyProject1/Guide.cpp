#include "Guide.h"
#include "Player.h"
#include "DxLib.h"
#include "math.h"


float LineR;		//���C���̕�
float Linelength;	//���C���̒���
unsigned int LineColor;		//���C���̐F

void Guide_Initialize()
{
	LineR = 5.0f;
	Linelength = 1300.f;
	LineColor = 0x00ff00;
}

void Guide_Draw()
{
	for (float i = 0; i < Linelength; i++)
	{
		DrawCircleAA(GetPlayerX() + (cos(-GetRadian())) * i, GetPlayerY() + (sin(-GetRadian())) * i, LineR, 100, LineColor, TRUE);
	}
	//DrawFormatString(850, 250, GetColor(255, 255, 255), "Line");

}
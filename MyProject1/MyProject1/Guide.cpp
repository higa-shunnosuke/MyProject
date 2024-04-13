#include "Guide.h"
#include "Player.h"
#include "Enemy.h"
#include "DxLib.h"
#include "math.h"

/****************************************************
*変数宣言
*****************************************************/
float GuideX;		//ラインのX
float GuideY;		//ラインのY
float GuideR;		//ラインの幅
float Guidelength;	//ラインの長さ
unsigned int GuideColor;	//ラインの色
int Is_guide;

/****************************************************
*ガイド：初期化処理
* 引　数：なし
* 戻り値：なし
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
*ガイド：描画処理
* 引　数：なし
* 戻り値：なし
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
*ガイド：長さ判定処理
* 引　数：なし
* 戻り値：なし
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
#include "Player.h"
#include "DxLib.h"
#include "math.h"
#include "Common.h"
#include "InputControl.h"
#include "Bullet.h"
#include "Guide.h"
#include"StageSelectScene.h"


float PlayerX;		//プレイヤーのX座標
float PlayerY;		//プレイヤーのY座標
float PlayerR;		//プレイヤーの半径
double Radian;		//ラジアン
double Degree;		//角度
bool Is_Bullet;		//バレットを生成可能か？
int type;			//弾のタイプ
int count;			//弾カウント

//初期化処理
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
	//バレット初期化処理
	Bullet_Initialize();
	//ガイド初期化処理
	Guide_Initialize();
}

//プレイヤー更新処理
void Player_Update()
{

	Player_Control();

	//タイプ変更
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

	//バレット発射
	if (GetButtonDown(XINPUT_BUTTON_A) == TRUE && Is_Bullet == true)
	{
		SetBullet(false);
		//バレット初期化処理
		Bullet_Initialize();
		count++;
	}
	
	//バレット更新処理
	if (Is_Bullet==false)
	{
		Bullet_Update();
	}

	//バレットが5回反射したら消える
	if (GetBRC() > 5)
	{
		SetBullet(true);

		//バレット初期化処理
		Bullet_Initialize();
	}
	else if (GetDelet()==true)
	{
		SetBullet(true);
	}
}

//プレイヤー描画処理
void Player_Draw()
{
	//バレット描画処理
	Bullet_Draw();
	if (Is_Bullet==true)
	{
		Guide_Draw();
	}
	DrawCircleAA(PlayerX, PlayerY, PlayerR, 100, 0xffffff, TRUE);
	DrawFormatString(450, 50, GetColor(255, 255, 255), "type：%d", type);
	DrawFormatString(450, 100, GetColor(255, 255, 255), "カウント：%d", count);
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

//バレットフラグ設定処理(true=撃てる,false=撃てない)
void SetBullet(bool flg)
{
	Is_Bullet = flg;

}

//タイプ取得処理
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
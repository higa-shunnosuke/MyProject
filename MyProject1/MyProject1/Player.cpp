#include "Player.h"
#include "DxLib.h"
#include "math.h"
#include "Common.h"
#include "InputControl.h"
#include "Bullet.h"


float PlayerX;     //バレットのX座標
float PlayerY;     //バレットのY座標
float PlayerR;     //バレットの半径
double Radian;			//ラジアン
double Degree;			//角度
bool Is_Bullet;			//バレットを生成可能か？

//初期化処理
void Player_Initialize()
{
	PlayerX=640.0f;
	PlayerY=480.0f;
	PlayerR = 25.0f;
	Is_Bullet = true;

	//バレット初期化処理
	Bullet_Initialize(PlayerX, PlayerY);
}

//プレイヤー更新処理
void Player_Update()
{

	Player_Control();

	//バレット発射
	if (GetButtonDown(XINPUT_BUTTON_A) == TRUE)
	{
		SetBullet(false);
	}

	//バレット更新処理
	if (Is_Bullet==false)
	{
		Bullet_Update(Radian);
	}

	//バレット初期化処理
	if (GetBRC() > 5)
	{
		Is_Bullet = true;

		Bullet_Initialize(PlayerX, PlayerY);
	}
}

//プレイヤー描画処理
void Player_Draw()
{
	//バレット描画処理
	if (Is_Bullet == false)
	{
		Bullet_Draw();
	}

	DrawCircleAA(PlayerX, PlayerY, PlayerR, 100, 0xffffff, TRUE);
	DrawFormatString(450, 100, GetColor(255, 255, 255), "θ ：%f", Degree);
	DrawFormatString(450, 150, GetColor(255, 255, 255), "cos：%f", cos(Radian));
	DrawFormatString(450, 200, GetColor(255, 255, 255), "sin：%f", sin(Radian));
	DrawFormatString(450, 250, GetColor(255, 255, 255), "rad：%f", Radian);
	DrawFormatString(450, 300, GetColor(255, 255, 255), "flg：%d", Is_Bullet);
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

//バレットフラグ設定処理(true=撃てる,false=撃てない)
void SetBullet(bool flg)
{
	Is_Bullet = flg;

}
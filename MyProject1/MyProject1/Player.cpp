#include "Player.h"
#include "DxLib.h"
#include "math.h"
#include "Common.h"
#include "InputControl.h"
#include "Bullet.h"
#include "Guide.h"
#include"StageSelectScene.h"

/****************************************************
*変数宣言
*****************************************************/
float PlayerX;		//プレイヤーのX座標
float PlayerY;		//プレイヤーのY座標
float PlayerR;		//プレイヤーの半径
double Radian;		//ラジアン
double Degree;		//角度
bool Is_Bullet;		//バレットを生成可能か？(true:可能,false:不可能)
int type;			//弾のタイプ
int count;			//弾カウント

/****************************************************
*プレイヤー：初期化処理
* 引　数：なし
* 戻り値：なし
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
	
	Bullet_Initialize();	//バレット初期化処理
	Guide_Initialize();		//ガイド初期化処理
}

/****************************************************
*プレイヤー：更新処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void Player_Update()
{
	//タイプ変更
	if (Is_Bullet == true)	//発射可能なら
	{
		Player_Control();	//発射角度操作処理

		//左ショルダーが押されたら、typeを減らす
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
		//右ショルダーが押されたら、typeを増やす
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
		//Aボタンが押されたら、弾を発射
		if (GetButtonDown(XINPUT_BUTTON_A) == TRUE)
		{
			SetBullet(false);	//発射フラグをfalseにする
			
			Bullet_Initialize();	//バレット初期化処理
		}
	}
	else	//弾が発射中なら
	{
		Bullet_Update();	//バレット更新処理
	}

	//弾が5回反射したら消える
	if (GetBRC() > 5)
	{
		SetBullet(true);	//発射フラグをtrueにする

		//バレット初期化処理
		Bullet_Initialize();
	}
	//弾が物体に当たると消える
	else if (GetDelet()==true)
	{
		SetBullet(true);	//発射フラグをtrueにする
	}
}

/****************************************************
*プレイヤー：描画処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void Player_Draw()
{
	Bullet_Draw();	//バレット描画処理

	//弾が発射中ならガイド線を描画
	if (Is_Bullet==true)
	{
		Guide_Draw();
	}
	DrawCircleAA(PlayerX, PlayerY, PlayerR, 100, 0xffffff, TRUE);
	DrawFormatString(450, 50, GetColor(255, 255, 255), "type：%d", type);
	DrawFormatString(450, 100, GetColor(255, 255, 255), "カウント：%d", count);
}

/****************************************************
*プレイヤー：発射角度操作処理
* 引　数：なし
* 戻り値：なし
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
	//上ボタンを押したら、角度を大きくする
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
	//下ボタンを押したら、角度を小さくする
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
	//角度をラジアンに変換
	Radian = Degree * (M_PI / 180);
}

/****************************************************
*プレイヤー：フラグ設定処理
* 引　数：flg(true=撃てる,false=撃てない)
* 戻り値：なし
*****************************************************/
void SetBullet(bool flg)
{
	Is_Bullet = flg;
}

/****************************************************
*プレイヤー：タイプ取得処理
* 引　数：なし
* 戻り値：type(反射弾or貫通弾)
*****************************************************/
int GetType()
{
	return type;
}
/****************************************************
*プレイヤー：X座標取得処理
* 引　数：なし
* 戻り値：X座標
*****************************************************/
float GetPlayerX()
{
	return PlayerX;
}
/****************************************************
*プレイヤー：Y座標取得処理
* 引　数：なし
* 戻り値：Y座標
*****************************************************/
float GetPlayerY()
{
	return PlayerY;
}
/****************************************************
*プレイヤー：半径取得処理
* 引　数：なし
* 戻り値：半径
*****************************************************/
float GetPlayerR()
{
	return PlayerR;
}
/****************************************************
*プレイヤー：ラジアン取得処理
* 引　数：なし
* 戻り値：ラジアン
*****************************************************/
float GetRadian()
{
	return Radian;
}
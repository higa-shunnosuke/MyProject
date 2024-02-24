#pragma once
#include"DxLib.h"

/******************************************
* マクロ定義
******************************************/
#define _USE_MATH_DEFINES	//数値演算定数
#include <math.h>

//画面の設定
#define SCREEN_WIDTH (1280)
#define SCREEN_HEIGHT (720)
#define SCREEN_COLOBIT (32)
#define FONT_SIZE (20)

#define SCREEN_LEFT (0)
#define SCREEN_RIGHT (1280)
#define SCREEN_UPPER (0)
#define SCREEN_UNDER (720)

/****************************************************
*入力制御機能：ゲーム終了用のボタン判定処理
* 引　数：無し
* 戻り値：TRUE（押した）,FALSE（押してない)
*****************************************************/
int GetExitButton(void)
{
	int ret = FALSE;

	if ((CheckHitKey(KEY_INPUT_ESCAPE) == TRUE))
	{
		ret = TRUE;
	}
	return ret;
}
#include "GameMainScene.h"
#include "StageSelectScene.h"
#include "SceneManager.h"
#include "InputControl.h"
#include "Common.h"
#include "Player.h"
#include "Enemy.h"
#include "DxLib.h"

/****************************************************
*マクロ定義
*****************************************************/
#define WALL (50)

/****************************************************
*変数宣言
*****************************************************/
int Is_Restart;		//リスタートするか？

/****************************************************
*ゲームメイン画面：初期化処理
* 引　数：なし
* 戻り値：エラー情報（-1;異常有-1以外;正常終了）
*****************************************************/
int GameMainScene_Initialize()
{
	Is_Restart = 1;

	Player_Initialize();
	Enemy_Initialize();
	
	int ret = 0;

	return ret;
}

/****************************************************
*ゲームメイン画面：更新処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void GameMainScene_Update()
{
	if(Is_Restart == 1)
	{
		Player_Update();
		Enemy_Update();
		if (GetButtonDown(XINPUT_BUTTON_START) == TRUE)
		{
			Is_Restart = 0;
		}
	}
	else
	{
		if (GetButtonDown(XINPUT_BUTTON_START) == TRUE)
		{
			Is_Restart = 1;
		}
		if (GetButtonDown(XINPUT_BUTTON_B) == TRUE)
		{
			GameMainScene_Initialize();
		}
		if (GetButtonDown(XINPUT_BUTTON_A) == TRUE)
		{
			Change_Scene(E_STAGESELECT);
		}
	}
}

/****************************************************
*ゲームメイン画面：初期化処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void GameMainScene_Draw()
{
	SetFontSize(50);
	DrawBox(SCREEN_LEFT,SCREEN_UPPER,SCREEN_RIGHT, SCREEN_UNDER,0x0,true);
	DrawFormatString(0, 0, 0xffffff,"ステージ%d", GetStageNum());
	if (Is_Restart == 0)
	{
		DrawString(100, 100, "PAUSE", GetColor(255, 255, 255));
	}
	Player_Draw();
	Enemy_Draw();
}
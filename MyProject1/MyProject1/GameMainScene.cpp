#include "GameMainScene.h"
#include "StageSelectScene.h"
#include "SceneManager.h"
#include "InputControl.h"
#include "Common.h"
#include "Player.h"
#include "Enemy.h"
#include "DxLib.h"

/****************************************************
*型定義
*****************************************************/
enum
{
	E_GAMEMAIN_BGM,
	E_GAMEMAIN_SE_CURSOR,
	E_GAMEMAIN_SE_SELECT,
	E_SOUND_MAX
};

/****************************************************
*変数宣言
*****************************************************/
int Is_Pause;		//ポーズするか？(0:する,1:しない)
static int sounds[E_SOUND_MAX];

/****************************************************
*ゲームメイン画面：初期化処理
* 引　数：なし
* 戻り値：エラー情報（-1;異常有-1以外;正常終了）
*****************************************************/
int GameMainScene_Initialize()
{
	Is_Pause = 1;		//ポーズしない

	Player_Initialize();	//プレイヤーの初期化
	Enemy_Initialize();		//エネミーの初期化
	
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
	//ポーズ画面ではないとき
	if(Is_Pause == 1)
	{
		Enemy_Update();		//エネミーの更新
		Player_Update();	//プレイヤーの更新

		//スタートボタンが押されたら、ポーズする
		if (GetButtonDown(XINPUT_BUTTON_START) == TRUE)
		{
			Is_Pause = 0;
		}
	}
	//ポーズ画面のとき
	else
	{
		//スタートボタンが押されたら、ポーズを解除
		if (GetButtonDown(XINPUT_BUTTON_START) == TRUE)
		{
			Is_Pause = 1;
		}
		//Bボタンが押されたら、リスタートする
		if (GetButtonDown(XINPUT_BUTTON_B) == TRUE)
		{
			GameMainScene_Initialize();
		}
		//Aボタンが押されたら、ステージ選択に戻る
		if (GetButtonDown(XINPUT_BUTTON_A) == TRUE)
		{
			Change_Scene(E_STAGESELECT);
		}
	}
}

/****************************************************
*ゲームメイン画面：描画処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void GameMainScene_Draw()
{
	SetFontSize(50);
	//背景の描画
	DrawBox(SCREEN_LEFT,SCREEN_UPPER,SCREEN_RIGHT, SCREEN_UNDER,0x0,true);
	//ステージ名の描画
	DrawFormatString(0, 0, 0xffffff,"ステージ%d", GetStageNum());
	//ポーズ画面の描画
	if (Is_Pause == 0)
	{
		DrawString(100, 100, "PAUSE", GetColor(255, 255, 255));
	}

	Player_Draw();	//プレイヤーの描画
	Enemy_Draw();	//プレイヤーの描画
}
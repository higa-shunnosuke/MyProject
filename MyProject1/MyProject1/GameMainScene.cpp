#include "GameMainScene.h"
#include "StageSelectScene.h"
#include "SceneManager.h"
#include "InputControl.h"
#include "Common.h"
#include "Player.h"
#include "DxLib.h"

/****************************************************
*マクロ定義
*****************************************************/
#define WALL (50)
/****************************************************
*型定義
*****************************************************/

/****************************************************
*グローバル変数宣言
*****************************************************/
static int stage_number;
/****************************************************
*プロトタイプ宣言
*****************************************************/

/****************************************************
*タイトル画面：初期化処理
* 引　数：なし
* 戻り値：エラー情報（-1;異常有-1以外;正常終了）
*****************************************************/
int GameMainScene_Initialize()
{
		Player_Initialize();
	
	int ret = 0;

	return ret;
}

/****************************************************
*タイトル画面：更新処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void GameMainScene_Update()
{
	Player_Update();

	if (GetButtonDown(XINPUT_BUTTON_START) == TRUE)
	{
		Change_Scene(E_PAUSE);
	}
}

/****************************************************
*タイトル画面：初期化処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void GameMainScene_Draw()
{
	SetFontSize(50);
	DrawBox(0,0,SCREEN_WIDTH, SCREEN_HEIGHT,0xffffff,true);
	DrawBox(SCREEN_LEFT,SCREEN_UPPER,SCREEN_RIGHT, SCREEN_UNDER,0x0,true);
	DrawFormatString(0, 0, 0x0,"ステージ%d", GetStageNum());
	Player_Draw();

}
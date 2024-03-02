#include "GameMainScene.h"
#include "SceneManager.h"
#include "InputControl.h"
#include "DxLib.h"
#include "Common.h"
#include "Player.h"

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
int GameMainScene_Initialize(void)
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
void GameMainScene_Update(int s_n)
{
	Player_Update();

	stage_number = s_n;

	if (GetButtonDown(XINPUT_BUTTON_START) == TRUE)
	{
		Change_Scene(E_PAUSE,0);
	}
}

/****************************************************
*タイトル画面：初期化処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void GameMainScene_Draw(void)
{
	SetFontSize(50);
	DrawBox(0,0,SCREEN_WIDTH, SCREEN_HEIGHT,0xffffff,true);
	DrawBox(SCREEN_LEFT,SCREEN_UPPER,SCREEN_RIGHT, SCREEN_UNDER,0x0,true);
	DrawFormatString(0, 0, 0x0,"ステージ%d", stage_number);
	Player_Draw();

}
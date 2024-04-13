#include "GameoverScene.h"
#include "SceneManager.h"
#include "InputControl.h"
#include "DxLib.h"

/****************************************************
*ゲームオーバー画面：初期化処理
* 引　数：なし
* 戻り値：エラー情報（-1;異常有-1以外;正常終了）
*****************************************************/
int GameoverScene_Initialize(void)
{
	int ret = 0;

	return ret;
}

/****************************************************
*ゲームオーバー画面：更新処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void GameoverScene_Update(void)
{
	if (GetButtonDown(XINPUT_BUTTON_B) == TRUE)
	{
		Change_Scene(E_TITLE);
	}
}

/****************************************************
*ゲームオーバー画面：初期化処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void GameoverScene_Draw(void)
{
	SetFontSize(50);
	DrawString(100, 100, "GAMEOVER", GetColor(255, 255, 255));
}
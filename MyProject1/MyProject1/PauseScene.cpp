#include "PauseScene.h"
#include "SceneManager.h"
#include "InputControl.h"
#include "DxLib.h"

/****************************************************
*タイトル画面：初期化処理
* 引　数：なし
* 戻り値：エラー情報（-1;異常有-1以外;正常終了）
*****************************************************/
int PauseScene_Initialize(void)
{
	int ret = 0;

	return ret;
}

/****************************************************
*タイトル画面：更新処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void PauseScene_Update(void)
{
	if (GetButtonDown(XINPUT_BUTTON_START) == TRUE)
	{
		Change_Scene(E_GAMEMAIN);
	}
	if (GetButtonDown(XINPUT_BUTTON_B) == TRUE)
	{
		Change_Scene(E_GAMEMAIN);
	}
	if (GetButtonDown(XINPUT_BUTTON_A) == TRUE)
	{
		Change_Scene(E_STAGESELECT);
	}
}

/****************************************************
*タイトル画面：初期化処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void PauseScene_Draw(void)
{
	SetFontSize(50);
	DrawString(100, 100, "PAUSE", GetColor(255, 255, 255));
}
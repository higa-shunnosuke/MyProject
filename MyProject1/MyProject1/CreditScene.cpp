#include "CreditScene.h"
#include "SceneManager.h"
#include "InputControl.h"
#include "DxLib.h"

/****************************************************
*クレジット画面：初期化処理
* 引　数：なし
* 戻り値：エラー情報（-1;異常有-1以外;正常終了）
*****************************************************/
int CreditScene_Initialize(void)
{
	int ret = 0;

	return ret;
}

/****************************************************
*クレジット画面：更新処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void CreditScene_Update(void)
{
	if (GetButtonDown(XINPUT_BUTTON_B) == TRUE)
	{
		Change_Scene(E_TITLE);
	}
}

/****************************************************
*クレジット画面：初期化処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void CreditScene_Draw(void)
{
	SetFontSize(50);
	DrawString(100, 100, "Credit", GetColor(255, 255, 255));
}
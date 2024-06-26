#include "TitleScene.h"
#include "SceneManager.h"
#include"InputControl.h"
#include "DxLib.h"

/****************************************************
*型定義
*****************************************************/
enum
{
	E_TITLE_BGM,
	E_TITLE_SE_CURSOR,
	E_TITLE_SE_SELECT,
	E_SOUND_MAX
};

/****************************************************
*グローバル変数宣言
*****************************************************/
static int cursor_number;
static int sounds[E_SOUND_MAX];

/****************************************************
*タイトル画面：初期化処理
* 引　数：なし
* 戻り値：エラー情報（-1;異常有-1以外;正常終了）
*****************************************************/
int TitleScene_Initialize(void)
{
	int ret = 0;

	//cursor_number = 0;

	sounds[E_TITLE_BGM] = LoadSoundMem("sounds/BGM041.ogg");
	sounds[E_TITLE_SE_CURSOR] = LoadSoundMem("sounds/SE1.mp3");
	sounds[E_TITLE_SE_SELECT] = LoadSoundMem("sounds/SE2.mp3");

	ChangeVolumeSoundMem(120, sounds[E_TITLE_SE_CURSOR]);
	ChangeVolumeSoundMem(80, sounds[E_TITLE_SE_SELECT]);

	for (int i = 0; i < E_SOUND_MAX; i++)
	{
		if (sounds[i] == -1)
		{
			ret = -1;
			break;
		}
	}
	return ret;
}

/****************************************************
*タイトル画面：更新処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void TitleScene_Update(void)
{
	//BGMが流れてないときに再生
	if (CheckSoundMem(sounds[E_TITLE_BGM])!=TRUE)
	{
		PlaySoundMem(sounds[E_TITLE_BGM], DX_PLAYTYPE_BACK, FALSE);
	}

	if (GetButtonDown(XINPUT_BUTTON_A) == TRUE)
	{
		StopSoundMem(sounds[E_TITLE_BGM]);
		PlaySoundMem(sounds[E_TITLE_SE_SELECT], DX_PLAYTYPE_BACK, FALSE);
		switch (cursor_number)
		{
		case 0:
			Change_Scene(E_STAGESELECT);
			break;
		case 1:
			Change_Scene(E_HELP);
			break;
		case 2:
			Change_Scene(E_CREDIT);
			break;
		case 3:
		default:
			Change_Scene(E_END);
			break;
		}
	}

	if (GetButtonDown(XINPUT_BUTTON_DPAD_UP) == TRUE)
	{
		PlaySoundMem(sounds[E_TITLE_SE_CURSOR], DX_PLAYTYPE_NORMAL, FALSE);
		if (cursor_number <= 0)
		{
			cursor_number = 3;
		}
		else
		{
			cursor_number--;
		}
	}

	if (GetButtonDown(XINPUT_BUTTON_DPAD_DOWN) == TRUE)
	{
		PlaySoundMem(sounds[E_TITLE_SE_CURSOR], DX_PLAYTYPE_NORMAL, FALSE);
		if (cursor_number >= 3)
		{
			cursor_number = 0;
		}
		else
		{
			cursor_number++;
		}
	}
}

/****************************************************
*タイトル画面：描画処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void TitleScene_Draw(void)
{
	SetFontSize(50);
	DrawString(100, 100, "タイトル", GetColor(255, 255, 255));
	switch (cursor_number)
	{
	case 0:
		DrawString(100, 300, "スタート", GetColor(0, 255, 0));
		DrawString(100, 350, "ヘルプ", GetColor(255, 255, 255));
		DrawString(100, 400, "クレジット", GetColor(255, 255, 255));
		DrawString(100, 450, "エンド", GetColor(255, 255, 255));
		break;
	case 1:
		DrawString(100, 300, "スタート", GetColor(255, 255, 255));
		DrawString(100, 350, "ヘルプ", GetColor(0, 255, 0));
		DrawString(100, 400, "クレジット", GetColor(255, 255, 255));
		DrawString(100, 450, "エンド", GetColor(255, 255, 255));
		break;
	case 2:
		DrawString(100, 300, "スタート", GetColor(255, 255, 255));
		DrawString(100, 350, "ヘルプ", GetColor(255, 255, 255));
		DrawString(100, 400, "クレジット", GetColor(0, 255, 0));
		DrawString(100, 450, "エンド", GetColor(255, 255, 255));
		break;
	default:
		DrawString(100, 300, "スタート", GetColor(255, 255, 255));
		DrawString(100, 350, "ヘルプ", GetColor(255, 255, 255));
		DrawString(100, 400, "クレジット", GetColor(255, 255, 255));
		DrawString(100, 450, "エンド", GetColor(0, 255, 0));
		break;
	}

	DrawTriangle(60, 310 + (cursor_number * 50), 60, 340 + (cursor_number * 50), 90, 325 + (cursor_number * 50), GetColor(0, 255, 0), TRUE);
}

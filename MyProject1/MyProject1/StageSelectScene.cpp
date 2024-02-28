#include "StageSelectScene.h"
#include "SceneManager.h"
#include"InputControl.h"
#include "DxLib.h"


/****************************************************
*マクロ定義
*****************************************************/

/****************************************************
*型定義
*****************************************************/
enum
{
	E_STAGE_BGM,
	E_STAGE_SE_CURSOR,
	E_STAGE_SE_SELECT,
	E_SOUND_MAX
};

/****************************************************
*グローバル変数宣言
*****************************************************/
static int stage_number=1;
static int sounds[E_SOUND_MAX];

/****************************************************
*プロトタイプ宣言
*****************************************************/

/****************************************************
*タイトル画面：初期化処理
* 引　数：なし
* 戻り値：エラー情報（-1;異常有-1以外;正常終了）
*****************************************************/
int StageSelectScene_Initialize(void)
{
	int ret = 0;

	//cursor_number = 0;

	sounds[E_STAGE_BGM] = LoadSoundMem("sounds/BGM041.ogg");
	sounds[E_STAGE_SE_CURSOR] = LoadSoundMem("sounds/SE1.mp3");
	sounds[E_STAGE_SE_SELECT] = LoadSoundMem("sounds/SE2.mp3");

	ChangeVolumeSoundMem(120, sounds[E_STAGE_SE_CURSOR]);
	ChangeVolumeSoundMem(80, sounds[E_STAGE_SE_SELECT]);

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
void StageSelectScene_Update(void)
{
	//BGMが流れてないときに再生
	/*if (CheckSoundMem(sounds[E_TITLE_BGM])!=TRUE)
	{
		PlaySoundMem(sounds[E_TITLE_BGM], DX_PLAYTYPE_BACK, FALSE);
	}*/

	if (GetButtonDown(XINPUT_BUTTON_A) == TRUE)
	{
		//StopSoundMem(sounds[E_STAGE_BGM]);
		PlaySoundMem(sounds[E_STAGE_SE_SELECT], DX_PLAYTYPE_BACK, FALSE);
		
		Change_Scene(E_GAMEMAIN,stage_number);

	}

	if (GetButtonDown(XINPUT_BUTTON_DPAD_LEFT) == TRUE)
	{
		PlaySoundMem(sounds[E_STAGE_SE_CURSOR], DX_PLAYTYPE_NORMAL, FALSE);
		if (stage_number <= 1)
		{
			stage_number = 1;
		}
		else
		{
			stage_number--;

		}
	}

	if (GetButtonDown(XINPUT_BUTTON_DPAD_RIGHT) == TRUE)
	{
		PlaySoundMem(sounds[E_STAGE_SE_CURSOR], DX_PLAYTYPE_NORMAL, FALSE);
		if (stage_number >= 8)
		{
			stage_number = 8;
		}
		else
		{
			stage_number++;

		}
	}

	if (GetButtonDown(XINPUT_BUTTON_B) == TRUE)
	{
		Change_Scene(E_TITLE,0);
	}
}

/****************************************************
*タイトル画面：描画処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void StageSelectScene_Draw(void)
{
	SetFontSize(50);
	DrawFormatString(100, 100, GetColor(255, 255, 255), "ステージ%d", stage_number);
}

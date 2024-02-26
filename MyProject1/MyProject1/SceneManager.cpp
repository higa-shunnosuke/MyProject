#include "SceneManager.h"
#include"TitleScene.h"
#include"StageSelectScene.h"
#include"HelpScene.h"
#include"CreditScene.h"
#include"GameMainScene.h"
#include"ResultScene.h"
#include"GameoverScene.h"
#include"EndScene.h"
#include"DxLib.h"

/****************************************************
*マクロ定義
*****************************************************/

/****************************************************
*型定義
*****************************************************/

/****************************************************
*変数宣言
*****************************************************/
GAME_MODE game_mode;     //ゲームモード情報
GAME_MODE next_mode;     //次のゲームモード
int read_error;     //読み込みエラー確認

/****************************************************
*プロトタイプ宣言
*****************************************************/

/****************************************************
*シーン管理機能：初期化処理
* 引　数：ゲームモード情報
* 戻り値：なし
*****************************************************/
void SceneManager_Initialize(GAME_MODE mode)
{
	read_error = D_NORMALITY;
	switch (mode)
	{
	case E_TITLE:
		read_error = TitleScene_Initialize();     //タイトル画面の初期化
		break;
	case E_STAGESELECT:
		read_error = StageSelectScene_Initialize();     //ステージ選択画面の初期化
		break;
	case E_HELP:
		read_error = HelpScene_Initialize();     //ヘルプ画面の初期化
		break;
	case E_CREDIT:
		read_error = CreditScene_Initialize();     //クレジット画面の初期化
		break;
	case E_GAMEMAIN:
		read_error = GameMainScene_Initialize();     //ゲームメイン画面の初期化
		break;
	case E_RESULT:
		read_error = ResultScene_Initialize();     //リザルト画面の初期化
		break;
	case E_GAMEOVER:
		read_error = GameoverScene_Initialize();     //ゲームオーバー画面の初期化
		break;
	case E_END:
	default:
		EndScene_Initialize();
		break;
	}
	game_mode = mode;
	next_mode = game_mode;
}

/****************************************************
*シーン管理機能：更新処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void SceneManager_Update(void)
{
	//前フレームとゲームモードが違っていたらシーンを切り替える
	if (game_mode != next_mode)
	{
		SceneManager_Initialize(next_mode);
	}

	//各画面の更新処理
	switch (game_mode)
	{
	case E_TITLE:
		TitleScene_Update();	//タイトル画面の更新
		break;
	case E_STAGESELECT:
		StageSelectScene_Update();	//ステージ選択画面の更新
		break;
	case E_HELP:
		HelpScene_Update();     //ヘルプ画面の更新
		break;
	case E_CREDIT:
		CreditScene_Update();     //クレジット画面の更新
		break;
	case E_GAMEMAIN:
		GameMainScene_Update();	//ゲームメイン画面の更新
		break;
	case E_RESULT:
		ResultScene_Update();     //リザルト画面の更新
		break;
	case E_GAMEOVER:
		GameoverScene_Update();     //ゲームオーバー画面の更新
		break;
	case E_END:
	default:
		EndScene_Update();
		break;
	}
}

/****************************************************
*シーン管理機能：描画処理
* 引　数：なし
* 戻り値：なし
*****************************************************/
void SceneManager_Draw(void)
{
	//各画面の描画処理
	switch (game_mode)
	{
	case E_TITLE:
		TitleScene_Draw();	//タイトル画面の描画
		break;
	case E_STAGESELECT:
		StageSelectScene_Draw();	//ステージ選択画面の描画
		break;
	case E_HELP:
		HelpScene_Draw();     //ヘルプ画面の描画
		break;
	case E_CREDIT:
		CreditScene_Draw();     //クレジット画面の描画
		break;
	case E_GAMEMAIN:
		GameMainScene_Draw();	//ゲームメイン画面の描画
		break;
	case E_RESULT:
		ResultScene_Draw();     //リザルト画面の描画
		break;
	case E_GAMEOVER:
		GameoverScene_Draw();     //ゲームオーバー画面の描画
		break;
	case E_END:
	default:
		EndScene_Draw();
		break;
	}
}

/****************************************************
*シーン管理機能：シーン変更処理
* 引　数：変更するゲームモード
* 戻り値：なし
*****************************************************/
void Change_Scene(GAME_MODE mode)
{
	next_mode = mode;
}

/****************************************************
*シーン管理機能：エラーチェック処理
* 引　数：なし
* 戻り値：エラー情報
*****************************************************/
int ErrorCheck(void)
{
	if (Get_EndTime() == TRUE)
	{
		read_error = D_ERROR;
	}

	return read_error;
}
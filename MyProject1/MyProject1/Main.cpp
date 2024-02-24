#include"DxLib.h"
#include"Common.h"
#include"FreamControl.h"
#include"SceneManager.h"

/***********************************************
 * プログラムの開始
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	double dNextTime = GetNowCount();

	//タイトルを変更
	SetMainWindowText("Profject1");

	// ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	//画面サイズの設定
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOBIT);

	// DXライブラリの初期化処理
	if (DxLib_Init() == -1) return -1;

	//フレーム制御機能初期化処理
	FreamControl_Initialize();

	//シーン管理機能初期化処理
	SceneManager_Initialize(E_TITLE);

	// 描画先画面を裏にする
	SetDrawScreen(DX_SCREEN_BACK);

	//文字サイズを設定
	SetFontSize(FONT_SIZE);

	// ゲームループ
	while ((ProcessMessage() == 0) && GetExitButton() != TRUE)
	{
		//フレーム制御機能更新処理
		FreamControl_Update();

		// 画面の初期化
		ClearDrawScreen();

		//シーン管理機能更新処理
		SceneManager_Update();

		//シーン管理機能描画処理
		SceneManager_Draw();

		// 裏画面の内容を表画面に反映
		ScreenFlip();
	}

	//Dxライブラリ使用の終了処理
	DxLib_End();

	//ソフトの終了
	return 0;
}
#include"DxLib.h"
#include"Common.h"
#include"FreamControl.h"

/***********************************************
 * プログラムの開始
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	double dNextTime = GetNowCount();

	//タイトルを変更
	SetMainWindowText("Profject1");

	ChangeWindowMode(TRUE);		// ウィンドウモードで起動

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOBIT);	//画面サイズの設定

	if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理

	//フレーム制御機能初期化処理
	FreamControl_Initialize();

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする


	// ゲームループ
	while ((ProcessMessage() == 0) && GetExitButton() != TRUE)
	{
		//フレーム制御機能更新処理
		FreamControl_Update();

		// 画面の初期化
		ClearDrawScreen();


		// 裏画面の内容を表画面に反映
		ScreenFlip();
	}

	//Dxライブラリ使用の終了処理
	DxLib_End();

	//ソフトの終了
	return 0;
}
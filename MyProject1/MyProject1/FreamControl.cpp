#include "FreamControl.h"
#include"DxLib.h"

//変数宣言
int FreamTime;
int NowTime;
int Wait;
int LastTime;

//フレーム制御機能：初期化処理
void FreamControl_Initialize(void)
{
	FreamTime = ((int)1000.0f / FREAM_RATE);
	NowTime = 0;
	LastTime = 0;
}

//フレーム制御機能：更新処理
void FreamControl_Update(void)
{
	NowTime = GetNowCount();
	Wait = FreamTime - (NowTime - LastTime);

	if (Wait > 0)
	{
		WaitTimer(Wait);
	}LastTime = GetNowCount();
}
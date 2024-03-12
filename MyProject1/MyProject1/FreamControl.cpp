#include "FreamControl.h"
#include"DxLib.h"

//�ϐ��錾
int FreamTime;
int NowTime;
int Wait;
int LastTime;

//�t���[������@�\�F����������
void FreamControl_Initialize(void)
{
	FreamTime = ((int)1000.0f / FREAM_RATE);
	NowTime = 0;
	LastTime = 0;
}

//�t���[������@�\�F�X�V����
void FreamControl_Update(void)
{
	NowTime = GetNowCount();
	Wait = FreamTime - (NowTime - LastTime);

	if (Wait > 0)
	{
		WaitTimer(Wait);
	}LastTime = GetNowCount();
}
#include "GameMainScene.h"
#include "StageSelectScene.h"
#include "SceneManager.h"
#include "InputControl.h"
#include "Common.h"
#include "Player.h"
#include "Enemy.h"
#include "DxLib.h"

/****************************************************
*�}�N����`
*****************************************************/
#define WALL (50)

/****************************************************
*�ϐ��錾
*****************************************************/
int Is_Restart;		//���X�^�[�g���邩�H

/****************************************************
*�Q�[�����C����ʁF����������
* ���@���F�Ȃ�
* �߂�l�F�G���[���i-1;�ُ�L-1�ȊO;����I���j
*****************************************************/
int GameMainScene_Initialize()
{
	Is_Restart = 1;

	Player_Initialize();
	Enemy_Initialize();
	
	int ret = 0;

	return ret;
}

/****************************************************
*�Q�[�����C����ʁF�X�V����
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void GameMainScene_Update()
{
	if(Is_Restart == 1)
	{
		Player_Update();
		Enemy_Update();
		if (GetButtonDown(XINPUT_BUTTON_START) == TRUE)
		{
			Is_Restart = 0;
		}
	}
	else
	{
		if (GetButtonDown(XINPUT_BUTTON_START) == TRUE)
		{
			Is_Restart = 1;
		}
		if (GetButtonDown(XINPUT_BUTTON_B) == TRUE)
		{
			GameMainScene_Initialize();
		}
		if (GetButtonDown(XINPUT_BUTTON_A) == TRUE)
		{
			Change_Scene(E_STAGESELECT);
		}
	}
}

/****************************************************
*�Q�[�����C����ʁF����������
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void GameMainScene_Draw()
{
	SetFontSize(50);
	DrawBox(SCREEN_LEFT,SCREEN_UPPER,SCREEN_RIGHT, SCREEN_UNDER,0x0,true);
	DrawFormatString(0, 0, 0xffffff,"�X�e�[�W%d", GetStageNum());
	if (Is_Restart == 0)
	{
		DrawString(100, 100, "PAUSE", GetColor(255, 255, 255));
	}
	Player_Draw();
	Enemy_Draw();
}
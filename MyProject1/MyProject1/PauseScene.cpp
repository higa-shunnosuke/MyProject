#include "PauseScene.h"
#include "SceneManager.h"
#include "InputControl.h"
#include "DxLib.h"

/****************************************************
*�^�C�g����ʁF����������
* ���@���F�Ȃ�
* �߂�l�F�G���[���i-1;�ُ�L-1�ȊO;����I���j
*****************************************************/
int PauseScene_Initialize(void)
{
	int ret = 0;

	return ret;
}

/****************************************************
*�^�C�g����ʁF�X�V����
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
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
*�^�C�g����ʁF����������
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void PauseScene_Draw(void)
{
	SetFontSize(50);
	DrawString(100, 100, "PAUSE", GetColor(255, 255, 255));
}
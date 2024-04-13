#include "HelpScene.h"
#include "SceneManager.h"
#include "InputControl.h"
#include "DxLib.h"

/****************************************************
*�w���v��ʁF����������
* ���@���F�Ȃ�
* �߂�l�F�G���[���i-1;�ُ�L-1�ȊO;����I���j
*****************************************************/
int HelpScene_Initialize(void)
{
	int ret = 0;
	
	return ret;
}

/****************************************************
*�w���v��ʁF�X�V����
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void HelpScene_Update(void)
{
	if (GetButtonDown(XINPUT_BUTTON_B) == TRUE)
	{
		Change_Scene(E_TITLE);
	}
}

/****************************************************
*�w���v��ʁF����������
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void HelpScene_Draw(void)
{
	SetFontSize(50);
	DrawString(100, 100, "HELP", GetColor(255, 255, 255));
}
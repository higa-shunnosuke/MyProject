#include "ResultScene.h"
#include "SceneManager.h"
#include "InputControl.h"
#include "DxLib.h"

/****************************************************
*���U���g��ʁF����������
* ���@���F�Ȃ�
* �߂�l�F�G���[���i-1;�ُ�L-1�ȊO;����I���j
*****************************************************/
int ResultScene_Initialize(void)
{
	int ret = 0;

	return ret;
}

/****************************************************
*���U���g��ʁF�X�V����
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void ResultScene_Update(void)
{
	if (GetButtonDown(XINPUT_BUTTON_B) == TRUE)
	{
		Change_Scene(E_TITLE);
	}
}

/****************************************************
*���U���g��ʁF����������
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void ResultScene_Draw(void)
{
	SetFontSize(50);
	DrawString(100, 100, "Result", GetColor(255, 255, 255));
}
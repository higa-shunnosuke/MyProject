#include "GameoverScene.h"
#include "SceneManager.h"
#include "InputControl.h"
#include "DxLib.h"

/****************************************************
*�Q�[���I�[�o�[��ʁF����������
* ���@���F�Ȃ�
* �߂�l�F�G���[���i-1;�ُ�L-1�ȊO;����I���j
*****************************************************/
int GameoverScene_Initialize(void)
{
	int ret = 0;

	return ret;
}

/****************************************************
*�Q�[���I�[�o�[��ʁF�X�V����
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void GameoverScene_Update(void)
{
	if (GetButtonDown(XINPUT_BUTTON_B) == TRUE)
	{
		Change_Scene(E_TITLE);
	}
}

/****************************************************
*�Q�[���I�[�o�[��ʁF����������
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void GameoverScene_Draw(void)
{
	SetFontSize(50);
	DrawString(100, 100, "GAMEOVER", GetColor(255, 255, 255));
}
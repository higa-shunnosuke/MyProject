#include "GameMainScene.h"
#include "SceneManager.h"
#include "InputControl.h"
#include "DxLib.h"
#include "Common.h"
#include "Player.h"

/****************************************************
*�}�N����`
*****************************************************/
#define WALL (50)
/****************************************************
*�^��`
*****************************************************/

/****************************************************
*�O���[�o���ϐ��錾
*****************************************************/
static int stage_number;
/****************************************************
*�v���g�^�C�v�錾
*****************************************************/

/****************************************************
*�^�C�g����ʁF����������
* ���@���F�Ȃ�
* �߂�l�F�G���[���i-1;�ُ�L-1�ȊO;����I���j
*****************************************************/
int GameMainScene_Initialize(void)
{
		Player_Initialize();
	
	int ret = 0;

	return ret;
}

/****************************************************
*�^�C�g����ʁF�X�V����
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void GameMainScene_Update(int s_n)
{
	Player_Update();

	stage_number = s_n;

	if (GetButtonDown(XINPUT_BUTTON_START) == TRUE)
	{
		Change_Scene(E_PAUSE,0);
	}
}

/****************************************************
*�^�C�g����ʁF����������
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void GameMainScene_Draw(void)
{
	SetFontSize(50);
	DrawBox(0,0,SCREEN_WIDTH, SCREEN_HEIGHT,0xffffff,true);
	DrawBox(SCREEN_LEFT,SCREEN_UPPER,SCREEN_RIGHT, SCREEN_UNDER,0x0,true);
	DrawFormatString(0, 0, 0x0,"�X�e�[�W%d", stage_number);
	Player_Draw();

}
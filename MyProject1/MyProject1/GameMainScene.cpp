#include "GameMainScene.h"
#include "StageSelectScene.h"
#include "SceneManager.h"
#include "InputControl.h"
#include "Common.h"
#include "Player.h"
#include "Enemy.h"
#include "Collinder.h"
#include "DxLib.h"

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
int GameMainScene_Initialize()
{
		Player_Initialize();
		Enemy_Initialize();
	
	int ret = 0;

	return ret;
}

/****************************************************
*�^�C�g����ʁF�X�V����
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void GameMainScene_Update()
{
	Player_Update();
	Enemy_Update();

	if (GetButtonDown(XINPUT_BUTTON_START) == TRUE)
	{
		Change_Scene(E_PAUSE);
	}
}

/****************************************************
*�^�C�g����ʁF����������
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void GameMainScene_Draw()
{
	SetFontSize(50);
	DrawBox(SCREEN_LEFT,SCREEN_UPPER,SCREEN_RIGHT, SCREEN_UNDER,0x0,true);
	DrawFormatString(0, 0, 0xffffff,"�X�e�[�W%d", GetStageNum());
	Player_Draw();
	Enemy_Draw();

}
#include "GameMainScene.h"
#include "StageSelectScene.h"
#include "SceneManager.h"
#include "InputControl.h"
#include "Common.h"
#include "Player.h"
#include "Enemy.h"
#include "DxLib.h"

/****************************************************
*�^��`
*****************************************************/
enum
{
	E_GAMEMAIN_BGM,
	E_GAMEMAIN_SE_CURSOR,
	E_GAMEMAIN_SE_SELECT,
	E_SOUND_MAX
};

/****************************************************
*�ϐ��錾
*****************************************************/
int Is_Pause;		//�|�[�Y���邩�H(0:����,1:���Ȃ�)
static int sounds[E_SOUND_MAX];

/****************************************************
*�Q�[�����C����ʁF����������
* ���@���F�Ȃ�
* �߂�l�F�G���[���i-1;�ُ�L-1�ȊO;����I���j
*****************************************************/
int GameMainScene_Initialize()
{
	Is_Pause = 1;		//�|�[�Y���Ȃ�

	Player_Initialize();	//�v���C���[�̏�����
	Enemy_Initialize();		//�G�l�~�[�̏�����
	
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
	//�|�[�Y��ʂł͂Ȃ��Ƃ�
	if(Is_Pause == 1)
	{
		Enemy_Update();		//�G�l�~�[�̍X�V
		Player_Update();	//�v���C���[�̍X�V

		//�X�^�[�g�{�^���������ꂽ��A�|�[�Y����
		if (GetButtonDown(XINPUT_BUTTON_START) == TRUE)
		{
			Is_Pause = 0;
		}
	}
	//�|�[�Y��ʂ̂Ƃ�
	else
	{
		//�X�^�[�g�{�^���������ꂽ��A�|�[�Y������
		if (GetButtonDown(XINPUT_BUTTON_START) == TRUE)
		{
			Is_Pause = 1;
		}
		//B�{�^���������ꂽ��A���X�^�[�g����
		if (GetButtonDown(XINPUT_BUTTON_B) == TRUE)
		{
			GameMainScene_Initialize();
		}
		//A�{�^���������ꂽ��A�X�e�[�W�I���ɖ߂�
		if (GetButtonDown(XINPUT_BUTTON_A) == TRUE)
		{
			Change_Scene(E_STAGESELECT);
		}
	}
}

/****************************************************
*�Q�[�����C����ʁF�`�揈��
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void GameMainScene_Draw()
{
	SetFontSize(50);
	//�w�i�̕`��
	DrawBox(SCREEN_LEFT,SCREEN_UPPER,SCREEN_RIGHT, SCREEN_UNDER,0x0,true);
	//�X�e�[�W���̕`��
	DrawFormatString(0, 0, 0xffffff,"�X�e�[�W%d", GetStageNum());
	//�|�[�Y��ʂ̕`��
	if (Is_Pause == 0)
	{
		DrawString(100, 100, "PAUSE", GetColor(255, 255, 255));
	}

	Player_Draw();	//�v���C���[�̕`��
	Enemy_Draw();	//�v���C���[�̕`��
}
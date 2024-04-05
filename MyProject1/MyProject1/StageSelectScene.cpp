#include "StageSelectScene.h"
#include "SceneManager.h"
#include"InputControl.h"
#include "DxLib.h"

/****************************************************
*�^��`
*****************************************************/
enum
{
	E_STAGE_BGM,
	E_STAGE_SE_CURSOR,
	E_STAGE_SE_SELECT,
	E_SOUND_MAX
};

/****************************************************
*�O���[�o���ϐ��錾
*****************************************************/
static int stage_number=1;
static int sounds[E_SOUND_MAX];

/****************************************************
*�X�e�[�W�I����ʁF����������
* ���@���F�Ȃ�
* �߂�l�F�G���[���i-1;�ُ�L-1�ȊO;����I���j
*****************************************************/
int StageSelectScene_Initialize(void)
{
	int ret = 0;

	sounds[E_STAGE_BGM] = LoadSoundMem("sounds/BGM041.ogg");
	sounds[E_STAGE_SE_CURSOR] = LoadSoundMem("sounds/SE1.mp3");
	sounds[E_STAGE_SE_SELECT] = LoadSoundMem("sounds/SE2.mp3");

	ChangeVolumeSoundMem(120, sounds[E_STAGE_SE_CURSOR]);
	ChangeVolumeSoundMem(80, sounds[E_STAGE_SE_SELECT]);

	for (int i = 0; i < E_SOUND_MAX; i++)
	{
		if (sounds[i] == -1)
		{
			ret = -1;
			break;
		}
	}
	return ret;
}

/****************************************************
*�X�e�[�W�I����ʁF�X�V����
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void StageSelectScene_Update(void)
{
	//BGM������ĂȂ��Ƃ��ɍĐ�
	if (CheckSoundMem(sounds[E_STAGE_BGM])!=TRUE)
	{
		PlaySoundMem(sounds[E_STAGE_BGM], DX_PLAYTYPE_BACK, FALSE);
	}

	if (GetButtonDown(XINPUT_BUTTON_DPAD_LEFT) == TRUE)
	{
		PlaySoundMem(sounds[E_STAGE_SE_CURSOR], DX_PLAYTYPE_NORMAL, FALSE);
		if (stage_number <= 1)
		{
			stage_number = 1;
		}
		else
		{
			stage_number--;
		}
	}

	if (GetButtonDown(XINPUT_BUTTON_DPAD_RIGHT) == TRUE)
	{
		PlaySoundMem(sounds[E_STAGE_SE_CURSOR], DX_PLAYTYPE_NORMAL, FALSE);
		if (stage_number >= 8)
		{
			stage_number = 8;
		}
		else
		{
			stage_number++;
		}
	}

	if (GetButtonDown(XINPUT_BUTTON_A) == TRUE)
	{
		StopSoundMem(sounds[E_STAGE_BGM]);
		PlaySoundMem(sounds[E_STAGE_SE_SELECT], DX_PLAYTYPE_BACK, FALSE);

		Change_Scene(E_GAMEMAIN);
	}

	if (GetButtonDown(XINPUT_BUTTON_B) == TRUE)
	{
		Change_Scene(E_TITLE);
	}
}

/****************************************************
*�X�e�[�W�I����ʁF�`�揈��
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void StageSelectScene_Draw(void)
{
	SetFontSize(50);
	DrawFormatString(0, 0, GetColor(255, 255, 255), "�X�e�[�W%d", stage_number);
}

/****************************************************
*�X�e�[�W�I����ʁF�X�e�[�W�ԍ��擾����
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
int GetStageNum()
{
	return stage_number;
}

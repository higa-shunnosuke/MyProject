#include "TitleScene.h"
#include "SceneManager.h"
#include"InputControl.h"
#include "DxLib.h"


/****************************************************
*�}�N����`
*****************************************************/

/****************************************************
*�^��`
*****************************************************/
enum
{
	E_TITLE_BGM,
	E_TITLE_SE_CURSOR,
	E_TITLE_SE_SELECT,
	E_SOUND_MAX
};

/****************************************************
*�O���[�o���ϐ��錾
*****************************************************/
static int cursor_number;
static int sounds[E_SOUND_MAX];

/****************************************************
*�v���g�^�C�v�錾
*****************************************************/

/****************************************************
*�^�C�g����ʁF����������
* ���@���F�Ȃ�
* �߂�l�F�G���[���i-1;�ُ�L-1�ȊO;����I���j
*****************************************************/
int TitleScene_Initialize(void)
{
	int ret = 0;

	//cursor_number = 0;

	sounds[E_TITLE_BGM] = LoadSoundMem("sounds/BGM041.ogg");
	sounds[E_TITLE_SE_CURSOR] = LoadSoundMem("sounds/SE1.mp3");
	sounds[E_TITLE_SE_SELECT] = LoadSoundMem("sounds/SE2.mp3");

	ChangeVolumeSoundMem(120, sounds[E_TITLE_SE_CURSOR]);
	ChangeVolumeSoundMem(80, sounds[E_TITLE_SE_SELECT]);

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
*�^�C�g����ʁF�X�V����
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void TitleScene_Update(void)
{
	//BGM������ĂȂ��Ƃ��ɍĐ�
	/*if (CheckSoundMem(sounds[E_TITLE_BGM])!=TRUE)
	{
		PlaySoundMem(sounds[E_TITLE_BGM], DX_PLAYTYPE_BACK, FALSE);
	}*/

	if (GetButtonDown(XINPUT_BUTTON_A) == TRUE)
	{
		StopSoundMem(sounds[E_TITLE_BGM]);
		PlaySoundMem(sounds[E_TITLE_SE_SELECT], DX_PLAYTYPE_BACK, FALSE);
		switch (cursor_number)
		{
		case 0:
			Change_Scene(E_STAGESELECT,0);
			break;
		case 1:
			Change_Scene(E_HELP,0);
			break;
		case 2:
			Change_Scene(E_CREDIT,0);
			break;
		case 3:
		default:
			Change_Scene(E_END,0);
			break;
		}
	}

	if (GetButtonDown(XINPUT_BUTTON_DPAD_UP) == TRUE)
	{
		PlaySoundMem(sounds[E_TITLE_SE_CURSOR], DX_PLAYTYPE_NORMAL, FALSE);
		if (cursor_number <= 0)
		{
			cursor_number = 3;
		}
		else
		{
			cursor_number--;

		}
	}

	if (GetButtonDown(XINPUT_BUTTON_DPAD_DOWN) == TRUE)
	{
		PlaySoundMem(sounds[E_TITLE_SE_CURSOR], DX_PLAYTYPE_NORMAL, FALSE);
		if (cursor_number >= 3)
		{
			cursor_number = 0;
		}
		else
		{
			cursor_number++;

		}
	}
}

/****************************************************
*�^�C�g����ʁF�`�揈��
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void TitleScene_Draw(void)
{
	SetFontSize(50);
	DrawString(100, 100, "�^�C�g��", GetColor(255, 255, 255));
	switch (cursor_number)
	{
	case 0:
		DrawString(100, 300, "�X�^�[�g", GetColor(0, 255, 0));
		DrawString(100, 350, "�w���v", GetColor(255, 255, 255));
		DrawString(100, 400, "�N���W�b�g", GetColor(255, 255, 255));
		DrawString(100, 450, "�G���h", GetColor(255, 255, 255));
		break;
	case 1:
		DrawString(100, 300, "�X�^�[�g", GetColor(255, 255, 255));
		DrawString(100, 350, "�w���v", GetColor(0, 255, 0));
		DrawString(100, 400, "�N���W�b�g", GetColor(255, 255, 255));
		DrawString(100, 450, "�G���h", GetColor(255, 255, 255));
		break;
	case 2:
		DrawString(100, 300, "�X�^�[�g", GetColor(255, 255, 255));
		DrawString(100, 350, "�w���v", GetColor(255, 255, 255));
		DrawString(100, 400, "�N���W�b�g", GetColor(0, 255, 0));
		DrawString(100, 450, "�G���h", GetColor(255, 255, 255));
		break;
	default:
		DrawString(100, 300, "�X�^�[�g", GetColor(255, 255, 255));
		DrawString(100, 350, "�w���v", GetColor(255, 255, 255));
		DrawString(100, 400, "�N���W�b�g", GetColor(255, 255, 255));
		DrawString(100, 450, "�G���h", GetColor(0, 255, 0));
		break;
	}

	DrawTriangle(60, 310 + (cursor_number * 50), 60, 340 + (cursor_number * 50), 90, 325 + (cursor_number * 50), GetColor(0, 255, 0), TRUE);
}

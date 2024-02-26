#include "SceneManager.h"
#include"TitleScene.h"
#include"StageSelectScene.h"
#include"HelpScene.h"
#include"CreditScene.h"
#include"GameMainScene.h"
#include"ResultScene.h"
#include"GameoverScene.h"
#include"EndScene.h"
#include"DxLib.h"

/****************************************************
*�}�N����`
*****************************************************/

/****************************************************
*�^��`
*****************************************************/

/****************************************************
*�ϐ��錾
*****************************************************/
GAME_MODE game_mode;     //�Q�[�����[�h���
GAME_MODE next_mode;     //���̃Q�[�����[�h
int read_error;     //�ǂݍ��݃G���[�m�F

/****************************************************
*�v���g�^�C�v�錾
*****************************************************/

/****************************************************
*�V�[���Ǘ��@�\�F����������
* ���@���F�Q�[�����[�h���
* �߂�l�F�Ȃ�
*****************************************************/
void SceneManager_Initialize(GAME_MODE mode)
{
	read_error = D_NORMALITY;
	switch (mode)
	{
	case E_TITLE:
		read_error = TitleScene_Initialize();     //�^�C�g����ʂ̏�����
		break;
	case E_STAGESELECT:
		read_error = StageSelectScene_Initialize();     //�X�e�[�W�I����ʂ̏�����
		break;
	case E_HELP:
		read_error = HelpScene_Initialize();     //�w���v��ʂ̏�����
		break;
	case E_CREDIT:
		read_error = CreditScene_Initialize();     //�N���W�b�g��ʂ̏�����
		break;
	case E_GAMEMAIN:
		read_error = GameMainScene_Initialize();     //�Q�[�����C����ʂ̏�����
		break;
	case E_RESULT:
		read_error = ResultScene_Initialize();     //���U���g��ʂ̏�����
		break;
	case E_GAMEOVER:
		read_error = GameoverScene_Initialize();     //�Q�[���I�[�o�[��ʂ̏�����
		break;
	case E_END:
	default:
		EndScene_Initialize();
		break;
	}
	game_mode = mode;
	next_mode = game_mode;
}

/****************************************************
*�V�[���Ǘ��@�\�F�X�V����
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void SceneManager_Update(void)
{
	//�O�t���[���ƃQ�[�����[�h������Ă�����V�[����؂�ւ���
	if (game_mode != next_mode)
	{
		SceneManager_Initialize(next_mode);
	}

	//�e��ʂ̍X�V����
	switch (game_mode)
	{
	case E_TITLE:
		TitleScene_Update();	//�^�C�g����ʂ̍X�V
		break;
	case E_STAGESELECT:
		StageSelectScene_Update();	//�X�e�[�W�I����ʂ̍X�V
		break;
	case E_HELP:
		HelpScene_Update();     //�w���v��ʂ̍X�V
		break;
	case E_CREDIT:
		CreditScene_Update();     //�N���W�b�g��ʂ̍X�V
		break;
	case E_GAMEMAIN:
		GameMainScene_Update();	//�Q�[�����C����ʂ̍X�V
		break;
	case E_RESULT:
		ResultScene_Update();     //���U���g��ʂ̍X�V
		break;
	case E_GAMEOVER:
		GameoverScene_Update();     //�Q�[���I�[�o�[��ʂ̍X�V
		break;
	case E_END:
	default:
		EndScene_Update();
		break;
	}
}

/****************************************************
*�V�[���Ǘ��@�\�F�`�揈��
* ���@���F�Ȃ�
* �߂�l�F�Ȃ�
*****************************************************/
void SceneManager_Draw(void)
{
	//�e��ʂ̕`�揈��
	switch (game_mode)
	{
	case E_TITLE:
		TitleScene_Draw();	//�^�C�g����ʂ̕`��
		break;
	case E_STAGESELECT:
		StageSelectScene_Draw();	//�X�e�[�W�I����ʂ̕`��
		break;
	case E_HELP:
		HelpScene_Draw();     //�w���v��ʂ̕`��
		break;
	case E_CREDIT:
		CreditScene_Draw();     //�N���W�b�g��ʂ̕`��
		break;
	case E_GAMEMAIN:
		GameMainScene_Draw();	//�Q�[�����C����ʂ̕`��
		break;
	case E_RESULT:
		ResultScene_Draw();     //���U���g��ʂ̕`��
		break;
	case E_GAMEOVER:
		GameoverScene_Draw();     //�Q�[���I�[�o�[��ʂ̕`��
		break;
	case E_END:
	default:
		EndScene_Draw();
		break;
	}
}

/****************************************************
*�V�[���Ǘ��@�\�F�V�[���ύX����
* ���@���F�ύX����Q�[�����[�h
* �߂�l�F�Ȃ�
*****************************************************/
void Change_Scene(GAME_MODE mode)
{
	next_mode = mode;
}

/****************************************************
*�V�[���Ǘ��@�\�F�G���[�`�F�b�N����
* ���@���F�Ȃ�
* �߂�l�F�G���[���
*****************************************************/
int ErrorCheck(void)
{
	if (Get_EndTime() == TRUE)
	{
		read_error = D_ERROR;
	}

	return read_error;
}
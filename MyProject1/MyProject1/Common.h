#pragma once
#include"DxLib.h"

/******************************************
* �}�N����`
******************************************/
#define _USE_MATH_DEFINES	//���l���Z�萔
#include <math.h>

//��ʂ̐ݒ�
#define SCREEN_WIDTH (1280)
#define SCREEN_HEIGHT (720)
#define SCREEN_COLOBIT (32)
#define FONT_SIZE (20)

#define SCREEN_LEFT (0)
#define SCREEN_RIGHT (1280)
#define SCREEN_UPPER (0)
#define SCREEN_UNDER (720)

/****************************************************
*���͐���@�\�F�Q�[���I���p�̃{�^�����菈��
* ���@���F����
* �߂�l�FTRUE�i�������j,FALSE�i�����ĂȂ�)
*****************************************************/
int GetExitButton(void)
{
	int ret = FALSE;

	if ((CheckHitKey(KEY_INPUT_ESCAPE) == TRUE))
	{
		ret = TRUE;
	}
	return ret;
}
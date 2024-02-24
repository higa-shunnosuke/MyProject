#include"DxLib.h"
#include"Common.h"
#include"FreamControl.h"

/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	double dNextTime = GetNowCount();

	//�^�C�g����ύX
	SetMainWindowText("Profject1");

	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOBIT);	//��ʃT�C�Y�̐ݒ�

	if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������

	//�t���[������@�\����������
	FreamControl_Initialize();

	SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���


	// �Q�[�����[�v
	while ((ProcessMessage() == 0) && GetExitButton() != TRUE)
	{
		//�t���[������@�\�X�V����
		FreamControl_Update();

		// ��ʂ̏�����
		ClearDrawScreen();


		// ����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();
	}

	//Dx���C�u�����g�p�̏I������
	DxLib_End();

	//�\�t�g�̏I��
	return 0;
}
#include"DxLib.h"
#include"Common.h"
#include"FreamControl.h"
#include"SceneManager.h"

/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	double dNextTime = GetNowCount();

	//�^�C�g����ύX
	SetMainWindowText("Profject1");

	// �E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//��ʃT�C�Y�̐ݒ�
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOBIT);

	// DX���C�u�����̏���������
	if (DxLib_Init() == -1) return -1;

	//�t���[������@�\����������
	FreamControl_Initialize();

	//�V�[���Ǘ��@�\����������
	SceneManager_Initialize(E_TITLE);

	// �`����ʂ𗠂ɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	//�����T�C�Y��ݒ�
	SetFontSize(FONT_SIZE);

	// �Q�[�����[�v
	while ((ProcessMessage() == 0) && GetExitButton() != TRUE)
	{
		//�t���[������@�\�X�V����
		FreamControl_Update();

		// ��ʂ̏�����
		ClearDrawScreen();

		//�V�[���Ǘ��@�\�X�V����
		SceneManager_Update();

		//�V�[���Ǘ��@�\�`�揈��
		SceneManager_Draw();

		// ����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();
	}

	//Dx���C�u�����g�p�̏I������
	DxLib_End();

	//�\�t�g�̏I��
	return 0;
}
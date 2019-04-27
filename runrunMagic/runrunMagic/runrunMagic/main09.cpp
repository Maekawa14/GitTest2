#include "input.h"
// WinMain�֐�


//�����\������!!!!!!!!!
int color = GetColor(255, 255, 255);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	//---------
	//�ݒ�
	//---------
	ChangeWindowMode(TRUE);  //�E�B���h�E���[�h�L

	// ��ʃ��[�h�̐ݒ�
	SetGraphMode(900, 600, 32);

	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		return -1;
	}


	//�v�����[�h�J�n
	SetDrawScreen(DX_SCREEN_BACK);

	initKey();

	while (1)
	{
		// ��ʂ�������(�^�����ɂ���)
		ClearDrawScreen();


		upDateKey();

		//�X�y�[�X�L�[�̏��
		switch ( getKey(KEY_INPUT_SPACE) )
		{
		case KEY_STATE_OFF:
			DrawFormatString(70, 230, color, "OFF");
			printf("OFF");
			break;
		case KEY_STATE_PUSHDOWN :
			DrawFormatString(70, 230, color, "�������Ă��܂�");
			printf("�������Ă��܂�");
			break;
		case KEY_STATE_PRESSED:
			DrawFormatString(70, 230, color, "�����Ɖ�����Ă��܂�");
			printf("�����Ɖ�����Ă��܂�");
			break;
		case KEY_STATE_PULLUP:
			DrawFormatString(70, 230, color, "�L�[������܂���");
			printf("�L�[������܂���");
			break;
	
		}

		// ����ʂ̓��e��\��ʂɃR�s�[����
		ScreenFlip();


		// Windows ���L�̖ʓ|�ȏ������c�w���C�u�����ɂ�点��
		// -1 ���Ԃ��Ă����烋�[�v�𔲂���
		if (ProcessMessage() < 0) break;

		// �����d�r�b�L�[��������Ă����烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

	}


	// �c�w���C�u�����g�p�̏I������
	DxLib_End();


	// �\�t�g�̏I��
	return 0;
}

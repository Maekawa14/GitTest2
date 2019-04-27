
//---------------------------------------------------------------------------
// @brief  ���C������.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "komon.h"

//-----------------------------------------------------------------------------
// @brief  ���C���֐�.
//-----------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    ChangeWindowMode(TRUE);
	
    // �c�w���C�u��������������
    if (DxLib_Init() == -1)
    {
        return -1;	// �G���[���N�����璼���ɏI��
    }
    
    // ��ʃ��[�h�̃Z�b�g
	SetGraphMode(640, 480, 16);
	//SetGraphMode(1920, 1080, 16);
	SetDrawScreen(DX_SCREEN_BACK);

	// ��Q���𐶐�.
	ObstructManager* obstructManager = new ObstructManager();
	obstructManager->CreateObstructs();

	// �A�C�e�����΂𐶐�.
	GraphManager* graphManager = new GraphManager();
	graphManager->CreateGraph();

	// �A�C�e�����΂𐶐�.
	DonutManager* donutManager = new DonutManager();
	donutManager->CreateGraph();

	//�j�R�𐶐�
	Nanji* nanji = new Nanji();


	// �v���C���[�𐶐�.
	Player* player = new Player();

	// �J�����𐶐�.
	Camera* camera = new Camera();

	//�����蔻�菈��
	HitChecker* hitChecker = new HitChecker();

	//�L�[�{�[�h�̉��������ǂ����𐶐�
	KeyState*  keyState = new KeyState();

	//�Q�[�W�𐶐�
	Gauge* gauge = new Gauge();

	//	�֐����܂Ƃ�
	FunctionSummary* functionSummary = new FunctionSummary();

	//	�J�E���g�_�E��
	CountDown* countDown = new CountDown();
	keyState->InitKey();

	// �G�X�P�[�v�L�[��������邩�E�C���h�E��������܂Ń��[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// ��ʂ�����������
		ClearDrawScreen();

		// �w���̃}�C�i�X�����̃f�B���N�V���i�����C�g�ɕύX
		ChangeLightTypeDir(VGet(-1.0f, -5.0f, 1.0f));

		//�Q�[�����C��
		functionSummary->Update(*obstructManager, *graphManager,*donutManager, *nanji,
			*player, *camera, *hitChecker, *keyState, *gauge, *countDown);

		// ����ʂ̓��e��\��ʂɔ��f������
		ScreenFlip();
	}

	// ��Q�����폜
	obstructManager->DestroyObstructs();
	delete(obstructManager);

	// �A�C�e�����΂��폜
	graphManager->DestroyGraph();
	delete(graphManager);

	// �j�R���폜
	delete(nanji);

	// �v���C���[���폜
	delete(player);

	// �J�������폜.
	delete(camera);

	//�����蔻����폜
	delete(hitChecker);

	//�L�[���͂��폜
	delete(keyState);

	//�Q�[�W���폜
	delete(gauge);
	// �c�w���C�u�����̌�n��
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}
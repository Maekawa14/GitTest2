#include "komon.h"

void FunctionSummary::Update(ObstructManager& obstructManager, GraphManager& graphManager, DonutManager& donutManager, Nanji& nanji,
							 Player& player, Camera& camera, HitChecker& hitChecker, KeyState& keyState,
							 Gauge& gauge, CountDown& countDown)
{
	//�Q�[���J�n�J�E���g�_�E��
	countDown.Update();
	// ��Q������
	obstructManager.Update();
	// ��Q���`��
	obstructManager.Draw();

	// ��Ε`��
	graphManager.Draw(hitChecker);

	// �h�[�i�c��`��
	donutManager.Draw(hitChecker);

	// �v���C���[�`��
	player.Draw(hitChecker);

	//�v���C���[�̃A�j���[�V����
	player.Motion();

	//�j�R�`��
	nanji.Update(player);

	//�Q�[�W�̕`��
	gauge.Update();

	// �J��������
	camera.Update(player);
	if (countDown.GameStart)
	{
		//�L�[�{�[�h����
		keyState.UpDateKey(); 

		// ��ΐ���
		graphManager.Update();

		// �h�[�i�c����
		donutManager.Update();
		// �v���C���[����.
		player.Update(keyState);

		// �v���C���[�̓���
		player.Move();

		// �v���C���[���W�����v
		player.Jump();

		//�t�B�[�o�[�^�C��
		player.Fever(gauge);

		// �q�b�g�̃`�F�b�N
		hitChecker.PlayerGround(player, obstructManager);
		hitChecker.PlayerJewelry(player, graphManager, gauge);

		hitChecker.PlayerNanji(player, nanji, gauge);
		hitChecker.PlayerDornatsu(player, donutManager, gauge);

		// HP����������
		gauge.DecreaseHP();

		// HP,MP���Q�[�W��蒴���Ȃ��悤�ɂ���
		gauge.Limit();

		// �t�B�[�o�[�^�C���̃t���O����
		gauge.Fever(player);
	}
}

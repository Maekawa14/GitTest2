#include "gauge.h"

Gauge::Gauge()
{

	//�̗͘g�̏����l
	HPX = 10.0f;
	HPY = 10.0f;
	HPX2 = 210.0f;
	HPY2 = 30.0f;
	HPGX2 = 210.0f;

	//�̗̓Q�[�W�̘g�F
	HPframeColor = GetColor(255, 255, 255);

	//�̗̓Q�[�W�̐F(�s���N)
	HPColor = GetColor(255, 40, 166);


	//�}�W�b�N�|�C���g�g�̏����l
	MPX = 10.0f;
	MPY = 50.0f;
	MPX2 = 210.0f;
	MPY2 = 70.0f;
	MPGX2 = 10.0f;

	//�̗̓Q�[�W�̘g�F
	MPframeColor = GetColor(255, 255, 255);

	//�}�W�b�N�|�C���g�̃Q�[�W�i���F�j
	MPColor = GetColor(54, 201, 203);
}

void Gauge::Update()
{
	//�̗̓Q�[�W
	DrawBox((int)HPX, (int)HPY, (int)HPGX2, (int)HPY2,
		HPColor, TRUE);

	//�̗̓Q�[�W�̘g
	DrawBox((int)HPX, (int)HPY, (int)HPX2, (int)HPY2,
		HPframeColor, FALSE);

	//�}�W�b�N�|�C���g�Q�[�W
	DrawBox((int)MPX, (int)MPY, (int)MPGX2, (int)MPY2,
		MPColor, TRUE);

	//�}�W�b�N�|�C���g�Q�[�W�̘g
	DrawBox((int)MPX, (int)MPY, (int)MPX2, (int)MPY2,
		MPframeColor, FALSE);
}

void Gauge::DecreaseHP()
{
	//HP�Q�[�W�̌���
	HPGX2 -= 0.2f;
}

void Gauge::Limit()
{
	// �̗̓Q�[�W�̕�������Ȃ��悤�ɂ���
	if (HPGX2 > 210.0f)
	{
		HPGX2 = 210.0f;
	}

	//�̗̓Q�[�W�̕���艺���Ȃ��悤�ɂ���
	if (HPGX2 < 11.0f)
	{
		HPGX2 = 11.0f;
		DrawFormatString(550, 120, GetColor(255, 0, 0), "GAME OVER!");
	}

	//���@�Q�[�W�̕�������Ȃ��悤�ɂ���
	if (MPGX2 > 210.0)
	{
		MPGX2 = 210.0f;
	}
}

void Gauge::Fever(Player& player)
{
	// MP�Q�[�W���}�b�N�X�ɂȂ�����
	// �t�B�[�o�[�^�C���̃t���O��true�ɂ���
	if (MPGX2 > 210.0)
	{
		player.feverFlag = true;
	}
}

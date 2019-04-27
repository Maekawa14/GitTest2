//-----------------------------------------------------------------------------
// @brief  �v���C���[�N���X.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "komon.h"

const float Player::COLIDE_DECEL_FAC = 0.4f;			// ��Q���ɂԂ������Ƃ��̌�����.

//�����蔻���else���S�͈͂ɂȂ��Ă���

//-----------------------------------------------------------------------------
// @brief  �R���X�g���N�^.
//-----------------------------------------------------------------------------
Player::Player() : modelHandle(-1)
, hitRadius(10.0f)
{

	//3D���f���̓ǂݍ���
	modelHandle = MV1LoadModel("img/���Av1_12/���Av1_12.pmd");

	//3D���f���̑傫��
	MV1SetScale(modelHandle, VGet(2.0f, 2.0f, 2.0f));

	//3D���f���Ŏg�p���Ă���}�e���A���̐����擾����
	MaterialNum = MV1GetMaterialNum(modelHandle);

	for (int i = 0; i < MaterialNum; i++)
	{
		// �}�e���A���̗֊s���̑������擾  
		float dotwidth = MV1GetMaterialOutLineDotWidth(modelHandle, i);
		// �}�e���A���̗֊s���̑������g�債��������������  
		MV1SetMaterialOutLineDotWidth(modelHandle, i, dotwidth / 50.0f);
	}

	// �A�^�b�`�����A�j���[�V�����̑��Đ����Ԃ��擾����
	TotalTime = MV1GetAttachAnimTotalTime(modelHandle, AttachIndex);

	// �Đ����Ԃ̏�����
	PlayTime = 0.0f;

	//�v���C���[�̏����ʒu  
	pos = VGet(-4300.0f, 53.0f, 0.0);
	velocity = VGet(0.0f, 0.0f, 0.0f);

	//�v���C���[�̃X�s�[�h�l
	speed = 2.0f;

	//�v���C���[�̏�������
	angleX = 0.0f, angleY = 4.5f, angleZ = 0.0f;

	// �W�����v�t���O
	jumpFlag = false;

	// �������Ƃ��L�[���͂𖳌�
	dropFlag = false;

	// �}�W�b�N�|�C���g
	magicPoint = 0;

	// Y���W��ۊǂ���
	prevY = 0;
	tempY = 0;

	// �����蔼�a
    radius = 4.0;

	// �ҋ@�����[�V����
	waitFlag = true;

	// ���郂�[�V������off
	runFlag = false;

	// �t�B�[�o�[�^�C���̃t���O
	feverFlag = false;

	//3D���f���̌���
	MV1SetRotationXYZ(modelHandle, VGet(angleX, angleY, angleZ));
}

//-----------------------------------------------------------------------------
// @brief  �f�X�g���N�^
//-----------------------------------------------------------------------------
Player::~Player()
{
	// ���f���̃A�����[�h
	MV1DeleteModel(modelHandle);
}

//-----------------------------------------------------------------------------
// @brief  �X�V
//-----------------------------------------------------------------------------
void Player::Update(KeyState& keyState)
{
	//�X�y�[�X�L�[�̏��
	switch (getKey(KEY_INPUT_SPACE))
	{
	case KEY_STATE_OFF:
		DrawFormatString(550, 0, GetColor(255, 255, 255), "OFF");
		break;
	case KEY_STATE_PUSHDOWN:     //�������u�ԃW�����v
		if (jumpFlag == false)
		{
			dropFlag = false;
			jumpFlag = true;
			prevY = pos.y;
			pos.y = pos.y + 6.5f;
		}
		DrawFormatString(550, 0, GetColor(255,255,255), "pushdown");
		break;
	case KEY_STATE_PRESSED:
		DrawFormatString(550, 0, GetColor(255, 255, 255), "PRESSED");
		break;
	case KEY_STATE_PULLUP:
		DrawFormatString(550, 0, GetColor(255, 255, 255), "PULLUP");
		break;
	}
}

void Player::Move()
{
	//printfDx("player.x : %f\n", pos.y);

	// �L�[���͎擾
	int Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//�v���C���[��65��艺�ɗ������ꍇ����ł��Ȃ��悤�ɂ���
	if (pos.y < 65)
	{
		dropFlag = true;
	}

	//�v���C���[�̈ړ�����
	if (pos.x < 3750.0f)
	{
		//�v���C���[�̈ړ����x
		pos.x += 83.5f;

		//���郂�[�V�����Đ�
		runFlag = true;
		waitFlag = false;
	}
	else
	{
		runFlag = false;
		waitFlag = true;
		DrawFormatString(550, 140, GetColor(252, 255, 0), "GAME CLEAR!");
	}
}

void Player::Jump()
{
	//�W�����v����

	if (jumpFlag == true)
	{
		tempY = pos.y;   //����Y���W��tempY�ɕۑ�����
		pos.y += (pos.y - prevY) - 0.5f;
		prevY = tempY;
		if (pos.y <= 53)
		{
			jumpFlag = false;
		}
	}
}

//�v���C���[�̃��[�V����
void Player::Motion()
{
	// ���܂ŃA�^�b�`���Ă����A�j���[�V�������f�^�b�`
	MV1DetachAnim(modelHandle, AttachIndex);

	if(runFlag == true)
	{
		//�R�c���f����1�Ԗڂ̃A�j���[�V�������A�^�b�`����
		AttachIndex = MV1AttachAnim(modelHandle, 1, -1, FALSE);
		// �Đ����Ԃ�i�߂�
		PlayTime += 0.5f;
	}
	else if (waitFlag == true)
	{
		// �R�c���f����1�Ԗڂ̃A�j���[�V�������A�^�b�`����
		AttachIndex = MV1AttachAnim(modelHandle, 0, -1, FALSE);
		// �Đ����Ԃ�i�߂�
		PlayTime += 0.7f;
	}

	// �A�j���[�V�����̑����Ԃ��擾���Ă���
	TotalTime = MV1GetAttachAnimTotalTime(modelHandle, AttachIndex);

	// �A�j���[�V�����Đ����Ԃ�������
	//PlayTime = 0.0f;
	MV1SetAttachAnimTime(modelHandle, AttachIndex, PlayTime);

	//3D���f���̌���
	MV1SetRotationXYZ(modelHandle, VGet(angleX, angleY, angleZ));

	// �RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(modelHandle, pos);

	// �Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ��O�ɖ߂�
	if (PlayTime >= TotalTime) {
		PlayTime = 0.0f;
	}

	// �Đ����Ԃ��Z�b�g����
	MV1SetAttachAnimTime(modelHandle, AttachIndex, PlayTime);
}

void Player::Fever(Gauge& gauge)
{
	if (feverFlag)
	{
		gauge.stopDecrease = true;
		gauge.MPGX2 -= 0.1;
		DrawFormatString(500, 100, GetColor(0, 255, 255), "Fever!!");

		if (gauge.MPGX2 < 0)
		{
			gauge.stopDecrease = false;
			feverFlag = false;
		}
	}
}


//-----------------------------------------------------------------------------
// @brief  �`��
//-----------------------------------------------------------------------------
void Player::Draw(HitChecker& hitChecker)
{
	// �R�c���f���̕`��
	MV1DrawModel(modelHandle);


	// �f�o�b�O�����蔻��
	//DrawSphere3D(pos, hitRadius, 5, 0x00ffff, 0x00ffff, false);

}

//-----------------------------------------------------------------------------
// @brief  �Փˏ���
//-----------------------------------------------------------------------------
void Player::OnHitObstruct(ObstructBase& obstruct)
{
	//���������Ƃ��|�C���g�����Z����
	magicPoint++;
}
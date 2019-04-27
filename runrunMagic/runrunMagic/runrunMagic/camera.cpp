//-----------------------------------------------------------------------------
// @brief  �J�����N���X.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "komon.h"
//-----------------------------------------------------------------------------
// @brief  �R���X�g���N�^.
//-----------------------------------------------------------------------------
Camera::Camera()
{
	//���s0.1�`1000�܂ł��J�����̕`��͈͂Ƃ���
	SetCameraNearFar(10.0f, 1200.0f);

	//�J�����̍��W������
	x = 0.0, y = 0.0, z = 0.0;

	// �J�����̌�����������
	CameraHAngle = 0.0f;
	CameraVAngle = 0.0f;
}

//-----------------------------------------------------------------------------
// @brief  �f�X�g���N�^.
//-----------------------------------------------------------------------------
Camera::~Camera()
{
	// �����Ȃ�.
}

//-----------------------------------------------------------------------------
// @brief  �X�V.
//-----------------------------------------------------------------------------
void Camera::Update(const Player& player)
{
	// �J�����̈ʒu�̓J�����̐����p�x�Ɛ����p�x����Z�o
	CameraLookAtPosition = player.pos;
	CameraLookAtPosition.x += 90;   //���S���E���ɂ��炷
	CameraLookAtPosition.y += CAMERA_LOOK_AT_HEIGHT;

	// �ŏ��ɐ����p�x�𔽉f�����ʒu���Z�o
	SinParam = (float)sin(CameraVAngle / 180.0f * DX_PI_F);
	CosParam = (float)cos(CameraVAngle / 180.0f * DX_PI_F);
	TempPosition1.x = 0.0f;
	TempPosition1.y = SinParam * CAMERA_LOOK_AT_DISTANCE;
	TempPosition1.z = -CosParam * CAMERA_LOOK_AT_DISTANCE;

	// ���ɐ����p�x�𔽉f�����ʒu���Z�o
	SinParam = (float)sin(CameraHAngle / 180.0f * DX_PI_F);
	CosParam = (float)cos(CameraHAngle / 180.0f * DX_PI_F);
	TempPosition2.x = CosParam * TempPosition1.x - SinParam * TempPosition1.z;
	TempPosition2.y = TempPosition1.y + 10;
	TempPosition2.z = (SinParam * TempPosition1.x + CosParam * TempPosition1.z) + 100;

	// �Z�o�������W�ɒ����_�̈ʒu�����Z�������̂��J�����̈ʒu
	CameraPosition = VAdd(TempPosition2, CameraLookAtPosition);
	//�^�[�Q�b�g������p�x�ɃJ������ݒu
	SetCameraPositionAndTarget_UpVecY(CameraPosition, CameraLookAtPosition);

	// �ړ������ꍇ�́A�J�����̐����p�x���l�����������ɍ��W���ړ�����
	if (player.moveFlag == TRUE)
	{
		VECTOR TempMoveVector;

		// �J�����̊p�x�ɍ��킹�Ĉړ��x�N�g������]���Ă�����Z
		SinParam = (float)sin(CameraHAngle / 180.0f * DX_PI_F);
		CosParam = (float)cos(CameraHAngle / 180.0f * DX_PI_F);
		TempMoveVector.x = player.angleX * CosParam - player.angleZ * SinParam;
		TempMoveVector.y = 0.0f;
		TempMoveVector.z = player.angleX * SinParam + player.angleZ * CosParam;

		pos = VAdd(pos, TempMoveVector);
	}
}
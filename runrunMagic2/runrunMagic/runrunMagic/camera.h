#pragma once

#include "komon.h"
class Player;
// �J�����̉�]���x
#define CAMERA_ANGLE_SPEED		3.0f

// �J�����̒����_�̍���
#define CAMERA_LOOK_AT_HEIGHT		55.0f

// �J�����ƒ����_�̋���
#define CAMERA_LOOK_AT_DISTANCE		250.0f
class Camera:public Player
{
public:
	Camera();							// �R���X�g���N�^.
	~Camera();							// �f�X�g���N�^.

	void Update(const Player& player);	                    // �X�V.

	float x, y, z;						//�J�����̈ʒu���W

	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return pos; }
	VECTOR TempPosition1;
	VECTOR TempPosition2;
	VECTOR CameraPosition;
	VECTOR CameraLookAtPosition;

private:
	VECTOR	pos;			// �|�W�V����.
	int    MoveFlag;
	float  Angle;
	float  CameraHAngle;
	float  CameraVAngle;
	float  SinParam;
	float  CosParam;

};
//-----------------------------------------------------------------------------
// @brief  �J�����N���X.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "komon.h"

//-----------------------------------------------------------------------------
// @brief  �R���X�g���N�^.
//-----------------------------------------------------------------------------
Enemy::Enemy()
{

	//�X���C���̓ǂݍ���
	modelHandle = MV1LoadModel("img/slime/slime.pmd");

	//�X���C���̏��������̒l
	angleX = 0.0f, angleY = 0.0f, angleZ = 0.0f;

	//�X���C���̏������W�̒l
	pos.x = 0.0f, pos.y = 0.0f, pos.z = 150.0f;

	//�X���C���̑傫��
	MV1SetScale(modelHandle, VGet(2.5f, 2.5f, 2.5f));

	//�X���C���̏����ʒu
	pos = VGet(pos.x, pos.y, pos.z);
}

//-----------------------------------------------------------------------------
// @brief  �f�X�g���N�^.
//-----------------------------------------------------------------------------
Enemy::~Enemy()
{
	// �����Ȃ�.
}

//--------
//�X�V
//--------
void Enemy::Updata(const Player& player)
{

	//�v���C���[��ǂ�������
	if (pos.x > player.pos.x)
	{
		pos.x--;
	}
	else if(pos.x < player.pos.x)
	{
		pos.x++;
	}

	if (pos.z > player.pos.z)
	{
		pos.z--;
	}
	else if (pos.z < player.pos.z)
	{
		pos.z++;
	}
}

//---------------
// @brief  �`��
//---------------
void Enemy::Draw()
{
	//3D���f���̌���
	MV1SetRotationXYZ(modelHandle, VGet(angleX, angleY, angleZ));

	// �RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(modelHandle, pos);

	// �R�c���f���̕`��
	MV1DrawModel(modelHandle);
}
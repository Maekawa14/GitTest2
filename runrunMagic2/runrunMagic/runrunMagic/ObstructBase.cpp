//-----------------------------------------------------------------------------
// @brief  ��Q�����N���X.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "komon.h"

#define USE_MODEL_DUPLICATE 1

//-----------------------------------------------------------------------------
// @brief  �R���X�g���N�^.
//-----------------------------------------------------------------------------
ObstructBase::ObstructBase(int sourceModelHandle)
	: modelHandle(-1)
	, hitRadius(2.0f)
{
	// �R�c���f���̓ǂݍ���
#if USE_MODEL_DUPLICATE
	modelHandle = MV1DuplicateModel(sourceModelHandle);
	if (modelHandle < 0)
	{
		printfDx("�f�[�^�ǂݍ��݂Ɏ��s. sourceId:%d", sourceModelHandle);
	}
#else
	modelHandle = MV1LoadModel("img/BackGround/Building/monshon1.x");
	if (modelHandle < 0)
	{
		printfDx("ObstructStatic:�f�[�^�ǂݍ��݂Ɏ��s");
	}
#endif
}

//-----------------------------------------------------------------------------
// @brief  �f�X�g���N�^.
//-----------------------------------------------------------------------------
ObstructBase::~ObstructBase()
{
	// ���f���̃A�����[�h.
	MV1DeleteModel(modelHandle);
}
//-----------------------------------------------------------------------------
// @brief  �`��.
//-----------------------------------------------------------------------------
void ObstructBase::Draw()
{
	// �R�c���f���̕`��
	MV1DrawModel(modelHandle);

	 //�f�o�b�O�����蔻��.
	DrawSphere3D(pos, hitRadius, 10, 0x00ffff, 0x00ffff, false);
}
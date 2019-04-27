#include "komon.h"

#define USE_ITEM_DUPLICATE 1

//-----------------------------------------------------------------------------
// @brief  �R���X�g���N�^.
//-----------------------------------------------------------------------------
GraphBase::GraphBase(int sourceModelHandle)
	: modelHandle(-1)
	, hitRadius(2.0f)
{
	// �R�c���f���̓ǂݍ���
#if USE_ITEM_DUPLICATE
	modelHandle = MV1DuplicateModel(sourceModelHandle);
	if (modelHandle < 0)
	{
		printfDx("�f�[�^�ǂݍ��݂Ɏ��s. sourceId:%d\n", sourceModelHandle);
	}
#else
	modelHandle = MV1LoadModel("img/BackGround/houseki.x");
	if (modelHandle < 0)
	{
		printfDx("ObstructStatic:�f�[�^�ǂݍ��݂Ɏ��s\n");
	}
#endif
}

//-----------------------------------------------------------------------------
// @brief  �f�X�g���N�^.
//-----------------------------------------------------------------------------
GraphBase::~GraphBase()
{
	// ���f���̃A�����[�h.
	MV1DeleteModel(modelHandle);
}
//-----------------------------------------------------------------------------
// @brief  �`��.
//-----------------------------------------------------------------------------
void GraphBase::Draw()
{
	// �R�c���f���̕`��
	MV1DrawModel(modelHandle);

	//�f�o�b�O�����蔻��.
	//DrawSphere3D(pos, hitRadius, 10, 0x00ffff, 0x00ffff, false);
}
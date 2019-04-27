//-----------------------------------------------------------------------------
// @brief  ��Q���F�����Ȃ�.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "komon.h"

//-----------------------------------------------------------------------------
// @brief  �R���X�g���N�^
//-----------------------------------------------------------------------------
ObstructStatic::ObstructStatic(int sourceModelHandle)
	: ObstructBase(sourceModelHandle)
{
	pos = VGet(0, 0, -10);
	hitRadius = 2.0f;   //�����蔻��͈̔�

	//3D���f���Ŏg�p���Ă���}�e���A���̐����擾����
	int MaterialNum = MV1GetMaterialNum(modelHandle);

	for (int i = 0; i < MaterialNum; i++)
	{
		// �}�e���A���̗֊s���̑������擾  
		float dotwidth = MV1GetMaterialOutLineDotWidth(modelHandle, i);
		// �}�e���A���̗֊s���̑������g�債��������������  
		MV1SetMaterialOutLineDotWidth(modelHandle, i, dotwidth / 50.0f);
	}
}

//-----------------------------------------------------------------------------
// @brief  �f�X�g���N�^.
//-----------------------------------------------------------------------------
ObstructStatic::~ObstructStatic()
{
	// �����Ȃ�.
}

//-----------------------------------------------------------------------------
// @brief  �X�V.
//-----------------------------------------------------------------------------
void ObstructStatic::Update()
{

	//3D���f���̑傫��
	MV1SetScale(modelHandle, VGet(120.0f, 25.0f, 25.0f));
	// �RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(modelHandle, pos);
}

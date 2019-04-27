#include "komon.h"

//-----------------------------------------------------------------------------
// @brief  �R���X�g���N�^
//-----------------------------------------------------------------------------
DonutStatic::DonutStatic(int sourceModelHandle)
	: DonutBase(sourceModelHandle)
{
	pos = VGet(5000.0f, 0.0f, 0.0f);
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
DonutStatic::~DonutStatic()
{
	// �����Ȃ�.
}

//-----------------------------------------------------------------------------
// @brief  �X�V.
//-----------------------------------------------------------------------------
void DonutStatic::Update()
{

	//3D���f���̑傫��
	MV1SetScale(modelHandle, VGet(7.0f, 7.0f, 7.0f));
	// �RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(modelHandle, pos);
}

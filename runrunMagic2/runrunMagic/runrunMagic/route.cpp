#include "komon.h"

Route::Route()
{
	//�����ʒu

	//���f���̓ǂݍ���
	modelHandle = MV1LoadModel("img/BackGround/Building/monshon1.x");


	//3D���f���̑傫��
	MV1SetScale(modelHandle, VGet(120.0f, 25.0f, 25.0f));

    //���̂̑傫��
    radius = 104;

	//3D���f���Ŏg�p���Ă���}�e���A���̐����擾����
	MaterialNum = MV1GetMaterialNum(modelHandle);

	for (int i = 0; i < MaterialNum; i
		++)
	{
		// �}�e���A���̗֊s���̑������擾  
		float dotwidth = MV1GetMaterialOutLineDotWidth(modelHandle, i);
		// �}�e���A���̗֊s���̑������g�債��������������  
		MV1SetMaterialOutLineDotWidth(modelHandle, i, dotwidth / 50.0f);
	}

	for (int i = 0; i <= LINE_ROUTE_COL; i++)
	{

		// �RD���f���̃|�W�V�����ݒ�
		MV1SetPosition(modelHandle, pos[i]);
	}

}

Route::~Route()
{

	//�C�e���[�^�[���g���ׂ�
	//�C�e���[�^�[���g���ׂ�

	//���f���̃A�����[�h
	MV1DeleteModel(modelHandle);
}

void Route::Update()
{
	//printfDx("route.y : %f\n", pos[1].y);
	//pos[1].y++;
}

void Route::Drow()
{
	// �R�c���f���̕`��
	MV1DrawModel(modelHandle);
}

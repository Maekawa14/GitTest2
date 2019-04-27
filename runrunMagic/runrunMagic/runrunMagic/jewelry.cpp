#include "komon.h"

Jewelry::Jewelry()
{
	//�����ʒu
	pos[0] = VGet(110.0, 93.0, 0.0);
	pos[1] = VGet(100, 93.0, 0.0);
	pos[2] = VGet(83.0, 93.0, 0.0);
	pos[3] = VGet(66.0, 93.0, 0.0);

	//���̂̑傫��
	radius = 2;
	for (int i = 0; i < LINE_JEWEL_COL; i++)
	{
		//���f���̓ǂݍ���
		modelHandle[i] = MV1LoadModel("img/BackGround/Building/houseki.x");

		//3D���f���̑傫��
		MV1SetScale(modelHandle[i], VGet(2.0f, 2.0f, 2.0f));

		// 3D���f���̃|�W�V�����ݒ�
		MV1SetPosition(modelHandle[i], pos[i]);

		//3D���f���Ŏg�p���Ă���}�e���A���̐����擾����
		MaterialNum[i] = MV1GetMaterialNum(modelHandle[i]);

		for (int j = 0; j < MaterialNum[i]; j++)
		{
			// �}�e���A���̗֊s���̑������擾  
			float dotwidth = MV1GetMaterialOutLineDotWidth(modelHandle[i], i);
			// �}�e���A���̗֊s���̑������g�債��������������  
			MV1SetMaterialOutLineDotWidth(modelHandle[i], i, dotwidth / 50.0f);
		}
	}
}

Jewelry::~Jewelry()
{
	for (int i = 0; i < LINE_JEWEL_COL; i++)
	{
		//���f���̃A�����[�h
		MV1DeleteModel(modelHandle[i]);
	}
}

void Jewelry::Update()
{
}

void Jewelry::Drow()
{
	for (int i = 0; i < LINE_JEWEL_COL; i++)
	{
		// �R�c���f���̕`��
		MV1DrawModel(modelHandle[i]);
	}
}

void Jewelry::PlayerHit(Player& player, Gauge& gauge)
{
	for (int i = 0; i < LINE_JEWEL_COL; i++)
	{
		playerHitDown = pos[i].x > player.pos.x - 2;
		playerHitUp = pos[i].x < (player.pos.x + 2) + radius;
		if (playerHitUp && playerHitDown)
		{
			printfDx("Hit\n");
			modelHandle[i] = NULL;
			gauge.MPGX2 += 0.1f;
			break;
		}
	}
}
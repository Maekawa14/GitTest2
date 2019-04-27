//-----------------------------------------------------------------------------
// @brief  ��Q���}�l�[�W���[.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "komon.h"

//-----------------------------------------------------------------------------
// @brief  �R���X�g���N�^.f
//-----------------------------------------------------------------------------
ObstructManager::ObstructManager()
	:  staticModelSourceHandle(-1)
{
	count = 0;

	for (int i = 0; i < LINE_ROUTE_RAW; i++)
	{
		for (int j = 0; j < LINE_ROUTE_COL; j++)
		{
			obstructs[i][j] = NULL;
		}
	}
}

//-----------------------------------------------------------------------------
// @brief  �f�X�g���N�^.
//-----------------------------------------------------------------------------
ObstructManager::~ObstructManager()
{
	// �����Ȃ�.
}

//-----------------------------------------------------------------------------
// @brief  ��Q������.
//-----------------------------------------------------------------------------
void ObstructManager::CreateObstructs()
{
	//printfDx("Hit!\n");

	//�}���V�����̃��f���ǂݍ���
	staticModelSourceHandle = MV1LoadModel("img/BackGround/Building/monshon1.x");

	// ��Q���̔z�u�}�f�[�^�Ƃ��Ă�linemap��p�ӂ���.
	int map0[LINE_ROUTE_COL]  = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
	int* lineMap[LINE_ROUTE_RAW] =
	{
		map0,
	};

	for (int i = 0; i < LINE_ROUTE_RAW; i++)
	{
		int* nowLine = lineMap[i];
		for (int j = 0; j < LINE_ROUTE_COL; j++)
		{
			// linemap�ɓ����Ă��鐔�l�ɂ���ď�Q���̎�ނ����肷��.
			if (nowLine[j] == 1)
			{
				obstructs[i][j] = new ObstructStatic(staticModelSourceHandle);
			}
			else
			{
				obstructs[i][j] = NULL;
			}

			// �ʒu�̏�����.
			if (obstructs[i][j] != NULL)
			{
				obstructs[i][j]->SetPos(
					VGet(
						(OBSTRUCT_SPACE_W * j) - (OBSTRUCT_SPACE_W * LINE_ROUTE_COL * 0.5f),
						(OBSTRUCT_SPACE_D * LINE_ROUTE_RAW) - (OBSTRUCT_SPACE_D * i)+ 60,
						0.0f)
					);
			}
		}
	}

}

//-----------------------------------------------------------------------------
// @brief  ��Q���폜.
//-----------------------------------------------------------------------------
void ObstructManager::DestroyObstructs()
{

	for (int i = 0; i < LINE_ROUTE_RAW; i++)
	{
		for (int j = 0; j < LINE_ROUTE_COL; j++)
		{
			if (obstructs[i][j] != NULL)
			{
				delete(obstructs[i][j]);
				obstructs[i][j] = NULL;
			}
		}
	}
	MV1DeleteModel(staticModelSourceHandle);
}

//-----------------------------------------------------------------------------
// @brief  �X�V.
//-----------------------------------------------------------------------------
void ObstructManager::Update()
{
	for (int i = 0; i < LINE_ROUTE_RAW; i++)
	{
		for (int j = 0; j < LINE_ROUTE_COL; j++)
		{
			if (obstructs[i][j] != NULL)
			{
				obstructs[i][j]->Update();
			}
		}
	}
}

//-----------------------------------------------------------------------------
// @brief  �`��.
//-----------------------------------------------------------------------------
void ObstructManager::Draw()
{
	for (int i = 0; i < LINE_ROUTE_RAW; i++)
	{
		for (int j = 0; j < LINE_ROUTE_COL; j++)
		{
			if (obstructs[i][j] != NULL)
			{
				obstructs[i][j]->Draw();
			}
		}
	}
}

//-----------------------------------------------------------------------------
// @brief  �w��ԍ��̏�Q�����擾.
//-----------------------------------------------------------------------------
ObstructBase* ObstructManager::GetObstruct(int raw, int col)
{
	return obstructs[raw][col];
}

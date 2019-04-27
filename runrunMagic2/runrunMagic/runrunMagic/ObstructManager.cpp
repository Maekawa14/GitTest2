//-----------------------------------------------------------------------------
// @brief  障害物マネージャー.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "komon.h"

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.f
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
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
ObstructManager::~ObstructManager()
{
	// 処理なし.
}

//-----------------------------------------------------------------------------
// @brief  障害物生成.
//-----------------------------------------------------------------------------
void ObstructManager::CreateObstructs()
{
	//printfDx("Hit!\n");

	//マンションのモデル読み込み
	staticModelSourceHandle = MV1LoadModel("img/BackGround/Building/monshon1.x");

	// 障害物の配置図データとしてのlinemapを用意する.
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
			// linemapに入っている数値によって障害物の種類を決定する.
			if (nowLine[j] == 1)
			{
				obstructs[i][j] = new ObstructStatic(staticModelSourceHandle);
			}
			else
			{
				obstructs[i][j] = NULL;
			}

			// 位置の初期化.
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
// @brief  障害物削除.
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
// @brief  更新.
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
// @brief  描画.
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
// @brief  指定番号の障害物を取得.
//-----------------------------------------------------------------------------
ObstructBase* ObstructManager::GetObstruct(int raw, int col)
{
	return obstructs[raw][col];
}

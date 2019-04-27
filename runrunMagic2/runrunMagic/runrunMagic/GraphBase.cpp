#include "komon.h"

#define USE_ITEM_DUPLICATE 1

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
GraphBase::GraphBase(int sourceModelHandle)
	: modelHandle(-1)
	, hitRadius(2.0f)
{
	// ３Ｄモデルの読み込み
#if USE_ITEM_DUPLICATE
	modelHandle = MV1DuplicateModel(sourceModelHandle);
	if (modelHandle < 0)
	{
		printfDx("データ読み込みに失敗. sourceId:%d\n", sourceModelHandle);
	}
#else
	modelHandle = MV1LoadModel("img/BackGround/houseki.x");
	if (modelHandle < 0)
	{
		printfDx("ObstructStatic:データ読み込みに失敗\n");
	}
#endif
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
GraphBase::~GraphBase()
{
	// モデルのアンロード.
	MV1DeleteModel(modelHandle);
}
//-----------------------------------------------------------------------------
// @brief  描画.
//-----------------------------------------------------------------------------
void GraphBase::Draw()
{
	// ３Ｄモデルの描画
	MV1DrawModel(modelHandle);

	//デバッグあたり判定.
	//DrawSphere3D(pos, hitRadius, 10, 0x00ffff, 0x00ffff, false);
}
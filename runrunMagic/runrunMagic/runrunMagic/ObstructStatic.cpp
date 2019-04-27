//-----------------------------------------------------------------------------
// @brief  障害物：動かない.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "komon.h"

//-----------------------------------------------------------------------------
// @brief  コンストラクタ
//-----------------------------------------------------------------------------
ObstructStatic::ObstructStatic(int sourceModelHandle)
	: ObstructBase(sourceModelHandle)
{
	pos = VGet(0, 0, -10);
	hitRadius = 2.0f;   //当たり判定の範囲

	//3Dモデルで使用しているマテリアルの数を取得する
	int MaterialNum = MV1GetMaterialNum(modelHandle);

	for (int i = 0; i < MaterialNum; i++)
	{
		// マテリアルの輪郭線の太さを取得  
		float dotwidth = MV1GetMaterialOutLineDotWidth(modelHandle, i);
		// マテリアルの輪郭線の太さを拡大した分小さくする  
		MV1SetMaterialOutLineDotWidth(modelHandle, i, dotwidth / 50.0f);
	}
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
ObstructStatic::~ObstructStatic()
{
	// 処理なし.
}

//-----------------------------------------------------------------------------
// @brief  更新.
//-----------------------------------------------------------------------------
void ObstructStatic::Update()
{

	//3Dモデルの大きさ
	MV1SetScale(modelHandle, VGet(120.0f, 25.0f, 25.0f));
	// ３Dモデルのポジション設定
	MV1SetPosition(modelHandle, pos);
}

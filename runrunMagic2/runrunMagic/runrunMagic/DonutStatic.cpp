#include "komon.h"

//-----------------------------------------------------------------------------
// @brief  コンストラクタ
//-----------------------------------------------------------------------------
DonutStatic::DonutStatic(int sourceModelHandle)
	: DonutBase(sourceModelHandle)
{
	pos = VGet(5000.0f, 0.0f, 0.0f);
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
DonutStatic::~DonutStatic()
{
	// 処理なし.
}

//-----------------------------------------------------------------------------
// @brief  更新.
//-----------------------------------------------------------------------------
void DonutStatic::Update()
{

	//3Dモデルの大きさ
	MV1SetScale(modelHandle, VGet(7.0f, 7.0f, 7.0f));
	// ３Dモデルのポジション設定
	MV1SetPosition(modelHandle, pos);
}

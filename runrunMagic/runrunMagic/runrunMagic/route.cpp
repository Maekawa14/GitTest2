#include "komon.h"

Route::Route()
{
	//初期位置

	//モデルの読み込み
	modelHandle = MV1LoadModel("img/BackGround/Building/monshon1.x");


	//3Dモデルの大きさ
	MV1SetScale(modelHandle, VGet(120.0f, 25.0f, 25.0f));

    //物体の大きさ
    radius = 104;

	//3Dモデルで使用しているマテリアルの数を取得する
	MaterialNum = MV1GetMaterialNum(modelHandle);

	for (int i = 0; i < MaterialNum; i
		++)
	{
		// マテリアルの輪郭線の太さを取得  
		float dotwidth = MV1GetMaterialOutLineDotWidth(modelHandle, i);
		// マテリアルの輪郭線の太さを拡大した分小さくする  
		MV1SetMaterialOutLineDotWidth(modelHandle, i, dotwidth / 50.0f);
	}

	for (int i = 0; i <= LINE_ROUTE_COL; i++)
	{

		// ３Dモデルのポジション設定
		MV1SetPosition(modelHandle, pos[i]);
	}

}

Route::~Route()
{

	//イテレーターを使うべし
	//イテレーターを使うべし

	//モデルのアンロード
	MV1DeleteModel(modelHandle);
}

void Route::Update()
{
	//printfDx("route.y : %f\n", pos[1].y);
	//pos[1].y++;
}

void Route::Drow()
{
	// ３Ｄモデルの描画
	MV1DrawModel(modelHandle);
}

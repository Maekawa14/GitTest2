#include "komon.h"

Jewelry::Jewelry()
{
	//初期位置
	pos[0] = VGet(110.0, 93.0, 0.0);
	pos[1] = VGet(100, 93.0, 0.0);
	pos[2] = VGet(83.0, 93.0, 0.0);
	pos[3] = VGet(66.0, 93.0, 0.0);

	//物体の大きさ
	radius = 2;
	for (int i = 0; i < LINE_JEWEL_COL; i++)
	{
		//モデルの読み込み
		modelHandle[i] = MV1LoadModel("img/BackGround/Building/houseki.x");

		//3Dモデルの大きさ
		MV1SetScale(modelHandle[i], VGet(2.0f, 2.0f, 2.0f));

		// 3Dモデルのポジション設定
		MV1SetPosition(modelHandle[i], pos[i]);

		//3Dモデルで使用しているマテリアルの数を取得する
		MaterialNum[i] = MV1GetMaterialNum(modelHandle[i]);

		for (int j = 0; j < MaterialNum[i]; j++)
		{
			// マテリアルの輪郭線の太さを取得  
			float dotwidth = MV1GetMaterialOutLineDotWidth(modelHandle[i], i);
			// マテリアルの輪郭線の太さを拡大した分小さくする  
			MV1SetMaterialOutLineDotWidth(modelHandle[i], i, dotwidth / 50.0f);
		}
	}
}

Jewelry::~Jewelry()
{
	for (int i = 0; i < LINE_JEWEL_COL; i++)
	{
		//モデルのアンロード
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
		// ３Ｄモデルの描画
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
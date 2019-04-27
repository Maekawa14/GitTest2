#include "komon.h"

Nanji::Nanji()
{
	//プレイヤーの初期位置
	pos[0] = VGet(-100.0f, 30.0f, 0.0f);
	pos[1] = VGet(-230.0f, 30.0f, 0.0f);
	pos[3] = VGet(-730.0f, 30.0f, 0.0f);
	pos[4] = VGet(-1030.0f, 30.0f, 0.0f);
	pos[5] = VGet(-1530.0f, 30.0f, 0.0f);
	pos[6] = VGet(-2430.0f, 30.0f, 0.0f);
	pos[7] = VGet(-3390.0f, 30.0f, 0.0f);

	radius = 30.0f;

	for (int i = 0; i < 8; i++)
	{
		//3Dモデルの読み込み
		modelHandle[i] = MV1LoadModel("img/BackGround/nanji.x");
	}
}

void Nanji::Update(Player& player)
{

	for (int i = 0; i < 8; i++)
	{
		// ３Ｄモデルの描画
		MV1DrawModel(modelHandle[i]);

		// プレイヤーから針山までの現在の距離
		distanceX = pos[i].x - player.pos.x;
		distanceY = pos[i].y - player.pos.y;

		// 判定の距離:今回は広めにとる
		hitRadius = (radius + 65) + player.radius;

		// プレイヤーと針山の距離が近くなれば実行
		if ((distanceX * distanceX + distanceY * distanceY) < hitRadius * hitRadius)
		{
			// プレイヤーが近づいてきたら針山が出現
			if (pos[i].y < 53)
			{
				pos[i].y += 3.0f;
			}
		}

		// ３Dモデルのポジション設定
		MV1SetPosition(modelHandle[i], pos[i]);
	
		//3Dモデルの大きさ
		MV1SetScale(modelHandle[i], VGet(10.0f, 10.0f, 10.0f));
	}
}

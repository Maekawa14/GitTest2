//-----------------------------------------------------------------------------
// @brief  ヒットチェック.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------

#include "komon.h"

//-----------------------------------------------------------------------------
// @brief  ヒットチェック処理.
//-----------------------------------------------------------------------------


HitChecker::HitChecker()
{
	isPlayerGroundLeft = false;    // 地面あたり判定（プレイヤーは左に居る状態）
	isPlayerGroundRight = false;   // 地面あたり判定（プレイヤーは右に居る状態）

	isPlayerJewelryLeft = false;   // 地面あたり判定（プレイヤーは左に居る状態）
	isPlayerJewelryLeft = false;   // 地面あたり判定（プレイヤーは右に居る状態）

	isPlayerNanjiLeft   = false;   // 針あたり判定（プレイヤーは左に居る状態）
	isPlayerNanjiRight  = false;   // 針あたり判定（プレイヤーは右に居る状態）
	isPlayerNanjiUp     = false;   // 針あたり判定（プレイヤーは上に居る状態）

	isPlayerDonutLeft = false;			//ドーナツあたり判定（プレイヤーは左に居る状態）
	isPlayerDonutRight = false;			//ドーナツあたり判定（プレイヤーは右に居る状態）
	isPlayerDonutUp = false;			//ドーナツあたり判定（プレイヤーは上に居る状態）
	isPlayerDonutDown = false;			//ドーナツあたり判定（プレイヤーは上に居る状態）
	isPlayerDonutUp2 = false;			//ドーナツあたり判定（プレイヤーは上に居る状態）
	isPlayerDonutDown2 = false;			//ドーナツあたり判定（プレイヤーは上に居る状態）
	HitDonutLower = false;

	damageFlag = false;			   // ダメージを受けたフラグ管理
	damageFlag2 = false;			   // ダメージを受けたフラグ管理

	count = 0;
}

void HitChecker::PlayerGround(Player& player, ObstructManager& obstructManager)
{
	bool isHit = false;
	//----------------
	// 地面の当たり判定
	//----------------

	for (int i = 0; i < LINE_ROUTE_COL; i++)
	{
		for (int j = 0; j < LINE_ROUTE_RAW; j++)
		{
			//マップチップの座標を取得する
			ObstructBase* obstruct = obstructManager.GetObstruct(j, i);

			if (obstruct != NULL)
			{
				// 地面（左側）とプレイヤーの当たり判定
				isPlayerGroundLeft = player.pos.x > obstruct->GetPos().x - 252.5f;

				// 地面（右側）とプレイヤーの当たり判定
				isPlayerGroundRight = player.pos.x < ((obstruct->GetPos().x + 252.5f) + player.radius);

				if (isPlayerGroundLeft && isPlayerGroundRight && player.jumpFlag != true)
				{
					DrawFormatString(550, 50, GetColor(255, 255, 255), "HIT!");
					isHit = true;
					break;
				}
			}
		}
	}

	// isHitフラグがtrueかつジャンプしていない場合
	// プレイヤーが落下する
	if (!isHit && !player.jumpFlag)
	{
		//地面から出たら落下
		//player.pos.y -= 5;
		DrawFormatString(500, 50, GetColor(255, 255, 255), "NoHit!");
	}
}



void HitChecker::PlayerJewelry(Player& player, GraphManager& graphManager, Gauge& gauge)
{
	//------------------
	//宝石の当たり判定
	//------------------
	VECTOR yZeroPlayer = VGet(player.GetPos().x, 0, player.GetPos().z);

	for (int i = 0; i < LINE_GRAPH_COL; i++)
	{
		for (int j = 0; j < LINE_GRAPH_RAW; j++)
		{
			//マップチップの座標を取得する
			GraphBase* graph = graphManager.GetGraph(j, i);
			//GraphBase* deleteGraph = graphManager.GetGraph(j, i);
			if (graph != NULL)
			{
				// 宝石（左側）とプレイヤーの当たり判定
				isPlayerJewelryLeft = player.pos.x > graph->GetPos().x - 2.0f;

				// 宝石（右側）とプレイヤーの当たり判定
				isPlayerJewelryRight = player.pos.x < ((graph->GetPos().x + 2.0f) + player.radius);

				// 宝石（右側）とプレイヤーの当たり判定
				isPlayerJewelryUp = player.pos.y < graph->GetPos().y;


				if (isPlayerJewelryLeft && isPlayerJewelryRight 
					&& isPlayerJewelryUp && !player.feverFlag)
				{
					DrawFormatString(500, 100, GetColor(255, 255, 255), "ItemHIT!");

					//魔法ゲージを加算する
					gauge.MPGX2 += 10.0f;

					//レイヤーが当たった宝石を消す
					graphManager.Delete(j, i);

					//ループから抜けだす
					break;
				}
			}
		}
	}
}

void HitChecker::PlayerNanji(Player& player, Nanji& nanji, Gauge& gauge)
{
	//----------------
	// 針の当たり判定
	//----------------

	for (int i = 0; i < 8; i++)
	{
		// 針（左側）とプレイヤーの当たり判定
		isPlayerNanjiLeft = player.pos.x > nanji.pos[i].x - nanji.radius;

		// 針（右側）とプレイヤーの当たり判定
		isPlayerNanjiRight = player.pos.x < ((nanji.pos[i].x + nanji.radius) + player.radius);

		// 針（上側）とプレイヤーの当たり判定
		isPlayerNanjiUp = player.pos.y < nanji.pos[i].y;

		//針山と当たり判定内容
		if (isPlayerNanjiLeft && isPlayerNanjiRight && isPlayerNanjiUp && !damageFlag)
		{
			DrawFormatString(550, 280, GetColor(0, 0, 255), "HIT!");
			// 針山に当たったら体力を3割り減らす
			gauge.HPGX2 = gauge.HPGX2 - (gauge.HPGX2 / 30);

			break;
		}
	}

}

void HitChecker::PlayerDornatsu(Player& player, DonutManager& donutManager, Gauge& gauge)
{
	//------------------
	//ドーナツの当たり判定
	//------------------
	VECTOR yZeroPlayer = VGet(player.GetPos().x, 0, player.GetPos().z);

	for (int i = 0; i < LINE_GRAPH_COL; i++)
	{
		for (int j = 0; j < LINE_GRAPH_RAW; j++)
		{
			//マップチップの座標を取得する
			DonutBase* donut = donutManager.GetGraph(j, i);
			if (donut != NULL)
			{
				// ドーナツ（左側）とプレイヤーの当たり判定
				isPlayerDonutLeft = player.pos.x > donut->GetPos().x - 5.0f;

				// ドーナツ（右側）とプレイヤーの当たり判定
				isPlayerDonutRight = player.pos.x < ((donut->GetPos().x + 5.0f) + player.radius);

				// ドーナツ（上側）とプレイヤーの当たり判定
				isPlayerDonutUp = player.pos.y > donut->GetPos().y - 5.0f;

				if (isPlayerDonutUp)
				{
					HitDonutLower = true;
				}
				else
				{
					HitDonutLower = false;
				}

				if (isPlayerDonutLeft && isPlayerDonutRight && HitDonutLower)
				{
					DrawFormatString(550, 200, GetColor(255, 255, 255), "DonutHIT!");
					//魔法ゲージを加算する
					gauge.HPGX2 += 10.0f;

					// ドーナツに当たったら当たったドーナツを消す
					donutManager.Delete(j, i);
					break;
				}
			}
		}
	}
}

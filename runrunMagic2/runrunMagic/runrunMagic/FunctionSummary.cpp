#include "komon.h"

void FunctionSummary::Update(ObstructManager& obstructManager, GraphManager& graphManager, DonutManager& donutManager, Nanji& nanji,
							 Player& player, Camera& camera, HitChecker& hitChecker, KeyState& keyState,
							 Gauge& gauge, CountDown& countDown)
{
	//ゲーム開始カウントダウン
	countDown.Update();
	// 障害物制御
	obstructManager.Update();
	// 障害物描画
	obstructManager.Draw();

	// 宝石描画
	graphManager.Draw(hitChecker);

	// ドーナツを描画
	donutManager.Draw(hitChecker);

	// プレイヤー描画
	player.Draw(hitChecker);

	//プレイヤーのアニメーション
	player.Motion();

	//針山描画
	nanji.Update(player);

	//ゲージの描画
	gauge.Update();

	// カメラ制御
	camera.Update(player);
	if (countDown.GameStart)
	{
		//キーボード制御
		keyState.UpDateKey(); 

		// 宝石制御
		graphManager.Update();

		// ドーナツ制御
		donutManager.Update();
		// プレイヤー制御.
		player.Update(keyState);

		// プレイヤーの動き
		player.Move();

		// プレイヤーがジャンプ
		player.Jump();

		//フィーバータイム
		player.Fever(gauge);

		// ヒットのチェック
		hitChecker.PlayerGround(player, obstructManager);
		hitChecker.PlayerJewelry(player, graphManager, gauge);

		hitChecker.PlayerNanji(player, nanji, gauge);
		hitChecker.PlayerDornatsu(player, donutManager, gauge);

		// HPが減少する
		gauge.DecreaseHP();

		// HP,MPがゲージより超えないようにする
		gauge.Limit();

		// フィーバータイムのフラグ操作
		gauge.Fever(player);
	}
}

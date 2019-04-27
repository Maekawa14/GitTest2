
//---------------------------------------------------------------------------
// @brief  メイン処理.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "komon.h"

//-----------------------------------------------------------------------------
// @brief  メイン関数.
//-----------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    ChangeWindowMode(TRUE);
	
    // ＤＸライブラリ初期化処理
    if (DxLib_Init() == -1)
    {
        return -1;	// エラーが起きたら直ちに終了
    }
    
    // 画面モードのセット
	SetGraphMode(640, 480, 16);
	//SetGraphMode(1920, 1080, 16);
	SetDrawScreen(DX_SCREEN_BACK);

	// 障害物を生成.
	ObstructManager* obstructManager = new ObstructManager();
	obstructManager->CreateObstructs();

	// アイテムや宝石を生成.
	GraphManager* graphManager = new GraphManager();
	graphManager->CreateGraph();

	// アイテムや宝石を生成.
	DonutManager* donutManager = new DonutManager();
	donutManager->CreateGraph();

	//針山を生成
	Nanji* nanji = new Nanji();


	// プレイヤーを生成.
	Player* player = new Player();

	// カメラを生成.
	Camera* camera = new Camera();

	//当たり判定処理
	HitChecker* hitChecker = new HitChecker();

	//キーボードの押したかどうかを生成
	KeyState*  keyState = new KeyState();

	//ゲージを生成
	Gauge* gauge = new Gauge();

	//	関数をまとめ
	FunctionSummary* functionSummary = new FunctionSummary();

	//	カウントダウン
	CountDown* countDown = new CountDown();
	keyState->InitKey();

	// エスケープキーが押されるかウインドウが閉じられるまでループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// 画面を初期化する
		ClearDrawScreen();

		// Ｘ軸のマイナス方向のディレクショナルライトに変更
		ChangeLightTypeDir(VGet(-1.0f, -5.0f, 1.0f));

		//ゲームメイン
		functionSummary->Update(*obstructManager, *graphManager,*donutManager, *nanji,
			*player, *camera, *hitChecker, *keyState, *gauge, *countDown);

		// 裏画面の内容を表画面に反映させる
		ScreenFlip();
	}

	// 障害物を削除
	obstructManager->DestroyObstructs();
	delete(obstructManager);

	// アイテムや宝石を削除
	graphManager->DestroyGraph();
	delete(graphManager);

	// 針山を削除
	delete(nanji);

	// プレイヤーを削除
	delete(player);

	// カメラを削除.
	delete(camera);

	//当たり判定を削除
	delete(hitChecker);

	//キー入力を削除
	delete(keyState);

	//ゲージを削除
	delete(gauge);
	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}
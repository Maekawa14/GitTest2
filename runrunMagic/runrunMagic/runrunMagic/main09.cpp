#include "input.h"
// WinMain関数


//文字表示だけ!!!!!!!!!
int color = GetColor(255, 255, 255);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	//---------
	//設定
	//---------
	ChangeWindowMode(TRUE);  //ウィンドウモード有

	// 画面モードの設定
	SetGraphMode(900, 600, 32);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;
	}


	//プリロード開始
	SetDrawScreen(DX_SCREEN_BACK);

	initKey();

	while (1)
	{
		// 画面を初期化(真っ黒にする)
		ClearDrawScreen();


		upDateKey();

		//スペースキーの状態
		switch ( getKey(KEY_INPUT_SPACE) )
		{
		case KEY_STATE_OFF:
			DrawFormatString(70, 230, color, "OFF");
			printf("OFF");
			break;
		case KEY_STATE_PUSHDOWN :
			DrawFormatString(70, 230, color, "今押しています");
			printf("今押しています");
			break;
		case KEY_STATE_PRESSED:
			DrawFormatString(70, 230, color, "ずっと押されています");
			printf("ずっと押されています");
			break;
		case KEY_STATE_PULLUP:
			DrawFormatString(70, 230, color, "キーが離れました");
			printf("キーが離れました");
			break;
	
		}

		// 裏画面の内容を表画面にコピーする
		ScreenFlip();


		// Windows 特有の面倒な処理をＤＸライブラリにやらせる
		// -1 が返ってきたらループを抜ける
		if (ProcessMessage() < 0) break;

		// もしＥＳＣキーが押されていたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

	}


	// ＤＸライブラリ使用の終了処理
	DxLib_End();


	// ソフトの終了
	return 0;
}

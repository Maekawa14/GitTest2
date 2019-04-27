#include "komon.h"

CountDown::CountDown()
{
	count = 3.0;
	GameStart = false;
}

void CountDown::Update()
{
	//カウントダウン
	count -= 0.01f;

	//カウントダウンが0になったらゲームスタート
	if (count < 0.0f)
	{
		count = 0.0f;
		GameStart = true;
	}
	printfDx("CountDown: %.0f\n", count);
}

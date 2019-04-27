#include "gauge.h"

Gauge::Gauge()
{

	//体力枠の初期値
	HPX = 10.0f;
	HPY = 10.0f;
	HPX2 = 210.0f;
	HPY2 = 30.0f;
	HPGX2 = 210.0f;

	//体力ゲージの枠色
	HPframeColor = GetColor(255, 255, 255);

	//体力ゲージの色(ピンク)
	HPColor = GetColor(255, 40, 166);


	//マジックポイント枠の初期値
	MPX = 10.0f;
	MPY = 50.0f;
	MPX2 = 210.0f;
	MPY2 = 70.0f;
	MPGX2 = 10.0f;

	//体力ゲージの枠色
	MPframeColor = GetColor(255, 255, 255);

	//マジックポイントのゲージ（水色）
	MPColor = GetColor(54, 201, 203);
}

void Gauge::Update()
{
	//体力ゲージ
	DrawBox((int)HPX, (int)HPY, (int)HPGX2, (int)HPY2,
		HPColor, TRUE);

	//体力ゲージの枠
	DrawBox((int)HPX, (int)HPY, (int)HPX2, (int)HPY2,
		HPframeColor, FALSE);

	//マジックポイントゲージ
	DrawBox((int)MPX, (int)MPY, (int)MPGX2, (int)MPY2,
		MPColor, TRUE);

	//マジックポイントゲージの枠
	DrawBox((int)MPX, (int)MPY, (int)MPX2, (int)MPY2,
		MPframeColor, FALSE);
}

void Gauge::DecreaseHP()
{
	//HPゲージの減少
	HPGX2 -= 0.2f;
}

void Gauge::Limit()
{
	// 体力ゲージの幅より上回らないようにする
	if (HPGX2 > 210.0f)
	{
		HPGX2 = 210.0f;
	}

	//体力ゲージの幅より下回らないようにする
	if (HPGX2 < 11.0f)
	{
		HPGX2 = 11.0f;
		DrawFormatString(550, 120, GetColor(255, 0, 0), "GAME OVER!");
	}

	//魔法ゲージの幅より上回らないようにする
	if (MPGX2 > 210.0)
	{
		MPGX2 = 210.0f;
	}
}

void Gauge::Fever(Player& player)
{
	// MPゲージがマックスになったら
	// フィーバータイムのフラグをtrueにする
	if (MPGX2 > 210.0)
	{
		player.feverFlag = true;
	}
}

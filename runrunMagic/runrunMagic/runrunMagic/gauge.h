#pragma once

#include  "komon.h"
class Gauge
{
public:
	Gauge();				//コンストラクタ
	~Gauge() {};			//デストラクタ
	void Update();	
	void DecreaseHP();		//HP減少
	void Limit();			//ゲージの上限下限
	void Fever(Player& player);			//フィーバー中の処理
	
	float HPGX2;			//体力ゲージの座標(MAX 200)
	float MPGX2;			//マジックポイントゲージの座標(MAX 200)
							//ゲージ増加をしなくなる
	bool stopDecrease;
private:
	float HPX, HPY, HPX2, HPY2;	//体力ゲージの枠座標
	int HPframeColor;			//体力ゲージの枠色
	int HPColor;				//体力ゲージの色

	float MPX, MPY, MPX2, MPY2;	//マジックポイントのゲージの枠座標
	int MPframeColor;			//マジックポイントゲージの枠色
	int MPColor;				//マジックポイントゲージの色

};
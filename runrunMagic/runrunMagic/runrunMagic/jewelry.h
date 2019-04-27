#pragma once
#include "komon.h"

//宝石の数
#define LINE_JEWEL_COL 5	//列
#define LINE_JEWEL_RAW 1	//行

class Player;
class Gauge;

class Jewelry
{
public:
	Jewelry();				// コンストラクタ.
	~Jewelry();				// デストラクタ.
	void Update();
	void Drow();
	void PlayerHit(Player& player, Gauge& gauge);
	
	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos[ LINE_JEWEL_COL ]; }
	void SetPos(const VECTOR set) { pos[ LINE_JEWEL_COL ] = set; }

	VECTOR pos[ LINE_JEWEL_COL ];

	float radius;
private:
	int modelHandle[ LINE_JEWEL_COL ];
	int x;			//X座標の初期値
	int MaterialNum[ LINE_JEWEL_COL ];
	float interval;//オブジェクト同士の間隔

	bool playerHitUp;
	bool playerHitDown;
};
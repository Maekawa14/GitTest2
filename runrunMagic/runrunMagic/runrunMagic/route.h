#pragma once

#include "komon.h"


// 道の数.
//#define LINE_ROUTE_COL 5	//列
//#define LINE_ROUTE_RAW 1	//行

class Player;

class Route
{
public:
	Route();
	~Route();
	void Update();
	void Drow();

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos[LINE_ROUTE_COL]; }
	void SetPos(const VECTOR set) { pos[LINE_ROUTE_COL] = set; }

	VECTOR pos[LINE_ROUTE_COL];


	float radius;

private:
	int modelHandle;
	int x;			//X座標の初期値
	int MaterialNum;
	float interval;//オブジェクト同士の間隔

};
//-----------------------------------------------------------------------------
// @brief  メイン処理.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------

#pragma once

class ObstructManager;
class GraphManager;
class Player;
class Gauge;
class Nanji;

class HitChecker
{
public:
	HitChecker();
	~HitChecker() {};
	void PlayerGround(Player& player, ObstructManager& obstructManager);
	void PlayerJewelry(Player& player, GraphManager& graphManager, Gauge& gauge);
	void PlayerNanji(Player& player, Nanji& nanji, Gauge& gauge);
	void PlayerDornatsu(Player& player, DonutManager& donutManager, Gauge& gauge);
    
	bool isPlayerJewelryLeft;		//宝石あたり判定（プレイヤーは左に居る状態）
    bool isPlayerJewelryRight;		//宝石あたり判定（プレイヤーは右に居る状態）
	bool isPlayerJewelryUp;			//宝石あたり判定（プレイヤーは上に居る状態）
	bool HitJewelryFlag;			// 宝石があたったときのフラグ
	int count;

private:
	bool isPlayerGroundLeft;		//道あたり判定（プレイヤーは左に居る状態）
	bool isPlayerGroundRight;		//道あたり判定（プレイヤーは右に居る状態）

	bool isPlayerNanjiLeft;			//針あたり判定（プレイヤーは左に居る状態）
	bool isPlayerNanjiRight;		//針あたり判定（プレイヤーは右に居る状態）
	bool isPlayerNanjiUp;			//針あたり判定（プレイヤーは上にいる状態）

	bool isPlayerDonutLeft;			//ドーナツあたり判定（プレイヤーは左に居る状態）
	bool isPlayerDonutRight;		//ドーナツあたり判定（プレイヤーは右に居る状態）
	bool isPlayerDonutUp;			//ドーナツあたり判定（プレイヤーは上に居る状態）
	bool isPlayerDonutUp2;			//ドーナツあたり判定（プレイヤーは上に居る状態）
	bool isPlayerDonutDown;			//ドーナツあたり判定（プレイヤーは上に居る状態）
	bool isPlayerDonutDown2;		//ドーナツあたり判定（プレイヤーは上に居る状態）
	bool HitDonutLower;


	bool damageFlag;				// 針山に当たったら一時的に針山との当たり判定をなくす
	bool damageFlag2;				// 針山に当たったら一時的に針山との当たり判定をなくす

};
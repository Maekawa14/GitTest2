#pragma once

class Player;
class Nanji
{
public:
	Nanji();						//コンストラクタ
	~Nanji() {};					// デストラクタ

	void Update(Player& player);	// 更新
						
	// モデルハンドルの取得
	int GetModelHandle() { return modelHandle[8]; }

	float radius;					//当たり判定の半径

	VECTOR pos[8];					//オブジェクトの位置

	// ポジションのgetter/setter
	const VECTOR& GetPos() const { return pos[8]; }
	void SetPos(const VECTOR set) { pos[8] = set; }

private:
	float distanceX;
	float distanceY;
	float hitRadius;
	int	 modelHandle[8];			// モデルハンドル
	VECTOR posX1[8], posX2[8];		// オブジェクトの両端
	float distance;					// プレイヤーと針山の距離
};
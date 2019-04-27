#pragma once

#include "komon.h"
class KeyState;
class ObstructBase;
class HitChecker;
class Gauge;

class Player
{
public:
	Player();				// コンストラクタ.
	~Player();				// デストラクタ.

	void Update(KeyState& keyState);			// 更新
	void Move();								//移動
	void Jump();								//ジャンプ
	void Draw(HitChecker& hitChecker);			// 描画
	void Motion();								// 3Dモデルのモーション
	void Fever(Gauge& gauge);					// 無敵モード


	// 衝突処理
	void OnHitObstruct(ObstructBase& obstruct);
	
	// モデルハンドルの取得
	int GetModelHandle() { return modelHandle; }

	float angleX, angleY, angleZ;	//モデルの角度

	// あたり判定半径の取得
	float GetHitRadius() { return hitRadius; }

	float radius;           //当たり判定の半径

	//移動しているか管理フラグ
	bool moveFlag;

	//ジャンプをしているかフラグ管理
	bool jumpFlag;

	// フィーバーモードのフラグ管理
	bool feverFlag;

	// ポジションのgetter/setter
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }

	VECTOR	pos;			// ポジション
private:
	int	 modelHandle;	// モデルハンドル
	int  AttachIndex;
	int  magicPoint;
	int MaterialNum;		// マテリアルの数を取得
	float speed;
	float TotalTime, PlayTime;
	float hitRadius;		// あたり判定の半径
	float tempY;			//一時的にY座標を保管
	float prevY;			//ひとつ前のY座標
	bool dropFlag;			//落下中操作できないようにする

    //MMDのアニメーションフラグ
	bool runFlag, waitFlag;
	VECTOR	velocity;		// 移動力
	VECTOR dir;				//プレイヤーの向き
	// 静的定数.
	static const float COLIDE_DECEL_FAC;
};

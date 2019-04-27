#pragma once

class Enemy
{
public:
	Enemy();		//コンストラクタ
	~Enemy();		//デストラクタ

	void Updata(const Player& player);	//更新
	void Draw();	// 描画.

	int GetModelHandle() { return modelHandle; }

	bool moveFlag;     //移動しているか管理フラグ

	// ポジションのgetter/setter.
	VECTOR	pos;			// ポジション.
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }

	float angleX, angleY, angleZ;	//モデルの角度

private:
	int	 modelHandle;	// モデルハンドル.
	int  AttachIndex;

	float TotalTime, PlayTime;

	bool runFlag, wolkFlag, waitFlag;

};
#pragma once
class DonutBase
{
public:
	DonutBase(int sourceModelHandle);	// コンストラクタ.
	virtual ~DonutBase();				// デストラクタ.

	virtual void Update() = 0;				// 更新.
	virtual void Draw();					// 描画.

											// モデルハンドルの取得.
	int GetModelHandle() { return modelHandle; }

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }
	float GetHitRadius() { return hitRadius; }
protected:
	int		modelHandle;					// モデルハンドル.
	VECTOR	pos;							// ポジション.
	float	hitRadius;						// あたり判定の半径.
};
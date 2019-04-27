//-----------------------------------------------------------------------------
// @brief  障害物マネージャー.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#pragma once
class ObstructBase;

// 障害物の数.
#define LINE_ROUTE_COL 15
#define LINE_ROUTE_RAW 1

#define OBSTRUCT_SPACE_D -71.0f // 障害物の縦間隔.
#define OBSTRUCT_SPACE_W 550.0f // 障害物の横間隔.

class ObstructManager final
{
public:
	ObstructManager();				// コンストラクタ.
	~ObstructManager();				// デストラクタ.

	void CreateObstructs();			// 障害物生成.
	void DestroyObstructs();		// 障害物削除.

	void Update();					// 更新.
	void Draw();					// 描画.
	//void Hit();					// 当たり判定
	// 指定番号の障害物を取得.
	ObstructBase* GetObstruct(int raw, int col);

	int count;
    float radius;
private:
	ObstructBase* obstructs[LINE_ROUTE_RAW][LINE_ROUTE_COL];

	int floatModelSourceHandle;		// 浮遊モデルの大本のハンドル.
	int staticModelSourceHandle;	// 静止モデルの大本のハンドル.
};
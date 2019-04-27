#pragma once

#define GRAPH_SPACE_D 1.0f  // 障害物の縦間隔
#define GRAPH_SPACE_W 10.0f  // 障害物の横間隔

class DonutManager final
{
public:
	DonutManager();				// コンストラクタ
	~DonutManager();			// デストラクタ

	void CreateGraph();			// 障害物生成
	void DestroyGraph();		// 障害物削除

	void Update();										// 更新
	void Draw(HitChecker& hitChecker);					// 描画
	void Delete(int i, int  j);							// オブジェクト削除
														// 指定番号の障害物を取得
	DonutBase* GetGraph(int raw, int col);

	int count;
	float radius;
private:
	DonutBase * graph[LINE_GRAPH_RAW][LINE_GRAPH_COL];
	DonutBase* deleteGraph[LINE_GRAPH_RAW][LINE_GRAPH_COL];
	int donutModelSourceHandle;		// ドーナツモデルの大本のハンドル.
	int jewelryModelSourceHandle;	// 宝石モデルの大本のハンドル.
};
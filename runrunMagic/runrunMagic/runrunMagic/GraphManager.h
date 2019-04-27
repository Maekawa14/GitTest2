#pragma once
class GraphBase;
class HitChecker;

// 障害物の数

#define GRAPH_SPACE_D 1.0f  // 障害物の縦間隔
#define GRAPH_SPACE_W 10.0f  // 障害物の横間隔

class GraphManager final
{
public:
	GraphManager();				// コンストラクタ
	~GraphManager();			// デストラクタ

	void CreateGraph();			// 障害物生成
	void DestroyGraph();		// 障害物削除

	void Update();										// 更新
	void Draw(HitChecker& hitChecker);					// 描画
	void Delete(int i, int j);				// オブジェクト削除
	// 指定番号の障害物を取得
	GraphBase* GetGraph(int raw, int col);
	int count;
	float radius;
private:
	GraphBase* graph[LINE_GRAPH_RAW][LINE_GRAPH_COL];
	GraphBase* deleteGraph[LINE_GRAPH_RAW][LINE_GRAPH_COL];
	int donutModelSourceHandle;		// ドーナツモデルの大本のハンドル.
	int jewelryModelSourceHandle;	// 宝石モデルの大本のハンドル.
};
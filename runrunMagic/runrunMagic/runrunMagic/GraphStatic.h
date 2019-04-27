#pragma once
#include "GraphBase.h"

class GraphStatic : public GraphBase
{
public:
	GraphStatic(int sourceModelHandle);	// コンストラクタ.
	virtual ~GraphStatic();				// デストラクタ.

	void Update();							// 更新.
};
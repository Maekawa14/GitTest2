#pragma once
#include "GraphBase.h"
class GraphFloat : public GraphBase
{
public:
	GraphFloat(int sourceModelHandle);	// コンストラクタ.
	virtual ~GraphFloat();				// デストラクタ.

	void Update();							// 更新.

private:
	float rad;								// sin移動用のラジアン関数.
};
#pragma once
#include "GraphBase.h"
class DonutFloat : public DonutBase
{
public:
	DonutFloat(int sourceModelHandle);	// コンストラクタ.
	virtual ~DonutFloat();				// デストラクタ.

	void Update();							// 更新.

private:
	float rad;								// sin移動用のラジアン関数.
};
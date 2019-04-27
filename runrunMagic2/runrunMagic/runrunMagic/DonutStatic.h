#pragma once
#include "DonutBase.h"

class DonutStatic : public DonutBase
{
public:
	DonutStatic(int sourceModelHandle);	// コンストラクタ.
	virtual ~DonutStatic();				// デストラクタ.

	void Update();							// 更新.
};
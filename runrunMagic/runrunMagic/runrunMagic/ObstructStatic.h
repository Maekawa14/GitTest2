//-----------------------------------------------------------------------------
// @brief  障害物：動かない.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#pragma once
#include "ObstructBase.h"

class ObstructStatic : public ObstructBase
{
public:
	ObstructStatic(int sourceModelHandle);	// コンストラクタ.
	virtual ~ObstructStatic();				// デストラクタ.

	void Update();							// 更新.
};


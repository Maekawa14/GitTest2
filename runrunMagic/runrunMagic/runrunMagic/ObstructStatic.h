//-----------------------------------------------------------------------------
// @brief  ��Q���F�����Ȃ�.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#pragma once
#include "ObstructBase.h"

class ObstructStatic : public ObstructBase
{
public:
	ObstructStatic(int sourceModelHandle);	// �R���X�g���N�^.
	virtual ~ObstructStatic();				// �f�X�g���N�^.

	void Update();							// �X�V.
};


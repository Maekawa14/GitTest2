//-----------------------------------------------------------------------------
// @brief  ��Q���F���V����.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#pragma once
#include "ObstructBase.h"

class ObstructFloat : public ObstructBase
{
public:
	ObstructFloat(int sourceModelHandle);	// �R���X�g���N�^.
	virtual ~ObstructFloat();				// �f�X�g���N�^.

	void Update();							// �X�V.

private:
	float rad;								// sin�ړ��p�̃��W�A���֐�.
};

#pragma once
#include "DonutBase.h"

class DonutStatic : public DonutBase
{
public:
	DonutStatic(int sourceModelHandle);	// �R���X�g���N�^.
	virtual ~DonutStatic();				// �f�X�g���N�^.

	void Update();							// �X�V.
};
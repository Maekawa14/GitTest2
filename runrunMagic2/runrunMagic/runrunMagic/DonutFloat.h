#pragma once
#include "GraphBase.h"
class DonutFloat : public DonutBase
{
public:
	DonutFloat(int sourceModelHandle);	// �R���X�g���N�^.
	virtual ~DonutFloat();				// �f�X�g���N�^.

	void Update();							// �X�V.

private:
	float rad;								// sin�ړ��p�̃��W�A���֐�.
};
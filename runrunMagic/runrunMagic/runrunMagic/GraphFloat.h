#pragma once
#include "GraphBase.h"
class GraphFloat : public GraphBase
{
public:
	GraphFloat(int sourceModelHandle);	// �R���X�g���N�^.
	virtual ~GraphFloat();				// �f�X�g���N�^.

	void Update();							// �X�V.

private:
	float rad;								// sin�ړ��p�̃��W�A���֐�.
};
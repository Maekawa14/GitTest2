#pragma once
#include "GraphBase.h"

class GraphStatic : public GraphBase
{
public:
	GraphStatic(int sourceModelHandle);	// �R���X�g���N�^.
	virtual ~GraphStatic();				// �f�X�g���N�^.

	void Update();							// �X�V.
};
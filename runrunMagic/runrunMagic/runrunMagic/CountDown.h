#pragma once

class FunctionSummary;

class CountDown
{
public:
	CountDown();
	~CountDown() {};

	void Update();

	float count;      // �J�E���g�_�E��
	bool GameStart;   //true�ɂȂ�����Q�[���X�^�[�g
};
#pragma once

class FunctionSummary;

class CountDown
{
public:
	CountDown();
	~CountDown() {};

	void Update();

	float count;      // カウントダウン
	bool GameStart;   //trueになったらゲームスタート
};
#include "komon.h"

CountDown::CountDown()
{
	count = 3.0;
	GameStart = false;
}

void CountDown::Update()
{
	//�J�E���g�_�E��
	count -= 0.01f;

	//�J�E���g�_�E����0�ɂȂ�����Q�[���X�^�[�g
	if (count < 0.0f)
	{
		count = 0.0f;
		GameStart = true;
	}
	printfDx("CountDown: %.0f\n", count);
}

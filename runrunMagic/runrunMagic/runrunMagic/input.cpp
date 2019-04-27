#include "input.h"

KEY_STATE_ENUM key[256];

KEY_STATE_ENUM getKey(unsigned char keycode)
{
	return key[keycode];
}

void KeyState::InitKey()
{
	nowkey = 0;
	prevkey = 1;
}

void KeyState::UpDateKey()   // ���t���[���Ă΂��
{
	//���݂̃L�[�̓��͂�
	GetHitKeyStateAll(keystate[nowkey]);

	for (int i = 0; i < 256; i++)
	{

		//�L�[��������Ă�����
		if (keystate[prevkey][i] == 1)
		{
			//�O�t���[����������Ă���̂ŉ��������Ă���ꍇ
			if (keystate[nowkey][i] == 1)
			{
				key[i] = KEY_STATE_PRESSED;
			}
			else    //�O�t���[���͉�����Ă������������ꍇ
			{
				key[i] = KEY_STATE_PULLUP;
			}
		}
		else
		{
			//�O�t���[���͉�����Ă��Ȃ��������������ꂽ�ꍇ
			if (keystate[nowkey][i] == 1)
			{
				key[i] = KEY_STATE_PUSHDOWN;
			}
			else   //�O�t���[�������݂�������Ă��Ȃ��ꍇ
			{
				key[i] = KEY_STATE_OFF;
			}
		}
	}

	//nowkey��prevkey��0��1��������if��
	if (nowkey == 0)
	{
		nowkey = 1;
	}
	else
	{
		nowkey = 0;
	}

	if (prevkey == 1)
	{
		prevkey = 0;
	}
	else
	{
		prevkey = 1;
	}

}

//checkhitkey�̖��
KEY_STATE_ENUM getKey(int keyCode)
{
	return key[keyCode];
}


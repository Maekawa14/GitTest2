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

void KeyState::UpDateKey()   // 毎フレーム呼ばれる
{
	//現在のキーの入力を
	GetHitKeyStateAll(keystate[nowkey]);

	for (int i = 0; i < 256; i++)
	{

		//キーが押されていたら
		if (keystate[prevkey][i] == 1)
		{
			//前フレームも押されているので押し続けている場合
			if (keystate[nowkey][i] == 1)
			{
				key[i] = KEY_STATE_PRESSED;
			}
			else    //前フレームは押されていたが離した場合
			{
				key[i] = KEY_STATE_PULLUP;
			}
		}
		else
		{
			//前フレームは押されていなかったが今押された場合
			if (keystate[nowkey][i] == 1)
			{
				key[i] = KEY_STATE_PUSHDOWN;
			}
			else   //前フレームも現在も押されていない場合
			{
				key[i] = KEY_STATE_OFF;
			}
		}
	}

	//nowkeyとprevkeyを0か1を代入するif文
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

//checkhitkeyの役目
KEY_STATE_ENUM getKey(int keyCode)
{
	return key[keyCode];
}


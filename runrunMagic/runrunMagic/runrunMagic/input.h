#pragma once

#include "komon.h"

typedef enum KEY_STATE_ENUM
{
	KEY_STATE_OFF = 0,   //元々OFF
	KEY_STATE_PUSHDOWN,  //今押された
	KEY_STATE_PRESSED,   //ずっと押された
	KEY_STATE_PULLUP,    //キーが離れた

}KEY_STATE_ENUM;

class KeyState
{
public:
	KeyState() {};			//コンストラクタ
	~KeyState() {};			//デストラクタ
	void InitKey();
	void UpDateKey();

private:
	char keystate[2][256];//キーボードの状態
	int nowkey, prevkey;
	int deflate;   //デフォルト
};

//---------------
//プロトタイプ宣言
//---------------
//KEY_STATE_ENUM getKey(unsigned char keycode);
KEY_STATE_ENUM getKey(int keyCode);
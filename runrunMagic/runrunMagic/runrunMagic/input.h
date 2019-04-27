#pragma once

#include "komon.h"

typedef enum KEY_STATE_ENUM
{
	KEY_STATE_OFF = 0,   //���XOFF
	KEY_STATE_PUSHDOWN,  //�������ꂽ
	KEY_STATE_PRESSED,   //�����Ɖ����ꂽ
	KEY_STATE_PULLUP,    //�L�[�����ꂽ

}KEY_STATE_ENUM;

class KeyState
{
public:
	KeyState() {};			//�R���X�g���N�^
	~KeyState() {};			//�f�X�g���N�^
	void InitKey();
	void UpDateKey();

private:
	char keystate[2][256];//�L�[�{�[�h�̏��
	int nowkey, prevkey;
	int deflate;   //�f�t�H���g
};

//---------------
//�v���g�^�C�v�錾
//---------------
//KEY_STATE_ENUM getKey(unsigned char keycode);
KEY_STATE_ENUM getKey(int keyCode);
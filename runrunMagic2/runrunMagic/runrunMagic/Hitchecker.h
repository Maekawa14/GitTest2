//-----------------------------------------------------------------------------
// @brief  ���C������.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------

#pragma once

class ObstructManager;
class GraphManager;
class Player;
class Gauge;
class Nanji;

class HitChecker
{
public:
	HitChecker();
	~HitChecker() {};
	void PlayerGround(Player& player, ObstructManager& obstructManager);
	void PlayerJewelry(Player& player, GraphManager& graphManager, Gauge& gauge);
	void PlayerNanji(Player& player, Nanji& nanji, Gauge& gauge);
	void PlayerDornatsu(Player& player, DonutManager& donutManager, Gauge& gauge);
    
	bool isPlayerJewelryLeft;		//��΂����蔻��i�v���C���[�͍��ɋ����ԁj
    bool isPlayerJewelryRight;		//��΂����蔻��i�v���C���[�͉E�ɋ����ԁj
	bool isPlayerJewelryUp;			//��΂����蔻��i�v���C���[�͏�ɋ����ԁj
	bool HitJewelryFlag;			// ��΂����������Ƃ��̃t���O
	int count;

private:
	bool isPlayerGroundLeft;		//�������蔻��i�v���C���[�͍��ɋ����ԁj
	bool isPlayerGroundRight;		//�������蔻��i�v���C���[�͉E�ɋ����ԁj

	bool isPlayerNanjiLeft;			//�j�����蔻��i�v���C���[�͍��ɋ����ԁj
	bool isPlayerNanjiRight;		//�j�����蔻��i�v���C���[�͉E�ɋ����ԁj
	bool isPlayerNanjiUp;			//�j�����蔻��i�v���C���[�͏�ɂ����ԁj

	bool isPlayerDonutLeft;			//�h�[�i�c�����蔻��i�v���C���[�͍��ɋ����ԁj
	bool isPlayerDonutRight;		//�h�[�i�c�����蔻��i�v���C���[�͉E�ɋ����ԁj
	bool isPlayerDonutUp;			//�h�[�i�c�����蔻��i�v���C���[�͏�ɋ����ԁj
	bool isPlayerDonutUp2;			//�h�[�i�c�����蔻��i�v���C���[�͏�ɋ����ԁj
	bool isPlayerDonutDown;			//�h�[�i�c�����蔻��i�v���C���[�͏�ɋ����ԁj
	bool isPlayerDonutDown2;		//�h�[�i�c�����蔻��i�v���C���[�͏�ɋ����ԁj
	bool HitDonutLower;


	bool damageFlag;				// �j�R�ɓ���������ꎞ�I�ɐj�R�Ƃ̓����蔻����Ȃ���
	bool damageFlag2;				// �j�R�ɓ���������ꎞ�I�ɐj�R�Ƃ̓����蔻����Ȃ���

};
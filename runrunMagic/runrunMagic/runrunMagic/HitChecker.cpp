//-----------------------------------------------------------------------------
// @brief  �q�b�g�`�F�b�N.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------

#include "komon.h"

//-----------------------------------------------------------------------------
// @brief  �q�b�g�`�F�b�N����.
//-----------------------------------------------------------------------------


HitChecker::HitChecker()
{
	isPlayerGroundLeft = false;    // �n�ʂ����蔻��i�v���C���[�͍��ɋ����ԁj
	isPlayerGroundRight = false;   // �n�ʂ����蔻��i�v���C���[�͉E�ɋ����ԁj

	isPlayerJewelryLeft = false;   // �n�ʂ����蔻��i�v���C���[�͍��ɋ����ԁj
	isPlayerJewelryLeft = false;   // �n�ʂ����蔻��i�v���C���[�͉E�ɋ����ԁj

	isPlayerNanjiLeft   = false;   // �j�����蔻��i�v���C���[�͍��ɋ����ԁj
	isPlayerNanjiRight  = false;   // �j�����蔻��i�v���C���[�͉E�ɋ����ԁj
	isPlayerNanjiUp     = false;   // �j�����蔻��i�v���C���[�͏�ɋ����ԁj

	isPlayerDonutLeft = false;			//�h�[�i�c�����蔻��i�v���C���[�͍��ɋ����ԁj
	isPlayerDonutRight = false;			//�h�[�i�c�����蔻��i�v���C���[�͉E�ɋ����ԁj
	isPlayerDonutUp = false;			//�h�[�i�c�����蔻��i�v���C���[�͏�ɋ����ԁj
	isPlayerDonutDown = false;			//�h�[�i�c�����蔻��i�v���C���[�͏�ɋ����ԁj
	isPlayerDonutUp2 = false;			//�h�[�i�c�����蔻��i�v���C���[�͏�ɋ����ԁj
	isPlayerDonutDown2 = false;			//�h�[�i�c�����蔻��i�v���C���[�͏�ɋ����ԁj
	HitDonutLower = false;

	damageFlag = false;			   // �_���[�W���󂯂��t���O�Ǘ�
	damageFlag2 = false;			   // �_���[�W���󂯂��t���O�Ǘ�

	count = 0;
}

void HitChecker::PlayerGround(Player& player, ObstructManager& obstructManager)
{
	bool isHit = false;
	//----------------
	// �n�ʂ̓����蔻��
	//----------------

	for (int i = 0; i < LINE_ROUTE_COL; i++)
	{
		for (int j = 0; j < LINE_ROUTE_RAW; j++)
		{
			//�}�b�v�`�b�v�̍��W���擾����
			ObstructBase* obstruct = obstructManager.GetObstruct(j, i);

			if (obstruct != NULL)
			{
				// �n�ʁi�����j�ƃv���C���[�̓����蔻��
				isPlayerGroundLeft = player.pos.x > obstruct->GetPos().x - 252.5f;

				// �n�ʁi�E���j�ƃv���C���[�̓����蔻��
				isPlayerGroundRight = player.pos.x < ((obstruct->GetPos().x + 252.5f) + player.radius);

				if (isPlayerGroundLeft && isPlayerGroundRight && player.jumpFlag != true)
				{
					DrawFormatString(550, 50, GetColor(255, 255, 255), "HIT!");
					isHit = true;
					break;
				}
			}
		}
	}

	// isHit�t���O��true���W�����v���Ă��Ȃ��ꍇ
	// �v���C���[����������
	if (!isHit && !player.jumpFlag)
	{
		//�n�ʂ���o���痎��
		//player.pos.y -= 5;
		DrawFormatString(500, 50, GetColor(255, 255, 255), "NoHit!");
	}
}



void HitChecker::PlayerJewelry(Player& player, GraphManager& graphManager, Gauge& gauge)
{
	//------------------
	//��΂̓����蔻��
	//------------------
	VECTOR yZeroPlayer = VGet(player.GetPos().x, 0, player.GetPos().z);

	for (int i = 0; i < LINE_GRAPH_COL; i++)
	{
		for (int j = 0; j < LINE_GRAPH_RAW; j++)
		{
			//�}�b�v�`�b�v�̍��W���擾����
			GraphBase* graph = graphManager.GetGraph(j, i);
			//GraphBase* deleteGraph = graphManager.GetGraph(j, i);
			if (graph != NULL)
			{
				// ��΁i�����j�ƃv���C���[�̓����蔻��
				isPlayerJewelryLeft = player.pos.x > graph->GetPos().x - 2.0f;

				// ��΁i�E���j�ƃv���C���[�̓����蔻��
				isPlayerJewelryRight = player.pos.x < ((graph->GetPos().x + 2.0f) + player.radius);

				// ��΁i�E���j�ƃv���C���[�̓����蔻��
				isPlayerJewelryUp = player.pos.y < graph->GetPos().y;


				if (isPlayerJewelryLeft && isPlayerJewelryRight 
					&& isPlayerJewelryUp && !player.feverFlag)
				{
					DrawFormatString(500, 100, GetColor(255, 255, 255), "ItemHIT!");

					//���@�Q�[�W�����Z����
					gauge.MPGX2 += 10.0f;

					//���C���[������������΂�����
					graphManager.Delete(j, i);

					//���[�v���甲������
					break;
				}
			}
		}
	}
}

void HitChecker::PlayerNanji(Player& player, Nanji& nanji, Gauge& gauge)
{
	//----------------
	// �j�̓����蔻��
	//----------------

	for (int i = 0; i < 8; i++)
	{
		// �j�i�����j�ƃv���C���[�̓����蔻��
		isPlayerNanjiLeft = player.pos.x > nanji.pos[i].x - nanji.radius;

		// �j�i�E���j�ƃv���C���[�̓����蔻��
		isPlayerNanjiRight = player.pos.x < ((nanji.pos[i].x + nanji.radius) + player.radius);

		// �j�i�㑤�j�ƃv���C���[�̓����蔻��
		isPlayerNanjiUp = player.pos.y < nanji.pos[i].y;

		//�j�R�Ɠ����蔻����e
		if (isPlayerNanjiLeft && isPlayerNanjiRight && isPlayerNanjiUp && !damageFlag)
		{
			DrawFormatString(550, 280, GetColor(0, 0, 255), "HIT!");
			// �j�R�ɓ���������̗͂�3���茸�炷
			gauge.HPGX2 = gauge.HPGX2 - (gauge.HPGX2 / 30);

			break;
		}
	}

}

void HitChecker::PlayerDornatsu(Player& player, DonutManager& donutManager, Gauge& gauge)
{
	//------------------
	//�h�[�i�c�̓����蔻��
	//------------------
	VECTOR yZeroPlayer = VGet(player.GetPos().x, 0, player.GetPos().z);

	for (int i = 0; i < LINE_GRAPH_COL; i++)
	{
		for (int j = 0; j < LINE_GRAPH_RAW; j++)
		{
			//�}�b�v�`�b�v�̍��W���擾����
			DonutBase* donut = donutManager.GetGraph(j, i);
			if (donut != NULL)
			{
				// �h�[�i�c�i�����j�ƃv���C���[�̓����蔻��
				isPlayerDonutLeft = player.pos.x > donut->GetPos().x - 5.0f;

				// �h�[�i�c�i�E���j�ƃv���C���[�̓����蔻��
				isPlayerDonutRight = player.pos.x < ((donut->GetPos().x + 5.0f) + player.radius);

				// �h�[�i�c�i�㑤�j�ƃv���C���[�̓����蔻��
				isPlayerDonutUp = player.pos.y > donut->GetPos().y - 5.0f;

				if (isPlayerDonutUp)
				{
					HitDonutLower = true;
				}
				else
				{
					HitDonutLower = false;
				}

				if (isPlayerDonutLeft && isPlayerDonutRight && HitDonutLower)
				{
					DrawFormatString(550, 200, GetColor(255, 255, 255), "DonutHIT!");
					//���@�Q�[�W�����Z����
					gauge.HPGX2 += 10.0f;

					// �h�[�i�c�ɓ��������瓖�������h�[�i�c������
					donutManager.Delete(j, i);
					break;
				}
			}
		}
	}
}

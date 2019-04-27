#include "komon.h"

Nanji::Nanji()
{
	//�v���C���[�̏����ʒu
	pos[0] = VGet(-100.0f, 30.0f, 0.0f);
	pos[1] = VGet(-230.0f, 30.0f, 0.0f);
	pos[3] = VGet(-730.0f, 30.0f, 0.0f);
	pos[4] = VGet(-1030.0f, 30.0f, 0.0f);
	pos[5] = VGet(-1530.0f, 30.0f, 0.0f);
	pos[6] = VGet(-2430.0f, 30.0f, 0.0f);
	pos[7] = VGet(-3390.0f, 30.0f, 0.0f);

	radius = 30.0f;

	for (int i = 0; i < 8; i++)
	{
		//3D���f���̓ǂݍ���
		modelHandle[i] = MV1LoadModel("img/BackGround/nanji.x");
	}
}

void Nanji::Update(Player& player)
{

	for (int i = 0; i < 8; i++)
	{
		// �R�c���f���̕`��
		MV1DrawModel(modelHandle[i]);

		// �v���C���[����j�R�܂ł̌��݂̋���
		distanceX = pos[i].x - player.pos.x;
		distanceY = pos[i].y - player.pos.y;

		// ����̋���:����͍L�߂ɂƂ�
		hitRadius = (radius + 65) + player.radius;

		// �v���C���[�Ɛj�R�̋������߂��Ȃ�Ύ��s
		if ((distanceX * distanceX + distanceY * distanceY) < hitRadius * hitRadius)
		{
			// �v���C���[���߂Â��Ă�����j�R���o��
			if (pos[i].y < 53)
			{
				pos[i].y += 3.0f;
			}
		}

		// �RD���f���̃|�W�V�����ݒ�
		MV1SetPosition(modelHandle[i], pos[i]);
	
		//3D���f���̑傫��
		MV1SetScale(modelHandle[i], VGet(10.0f, 10.0f, 10.0f));
	}
}

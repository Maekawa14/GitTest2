#pragma once
#include "komon.h"

//��΂̐�
#define LINE_JEWEL_COL 5	//��
#define LINE_JEWEL_RAW 1	//�s

class Player;
class Gauge;

class Jewelry
{
public:
	Jewelry();				// �R���X�g���N�^.
	~Jewelry();				// �f�X�g���N�^.
	void Update();
	void Drow();
	void PlayerHit(Player& player, Gauge& gauge);
	
	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return pos[ LINE_JEWEL_COL ]; }
	void SetPos(const VECTOR set) { pos[ LINE_JEWEL_COL ] = set; }

	VECTOR pos[ LINE_JEWEL_COL ];

	float radius;
private:
	int modelHandle[ LINE_JEWEL_COL ];
	int x;			//X���W�̏����l
	int MaterialNum[ LINE_JEWEL_COL ];
	float interval;//�I�u�W�F�N�g���m�̊Ԋu

	bool playerHitUp;
	bool playerHitDown;
};
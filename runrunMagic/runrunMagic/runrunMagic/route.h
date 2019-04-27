#pragma once

#include "komon.h"


// ���̐�.
//#define LINE_ROUTE_COL 5	//��
//#define LINE_ROUTE_RAW 1	//�s

class Player;

class Route
{
public:
	Route();
	~Route();
	void Update();
	void Drow();

	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return pos[LINE_ROUTE_COL]; }
	void SetPos(const VECTOR set) { pos[LINE_ROUTE_COL] = set; }

	VECTOR pos[LINE_ROUTE_COL];


	float radius;

private:
	int modelHandle;
	int x;			//X���W�̏����l
	int MaterialNum;
	float interval;//�I�u�W�F�N�g���m�̊Ԋu

};
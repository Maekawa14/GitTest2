//-----------------------------------------------------------------------------
// @brief  ��Q���}�l�[�W���[.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#pragma once
class ObstructBase;

// ��Q���̐�.
#define LINE_ROUTE_COL 15
#define LINE_ROUTE_RAW 1

#define OBSTRUCT_SPACE_D -71.0f // ��Q���̏c�Ԋu.
#define OBSTRUCT_SPACE_W 550.0f // ��Q���̉��Ԋu.

class ObstructManager final
{
public:
	ObstructManager();				// �R���X�g���N�^.
	~ObstructManager();				// �f�X�g���N�^.

	void CreateObstructs();			// ��Q������.
	void DestroyObstructs();		// ��Q���폜.

	void Update();					// �X�V.
	void Draw();					// �`��.
	//void Hit();					// �����蔻��
	// �w��ԍ��̏�Q�����擾.
	ObstructBase* GetObstruct(int raw, int col);

	int count;
    float radius;
private:
	ObstructBase* obstructs[LINE_ROUTE_RAW][LINE_ROUTE_COL];

	int floatModelSourceHandle;		// ���V���f���̑�{�̃n���h��.
	int staticModelSourceHandle;	// �Î~���f���̑�{�̃n���h��.
};
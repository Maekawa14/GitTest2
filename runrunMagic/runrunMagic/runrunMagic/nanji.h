#pragma once

class Player;
class Nanji
{
public:
	Nanji();						//�R���X�g���N�^
	~Nanji() {};					// �f�X�g���N�^

	void Update(Player& player);	// �X�V
						
	// ���f���n���h���̎擾
	int GetModelHandle() { return modelHandle[8]; }

	float radius;					//�����蔻��̔��a

	VECTOR pos[8];					//�I�u�W�F�N�g�̈ʒu

	// �|�W�V������getter/setter
	const VECTOR& GetPos() const { return pos[8]; }
	void SetPos(const VECTOR set) { pos[8] = set; }

private:
	float distanceX;
	float distanceY;
	float hitRadius;
	int	 modelHandle[8];			// ���f���n���h��
	VECTOR posX1[8], posX2[8];		// �I�u�W�F�N�g�̗��[
	float distance;					// �v���C���[�Ɛj�R�̋���
};
#pragma once

#include "komon.h"
class KeyState;
class ObstructBase;
class HitChecker;
class Gauge;

class Player
{
public:
	Player();				// �R���X�g���N�^.
	~Player();				// �f�X�g���N�^.

	void Update(KeyState& keyState);			// �X�V
	void Move();								//�ړ�
	void Jump();								//�W�����v
	void Draw(HitChecker& hitChecker);			// �`��
	void Motion();								// 3D���f���̃��[�V����
	void Fever(Gauge& gauge);					// ���G���[�h


	// �Փˏ���
	void OnHitObstruct(ObstructBase& obstruct);
	
	// ���f���n���h���̎擾
	int GetModelHandle() { return modelHandle; }

	float angleX, angleY, angleZ;	//���f���̊p�x

	// �����蔻�蔼�a�̎擾
	float GetHitRadius() { return hitRadius; }

	float radius;           //�����蔻��̔��a

	//�ړ����Ă��邩�Ǘ��t���O
	bool moveFlag;

	//�W�����v�����Ă��邩�t���O�Ǘ�
	bool jumpFlag;

	// �t�B�[�o�[���[�h�̃t���O�Ǘ�
	bool feverFlag;

	// �|�W�V������getter/setter
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }

	VECTOR	pos;			// �|�W�V����
private:
	int	 modelHandle;	// ���f���n���h��
	int  AttachIndex;
	int  magicPoint;
	int MaterialNum;		// �}�e���A���̐����擾
	float speed;
	float TotalTime, PlayTime;
	float hitRadius;		// �����蔻��̔��a
	float tempY;			//�ꎞ�I��Y���W��ۊ�
	float prevY;			//�ЂƂO��Y���W
	bool dropFlag;			//����������ł��Ȃ��悤�ɂ���

    //MMD�̃A�j���[�V�����t���O
	bool runFlag, waitFlag;
	VECTOR	velocity;		// �ړ���
	VECTOR dir;				//�v���C���[�̌���
	// �ÓI�萔.
	static const float COLIDE_DECEL_FAC;
};

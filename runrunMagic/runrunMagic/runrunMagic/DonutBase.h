#pragma once
class DonutBase
{
public:
	DonutBase(int sourceModelHandle);	// �R���X�g���N�^.
	virtual ~DonutBase();				// �f�X�g���N�^.

	virtual void Update() = 0;				// �X�V.
	virtual void Draw();					// �`��.

											// ���f���n���h���̎擾.
	int GetModelHandle() { return modelHandle; }

	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }
	float GetHitRadius() { return hitRadius; }
protected:
	int		modelHandle;					// ���f���n���h��.
	VECTOR	pos;							// �|�W�V����.
	float	hitRadius;						// �����蔻��̔��a.
};
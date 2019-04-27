#pragma once

class Enemy
{
public:
	Enemy();		//�R���X�g���N�^
	~Enemy();		//�f�X�g���N�^

	void Updata(const Player& player);	//�X�V
	void Draw();	// �`��.

	int GetModelHandle() { return modelHandle; }

	bool moveFlag;     //�ړ����Ă��邩�Ǘ��t���O

	// �|�W�V������getter/setter.
	VECTOR	pos;			// �|�W�V����.
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }

	float angleX, angleY, angleZ;	//���f���̊p�x

private:
	int	 modelHandle;	// ���f���n���h��.
	int  AttachIndex;

	float TotalTime, PlayTime;

	bool runFlag, wolkFlag, waitFlag;

};
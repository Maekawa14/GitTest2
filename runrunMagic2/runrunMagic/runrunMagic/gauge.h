#pragma once

#include  "komon.h"
class Gauge
{
public:
	Gauge();				//�R���X�g���N�^
	~Gauge() {};			//�f�X�g���N�^
	void Update();	
	void DecreaseHP();		//HP����
	void Limit();			//�Q�[�W�̏������
	void Fever(Player& player);			//�t�B�[�o�[���̏���
	
	float HPGX2;			//�̗̓Q�[�W�̍��W(MAX 200)
	float MPGX2;			//�}�W�b�N�|�C���g�Q�[�W�̍��W(MAX 200)
							//�Q�[�W���������Ȃ��Ȃ�
	bool stopDecrease;
private:
	float HPX, HPY, HPX2, HPY2;	//�̗̓Q�[�W�̘g���W
	int HPframeColor;			//�̗̓Q�[�W�̘g�F
	int HPColor;				//�̗̓Q�[�W�̐F

	float MPX, MPY, MPX2, MPY2;	//�}�W�b�N�|�C���g�̃Q�[�W�̘g���W
	int MPframeColor;			//�}�W�b�N�|�C���g�Q�[�W�̘g�F
	int MPColor;				//�}�W�b�N�|�C���g�Q�[�W�̐F

};
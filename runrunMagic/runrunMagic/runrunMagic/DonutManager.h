#pragma once

#define GRAPH_SPACE_D 1.0f  // ��Q���̏c�Ԋu
#define GRAPH_SPACE_W 10.0f  // ��Q���̉��Ԋu

class DonutManager final
{
public:
	DonutManager();				// �R���X�g���N�^
	~DonutManager();			// �f�X�g���N�^

	void CreateGraph();			// ��Q������
	void DestroyGraph();		// ��Q���폜

	void Update();										// �X�V
	void Draw(HitChecker& hitChecker);					// �`��
	void Delete(int i, int  j);							// �I�u�W�F�N�g�폜
														// �w��ԍ��̏�Q�����擾
	DonutBase* GetGraph(int raw, int col);

	int count;
	float radius;
private:
	DonutBase * graph[LINE_GRAPH_RAW][LINE_GRAPH_COL];
	DonutBase* deleteGraph[LINE_GRAPH_RAW][LINE_GRAPH_COL];
	int donutModelSourceHandle;		// �h�[�i�c���f���̑�{�̃n���h��.
	int jewelryModelSourceHandle;	// ��΃��f���̑�{�̃n���h��.
};
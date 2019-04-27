#pragma once
class GraphBase;
class HitChecker;

// ��Q���̐�

#define GRAPH_SPACE_D 1.0f  // ��Q���̏c�Ԋu
#define GRAPH_SPACE_W 10.0f  // ��Q���̉��Ԋu

class GraphManager final
{
public:
	GraphManager();				// �R���X�g���N�^
	~GraphManager();			// �f�X�g���N�^

	void CreateGraph();			// ��Q������
	void DestroyGraph();		// ��Q���폜

	void Update();										// �X�V
	void Draw(HitChecker& hitChecker);					// �`��
	void Delete(int i, int j);				// �I�u�W�F�N�g�폜
	// �w��ԍ��̏�Q�����擾
	GraphBase* GetGraph(int raw, int col);
	int count;
	float radius;
private:
	GraphBase* graph[LINE_GRAPH_RAW][LINE_GRAPH_COL];
	GraphBase* deleteGraph[LINE_GRAPH_RAW][LINE_GRAPH_COL];
	int donutModelSourceHandle;		// �h�[�i�c���f���̑�{�̃n���h��.
	int jewelryModelSourceHandle;	// ��΃��f���̑�{�̃n���h��.
};
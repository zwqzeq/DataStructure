
//��������������ÿ�����
typedef struct Node {
	int leftThraed;//������
	struct Node *leftChild;//��ָ��
	Datatype data;//����Ԫ��
	struct Node*rightChild;//��ָ��
	int rightThread;//������
};

//��������
void InThread(ThreadBiNode *current, ThreadBiNode **pre);
void CreatInThread(ThreadBiNode **root);
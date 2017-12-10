
//中序线索二叉树每个结点
typedef struct Node {
	int leftThraed;//左线索
	struct Node *leftChild;//左指针
	Datatype data;//数据元素
	struct Node*rightChild;//右指针
	int rightThread;//右线索
};

//函数声明
void InThread(ThreadBiNode *current, ThreadBiNode **pre);
void CreatInThread(ThreadBiNode **root);
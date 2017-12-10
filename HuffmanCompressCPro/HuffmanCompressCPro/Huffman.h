
struct HTNode{
    int weight;//权值
	int parent;//父节点
	int lchild;//左孩子
	int rchild;//右孩子
};


//函数声明
int HuffmanTree(HuffmanTree &pHT,int *w,int n);
int Select(HuffmanTree pHT,int nSize);
int HuffmanCoding();

struct HTNode{
    int weight;//Ȩֵ
	int parent;//���ڵ�
	int lchild;//����
	int rchild;//�Һ���
};


//��������
int HuffmanTree(HuffmanTree &pHT,int *w,int n);
int Select(HuffmanTree pHT,int nSize);
int HuffmanCoding();
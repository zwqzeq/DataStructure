#ifndef HUFFMAN_H
#define HUFFMAN_H

struct HTNode
{
	int weight;//Ȩֵ
	int parent;//���ڵ�
	int lchild;//����
	int rchild;//�Һ���
};
typedef HTNode *HTree;//��̬��������洢Huffman��
typedef char**HCode;//��̬��������洢Huffman����

int HuffmanTree(HTree &pHT, int *aWeight);//����Huffman��
int Select(HTree pHT,int nSize);//����Huffman�����������Ȩֵ��С�Ľ��
int HuffmanCoding(HCode &pHC,HTree &pHT);//����Huffman��������Huffman����


#endif
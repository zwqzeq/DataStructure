#ifndef HUFFMAN_H
#define HUFFMAN_H

struct HTNode
{
	int weight;//权值
	int parent;//父节点
	int lchild;//左孩子
	int rchild;//右孩子
};
typedef HTNode *HTree;//动态分配数组存储Huffman树
typedef char**HCode;//动态分配数组存储Huffman编码

int HuffmanTree(HTree &pHT, int *aWeight);//生成Huffman树
int Select(HTree pHT,int nSize);//查找Huffman树结点数组中权值最小的结点
int HuffmanCoding(HCode &pHC,HTree &pHT);//遍历Huffman树，生成Huffman编码


#endif
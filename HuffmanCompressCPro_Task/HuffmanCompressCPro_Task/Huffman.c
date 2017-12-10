//以下是针对哈夫曼树的操作
#include "Huffman.h"
#include "Compress.h"

//初始化树
int InitQueue(SeqQueue * Q)
{
	if (!Q)
		return 1;
	Q->tag = Empty;
	Q->front = Q->rear = 0;
	Q->length = 0;
	return 0;
}

//插入数据
int In_seqQueue(SeqQueue * Q, char x)
{
	if (Q->front == Q->rear && Q->tag == SOME)
		return FULL;	

	Q->elem[Q->rear] = x;
	Q->rear = (Q->rear + 1) % Maxsize;
	Q->length++;
	Q->tag = SOME;
	return SOME;
}

//数据出队列
int Out_Queue(SeqQueue * Q, char *x)
{
	if (Q->tag == Empty)
		return Empty;

	*x = Q->elem[Q->front];
	Q->length--;
	Q->front = (Q->front + 1) % Maxsize;

	if (Q->front == Q->rear)
		Q->tag = Empty;

	return SOME;
}

//选择最小哈夫曼树
void SelectMinTree(HTNode * ht, int n, int *k)
{
	int i, temp;
	WeightType min;
	for (i = 0; i <= n; i++) {
		if (0 == ht[i].parent) {
			min = ht[i].weight;	
			temp = i;
			break;
		}
	}
	for (i++; i <= n; i++) {
		if (0 == ht[i].parent && ht[i].weight < min) {
			min = ht[i].weight;
			temp = i;
		}
	}
	*k = temp;
}
// 对哈夫曼树排序，并统计叶子数量
int SortTree(HTNode * ht)
{
	short i, j;
	HTNode tmp;
	for (i = N - 1; i >= 0; i--) {
		for (j = 0; j < i; j++)
			if (ht[j].weight < ht[j + 1].weight) {
				tmp = ht[j];
				ht[j] = ht[j + 1];
				ht[j + 1] = tmp;
			}
	}
	for (i = 0; i < N; i++)
		if (0 == ht[i].weight)
			return i;
	//返回叶子个数
	return i;		
}

//求哈夫曼0-1字符编码表
//从叶子结点到根，逆向求每个叶子结点对应的哈夫曼编码
char **CrtHuffmanCode(HTNode * ht, short LeafNum)
{
	char *cd, **hc;	//容器
	int i, start, p, last;
	hc = (char **)malloc((LeafNum) * sizeof(char *));	//分配n个编码的头指针
	if (1 == LeafNum)	//只有一个叶子节点时 
	{
		hc[0] = (char *)malloc((LeafNum + 1) * sizeof(char));
		strcpy(hc[0], "0");
		return hc;
	}
	cd = (char *)malloc((LeafNum + 1) * sizeof(char));	//分配求当前编码的工作空间 
	cd[LeafNum] = '\0';	//从右向左逐位存放编码，首先存放编码结束符 
	printf("源文件被编码为：\n");
	for (i = 0; i < LeafNum; i++) {	//求n个叶子结点对应的哈夫曼编码 
		start = LeafNum;	//初始化编码起始指针
		last = i;
		for (p = ht[i].parent; p != 0; p = ht[p].parent) {	//从叶子到根结点求编码 
			if (ht[p].LChild == last)
				cd[--start] = '0';	//左分支标0 
			else
				cd[--start] = '1';	//右分支标1 
			last = p;
		}
		hc[i] = (char *)malloc((LeafNum - start) * sizeof(char));	//为第i个编码分配空间 
		strcpy(hc[i], &cd[start]);
		printf("%s",&cd[start]);
	}			
	free(cd);
	return hc;
}

//创建一个哈夫曼树
HTNode *CreatHFM(FILE * fp, short *n, WeightType * FileLength)
{
	HTNode *ht = NULL;
	int i, m, s1, s2;
	MyType ch;
	ht = (HTNode *) malloc(2 * N * sizeof(HTNode));
	if (!ht)
		exit(1);
	for (i = 0; i < N; i++) {
		ht[i].weight = 0;
		ht[i].ch = (MyType) i;	//1-n号ch 为字符，初始化 
	}
	for (*FileLength = 0; !feof(fp); ++(*FileLength)) {
		ch = fgetc(fp);	   
		ht[ch].weight++;	
	}
	--(*FileLength);//去掉文件结束后的长度
	*n = SortTree(ht);
	m = *n * 2 - 1;	
	if (1 == *n) {
		ht[0].parent = 1;
		return ht;
	} else if (0 > *n)
		return NULL;

	for (i = m - 1; i >= 0; i--) {
		ht[i].LChild = 0;
		ht[i].parent = 0;
		ht[i].RChild = 0;
	}

	//创建非叶子结点,建哈夫曼树
	for (i = *n; i < m; i++)	
	{			
		//在ht[0]~ht[i-1]的范围内选择两个parent为0且weight最小的结点，其序号分别赋值给s1、s2返回
		SelectMinTree(ht, i - 1, &s1);
		ht[s1].parent = i;
		ht[i].LChild = s1;
		SelectMinTree(ht, i - 1, &s2);
		ht[s2].parent = i;
		ht[i].RChild = s2;
		ht[i].weight = ht[s1].weight + ht[s2].weight;
	}	

	//哈夫曼树建立完毕 
	return ht;
}

//从队列里取8个字符（0、1），转换成一个字节
MyType GetBits(SeqQueue * Q)
{
	MyType i, bits = 0;
	char x;
	for (i = 0; i < 8; i++) {
		if (Out_Queue(Q, &x) != Empty) {
			if ('0' == x)
				bits = bits << 1;
			else
				bits = (bits << 1) | 1;
		} else
			break;
	}			
	return bits;
}

//求最长（最短）编码长度
void MaxMinLength(FILE * File, HTNode * ht, char **hc, short NLeaf, MyType * Max, MyType * Min)
{
	int i;
	MyType length;
	*Max = *Min = strlen(hc[0]);
	for (i = 0; i < NLeaf; i++) {
		length = strlen(hc[i]);
		fwrite(&ht[i].ch, sizeof(MyType), 1, File);	//字符和对应的
		fwrite(&length, sizeof(MyType), 1, File);	//编码长度写进文件
		if (length > *Max)
			*Max = length;
		if (length < *Min)
			*Min = length;
	}
}

//把出现过的字符编码表经过压缩写进文件
short CodeToFile(FILE * fp, char **hc, short n, SeqQueue * Q, MyType * length)
{
	int i;
	char *p;
	MyType j, bits;
	short count = 0;
	for (i = 0; i < n; i++)	// 将n个叶子压缩并写入文件
	{
		for (p = hc[i]; '\0' != *p; p++)
			In_seqQueue(Q, *p);
		while (Q->length > 8) {	//  puts("出队");
			bits = GetBits(Q);	//出队8个元素
			fputc(bits, fp);
			count++;
		}
	}
	*length = Q->length;
	i = 8 - *length;
	bits = GetBits(Q);	//取8个如果队不空
	for (j = 0; j < i; j++)
		bits = bits << 1;	
	fputc(bits, fp);	
	count++;		
	InitQueue(Q);
	return count;
}
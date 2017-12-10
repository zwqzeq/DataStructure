#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//宏定义
#define  N 256
#define Maxsize 80
#define  SOME 1
#define Empty 0
#define FULL -1

typedef unsigned long int WeightType;
typedef unsigned char MyType;


//哈夫曼树结构体
typedef struct			
{
	MyType ch;		//存字符
	WeightType weight;	/* 用来存放各个结点的权值 */
	int parent, LChild, RChild;	/*指向双亲、孩子结点的指针 */
} HTNode;

//队列结构体
typedef struct
{
	int tag;
	int front;
	int rear;
	MyType length;
	char elem[Maxsize];
} SeqQueue;


//函数声明
int InitQueue(SeqQueue * Q);
int In_seqQueue(SeqQueue * Q, char x);
int Out_Queue(SeqQueue * Q, char *x);
void SelectMinTree(HTNode * ht, int n, int *k);
int SortTree(HTNode * ht);
char **CrtHuffmanCode(HTNode * ht, short LeafNum);
HTNode *CreatHFM(FILE * fp, short *n, WeightType * FileLength);
MyType GetBits(SeqQueue * Q);
void MaxMinLength(FILE * File, HTNode * ht, char **hc, short NLeaf, MyType * Max, MyType * Min);
short CodeToFile(FILE * fp, char **hc, short n, SeqQueue * Q, MyType * length);



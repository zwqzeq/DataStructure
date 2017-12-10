//防止重复定义
#ifndef SLNODE_H
#define SLNODE_H
#include <stdio.h>
#include <malloc.h>

typedef int DataType;

//定义结构体
typedef struct Node
{
	DataType data;
	struct Node *next;
}SLNode;

//初始化顺序表
void ListInitiate(SLNode **head);                   //函数声明
//求当前数据元素个数
int ListLength(SLNode *head);
//插入数据元素
int ListInsert(SLNode *head, int i, DataType x);
//删除数据个数元素
int ListDelete(SLNode *head, int i, DataType *x);
//取数据元素
int ListGet(SLNode *head, int i, DataType *x);
//撤销单链表
void Destory(SLNode **head);

#endif
#pragma once
#include<stdio.h>
#define Max 100
typedef int Datatype;


typedef struct
{
	Datatype seqCQue[Max];//顺序队列的长度
	int rear;//队尾指针
	int front;//队头指针
	int count;//计数器
}SeqCQueue;

//函数声明
void QueueInitiate(SeqCQueue *Q);
int QueueNotEmpty(SeqCQueue *Q);
int QueueAppend(SeqCQueue *Q,Datatype x);
int  QueueDelete(SeqCQueue *Q, Datatype *d);
int QueueGet(SeqCQueue *Q,Datatype *d);

























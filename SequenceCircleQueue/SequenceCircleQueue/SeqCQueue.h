#pragma once
#include<stdio.h>
#define Max 100
typedef int Datatype;


typedef struct
{
	Datatype seqCQue[Max];//˳����еĳ���
	int rear;//��βָ��
	int front;//��ͷָ��
	int count;//������
}SeqCQueue;

//��������
void QueueInitiate(SeqCQueue *Q);
int QueueNotEmpty(SeqCQueue *Q);
int QueueAppend(SeqCQueue *Q,Datatype x);
int  QueueDelete(SeqCQueue *Q, Datatype *d);
int QueueGet(SeqCQueue *Q,Datatype *d);

























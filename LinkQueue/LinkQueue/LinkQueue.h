#pragma once
typedef int Datatype;

//链式队列中每个结点
typedef  struct qnode{
	Datatype data;     //数据域
	struct qnode * next;//指针域                                            
} LQNode ;

//链式队列的指针
typedef struct
{
	LQNode *front;//队头指针
	LQNode * rear;//队尾指针
}LQueue;


//函数声明
void QueueInitiate(LQueue *Q);
int QueueNotEmpty(LQueue Q);
void QueueAppend(LQueue*Q, Datatype x);
int QueueDelete(LQueue *Q, Datatype *d);
int QueueGet(LQueue Q, Datatype *d);
void QueueDestroy(LQueue Q);
#include"LinkQueue.h"
#include<stdlib.h>

//初始化
void QueueInitiate(LQueue *Q) {
	Q->front = NULL;//定义初始时队头指针的初始值
	Q->rear = NULL;//定义初始时队尾指针的初始值
}

//非空否
int QueueNotEmpty(LQueue Q) {
	if (Q.front == NULL) {
		return 0;//为空则返回0
	}
	else {
		return 1;//非空返回1
	}
}

//入队列
void QueueAppend(LQueue*Q, Datatype x) {
	LQNode *p;
	p = (LQNode*)malloc(sizeof(LQNode));//创建新的结点
	p->data = x;//新结点数据域赋值
	p->next = NULL;//入队列是插入队列的尾部，所以指针域置空

	if (Q->rear!=NULL) {//队列原来非空时队尾加新结点
		Q->rear->next;
	}
	Q->rear = p;
	if (Q->front == NULL) {//队列原来为空时修改队头指针
		Q->front = p;
	}
}

//出队列
int QueueDelete(LQueue *Q, Datatype *d) {
	LQueue *p;
	if (Q->front == NULL) {
		printf("队列为空，无法出队列！");
		return 0;
	}
	else {
		*d = Q->front->data;
		p = Q->front;
		Q->front=Q->front->next;
		if (Q->front == NULL) {
			Q->rear = NULL;
		}
		free(p);
		return 1;//出队成功返回1
	}
}

//取队头数据元素
int QueueGet(LQueue Q, Datatype *d) {
	if (Q.front == NULL) {
		printf("队列已空，无数据元素出队列！");
		return 0;
	}
	else {
		*d = Q.front->data;
		return 1;
	}
}

//撤销队列（撤销动态申请空间）
void QueueDestroy(LQueue Q) {
	LQNode *p,*q;
	p = Q.front;
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
}
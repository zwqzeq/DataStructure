#include"LinkQueue.h"
#include<stdlib.h>

//��ʼ��
void QueueInitiate(LQueue *Q) {
	Q->front = NULL;//�����ʼʱ��ͷָ��ĳ�ʼֵ
	Q->rear = NULL;//�����ʼʱ��βָ��ĳ�ʼֵ
}

//�ǿշ�
int QueueNotEmpty(LQueue Q) {
	if (Q.front == NULL) {
		return 0;//Ϊ���򷵻�0
	}
	else {
		return 1;//�ǿշ���1
	}
}

//�����
void QueueAppend(LQueue*Q, Datatype x) {
	LQNode *p;
	p = (LQNode*)malloc(sizeof(LQNode));//�����µĽ��
	p->data = x;//�½��������ֵ
	p->next = NULL;//������ǲ�����е�β��������ָ�����ÿ�

	if (Q->rear!=NULL) {//����ԭ���ǿ�ʱ��β���½��
		Q->rear->next;
	}
	Q->rear = p;
	if (Q->front == NULL) {//����ԭ��Ϊ��ʱ�޸Ķ�ͷָ��
		Q->front = p;
	}
}

//������
int QueueDelete(LQueue *Q, Datatype *d) {
	LQueue *p;
	if (Q->front == NULL) {
		printf("����Ϊ�գ��޷������У�");
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
		return 1;//���ӳɹ�����1
	}
}

//ȡ��ͷ����Ԫ��
int QueueGet(LQueue Q, Datatype *d) {
	if (Q.front == NULL) {
		printf("�����ѿգ�������Ԫ�س����У�");
		return 0;
	}
	else {
		*d = Q.front->data;
		return 1;
	}
}

//�������У�������̬����ռ䣩
void QueueDestroy(LQueue Q) {
	LQNode *p,*q;
	p = Q.front;
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
}
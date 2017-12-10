#pragma once
typedef int Datatype;

//��ʽ������ÿ�����
typedef  struct qnode{
	Datatype data;     //������
	struct qnode * next;//ָ����                                            
} LQNode ;

//��ʽ���е�ָ��
typedef struct
{
	LQNode *front;//��ͷָ��
	LQNode * rear;//��βָ��
}LQueue;


//��������
void QueueInitiate(LQueue *Q);
int QueueNotEmpty(LQueue Q);
void QueueAppend(LQueue*Q, Datatype x);
int QueueDelete(LQueue *Q, Datatype *d);
int QueueGet(LQueue Q, Datatype *d);
void QueueDestroy(LQueue Q);
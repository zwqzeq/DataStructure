//��ֹ�ظ�����
#ifndef SLNODE_H
#define SLNODE_H
#include <stdio.h>
#include <malloc.h>

typedef int DataType;

//����ṹ��
typedef struct Node
{
	DataType data;
	struct Node *next;
}SLNode;

//��ʼ��˳���
void ListInitiate(SLNode **head);                   //��������
//��ǰ����Ԫ�ظ���
int ListLength(SLNode *head);
//��������Ԫ��
int ListInsert(SLNode *head, int i, DataType x);
//ɾ�����ݸ���Ԫ��
int ListDelete(SLNode *head, int i, DataType *x);
//ȡ����Ԫ��
int ListGet(SLNode *head, int i, DataType *x);
//����������
void Destory(SLNode **head);

#endif
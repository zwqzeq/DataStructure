#include "SLNode.h"

//��ʼ��˳���
void ListInitiate(SLNode **head)
{
	*head = (SLNode *)malloc(sizeof(SLNode));//����ͷ��㣬��headָ�����ַ
	(*head)->next = NULL;//�ý������NULL
}
//��ǰ����Ԫ�ظ���
int ListLength(SLNode *head)
{
	SLNode *p = head;
	int size = 0;
	while (p->next != NULL)
	{
		p = p->next;
		size++;
	}
	return size;
}
//��������Ԫ��
int ListInsert(SLNode *head, int i, DataType x)
{
	SLNode *p, *q;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL && j < i - 1)//������pָ���i-1�����
	{
		p = p->next;
		j++;
	}
	if (j != i - 1)
	{
		printf("����Ԫ��λ�ò�������\n");
		return 0;
	}
	q = (SLNode *)malloc(sizeof(SLNode));//�����½��
	q->data = x;//�½��������ֵ
	q->next = p->next;//���벽��1
	p->next = q;//���벽��2
	return 1;
}

//ɾ������Ԫ�ظ���
//ɾ����ͷ��㵥����head�ĵ�i�����
//��ɾ������������ֵ��x���أ��ɹ�����1��ʧ��0
int ListDelete(SLNode *head, int i, DataType *x)
{
	SLNode *p, *s;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL && p->next->next != NULL && j < i -1)
	{
		p = p->next;//ѭ������ʱpָ��i-1�����
		j++;
	}
	if (j != i - 1)
	{
		printf("ɾ��Ԫ��λ�ò�������\n");
		return 0;
	}
	s = p->next;
	*x = s->data;
	p->next = p->next->next;
	free(s);
	return 1;
}
//ȡ����Ԫ��
int ListGet(SLNode *head, int i, DataType *x)
{
	SLNode *p;
	int j;
	p = head;
	j = -1;
	while (p->next != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	if (j != i)
	{
		printf("ȥԪ�ز���λ�ô���\n");
		return 0;
	}
	*x = p->data;
	return 1;
}
//����������
void Destory(SLNode **head)
{
	SLNode *p, *p1;
	p = *head;
	while (p != NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
	*head = NULL;
}
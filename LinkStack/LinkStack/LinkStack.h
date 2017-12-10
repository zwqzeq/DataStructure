#pragma once
typedef int Datatype;

//��ʽ��ջ�Ľ��
typedef struct snode
{
	Datatype data;//������
	struct snode *next;//ָ����
}LinkStack;

//��������
void StackInitiate(LinkStack **head);
int StackNotEmpty(LinkStack *head);
int StackPush(LinkStack *head, Datatype x);
int StackPop(LinkStack*head, Datatype *d);
int StackTop(LinkStack *head, Datatype *d);
int StackDestroy(LinkStack *head);



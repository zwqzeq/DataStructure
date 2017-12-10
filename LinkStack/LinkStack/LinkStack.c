#include"LinkStack.h"
#include<stdlib.h>
//��ʼ��
void StackInitiate(LinkStack **head) {
	*head = (LinkStack*)malloc(sizeof(LinkStack));//��ͷָ��headָ�򴴽��ĵ�һ����㣬��������ͷ��㣩
	(*head)->next = NULL;


}
int StackNotEmpty(LinkStack *head) {
	if (head->next == NULL) {
		return 0;//��ջΪ��ʱ������0
	}
	else {
		return 1;//��ջ��Ϊ��ʱ����1
	}
}

//��ջ
int StackPush(LinkStack *head, Datatype x) {
	LinkStack *p;
	p = (LinkStack*)malloc(sizeof(LinkStack));//����һ���½��
	p->data = x;//���½��������ֵ
	p->next = head->next; //�½������ջ��
	head->next = p;           //�½���Ϊ�µ�ջ��
}

//��ջ
int StackPop(LinkStack*head, Datatype *d) {
	LinkStack *p;
	p = head->next;
	if (head->next == NULL) {
		printf("��ջΪ�գ��޷���ջ��");
		return 0;
	}
	*d = head->next->data;
	head->next=head->next->next;
	free(p);
	return 1;
}

//ȡջ��Ԫ��
int StackTop(LinkStack *head, Datatype *d) {
	if (head->next == NULL) {
		printf("��ջ�ѿ��޷�ȡջ��Ԫ�أ�");
		return 0;
	}
	*d = head->next->data;
	return 1;
}

//������ջ
int StackDestroy(LinkStack *head) {
	LinkStack *p,*q;
	p = head;
	while (p ->next != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	head = NULL;
}
#include<stdio.h>
#include"LinkStack.h"

//�������
int main() {
	int i;
	Datatype d;
	LinkStack *head;               //����ͷָ�����
	StackInitiate(&head);       //��ʼ��
	for (i = 0; i < 10; i++) {
		StackPush(head, i + 1);//��ջ
	}
	StackTop(head, &d);//ȡջ��Ԫ��
	printf("��ǰջ��Ԫ��Ϊ��%d\n", d);
	printf("���γ�ջ������Ԫ���������£�\n");
	while (StackNotEmpty(head)) {//ջ�ǿշ�
		StackPop(head, &d);//��ջ
		printf("%d  ", d);
	}
	StackDestroy(head);//������ջ
	printf("\n");
}
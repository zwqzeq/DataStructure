//˳���ջ
#include<stdio.h>
#include "SeqStack.h"


int main() {
	int i = 0;
	Datatype x;
	SeqStack myStack;//������ջ
	StackInitiate(&myStack);//��ʼ����ջ
	for (i = 0; i < 10; i++) {
		StackPush(&myStack, i + 1);
	}
	StackTop(&myStack, &x);
	printf("��ǰջ��Ԫ��Ϊ:%d \n", x);
	printf("���γ�ջ������Ԫ����������:\n ");
	while(StackNotEmpty(myStack)){
		StackPop(&myStack, &x);
		printf("%d   ", x);
	}
	printf("\n");
	return 0;
}






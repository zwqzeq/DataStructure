//顺序堆栈
#include<stdio.h>
#include "SeqStack.h"


int main() {
	int i = 0;
	Datatype x;
	SeqStack myStack;//创建堆栈
	StackInitiate(&myStack);//初始化堆栈
	for (i = 0; i < 10; i++) {
		StackPush(&myStack, i + 1);
	}
	StackTop(&myStack, &x);
	printf("当前栈顶元素为:%d \n", x);
	printf("依次出栈的数据元素序列如下:\n ");
	while(StackNotEmpty(myStack)){
		StackPop(&myStack, &x);
		printf("%d   ", x);
	}
	printf("\n");
	return 0;
}






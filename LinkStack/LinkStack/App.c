#include<stdio.h>
#include"LinkStack.h"

//程序入口
int main() {
	int i;
	Datatype d;
	LinkStack *head;               //定义头指针变量
	StackInitiate(&head);       //初始化
	for (i = 0; i < 10; i++) {
		StackPush(head, i + 1);//入栈
	}
	StackTop(head, &d);//取栈顶元素
	printf("当前栈顶元素为：%d\n", d);
	printf("依次出栈的数据元素序列如下：\n");
	while (StackNotEmpty(head)) {//栈非空否
		StackPop(head, &d);//出栈
		printf("%d  ", d);
	}
	StackDestroy(head);//撤销堆栈
	printf("\n");
}
#include "SeqStack.h"

//初始化
void StackInitiate(SeqStack*S) {
	S->top = 0;
}

//栈顶非空否
int StackNotEmpty(SeqStack S) {
	if (S.top <= 0) {
		return 0;//为空返回0
	}
	else {
		return 1;//非空返回1
	}
}

//入栈
int StackPush(SeqStack*S, Datatype x) {
	if (S->top >= MaxStackSize) {
		printf("堆栈已满，无法插入！\n");
		return 0;
	}
	S->stack[S->top] = x;
	(S->top)++;
	return 1;
}


//出栈
int StackPop(SeqStack*S, Datatype *d) {
	if (S->top <= 0) {                /*为什么top=0时，堆栈也为空呢？
									  top标记的是栈顶位置，且栈顶总是空的，top标记的位置总是空
									  例如：当top=0时，top标记在第一个结点（结点0）此时数据元素个数为0，
									  当存入第一个数据到堆栈（即第一个元素入栈）时，即top向右移动一位即top=1，top标记的位置为（结点1）即堆栈的第二个结点，此时堆栈中存放的数据元素个数为1
									  */
		printf("堆栈已空无法出栈！");
		return 0;
	}
	*d = S->stack[S->top-1];
	S->top--;
	return 1;
}

//取栈顶元素
int StackTop(SeqStack*S, Datatype *d) {
	if (S->top <= 0) {
		printf("堆栈已空无法取元素");
	}
	else {
		*d = S->stack[S->top - 1];
	}
}
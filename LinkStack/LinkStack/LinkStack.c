#include"LinkStack.h"
#include<stdlib.h>
//初始化
void StackInitiate(LinkStack **head) {
	*head = (LinkStack*)malloc(sizeof(LinkStack));//让头指针head指向创建的第一个结点，（即创建头结点）
	(*head)->next = NULL;


}
int StackNotEmpty(LinkStack *head) {
	if (head->next == NULL) {
		return 0;//堆栈为空时，返回0
	}
	else {
		return 1;//堆栈不为空时返回1
	}
}

//入栈
int StackPush(LinkStack *head, Datatype x) {
	LinkStack *p;
	p = (LinkStack*)malloc(sizeof(LinkStack));//创建一个新结点
	p->data = x;//给新结点数据域赋值
	p->next = head->next; //新结点链入栈顶
	head->next = p;           //新结点成为新的栈顶
}

//出栈
int StackPop(LinkStack*head, Datatype *d) {
	LinkStack *p;
	p = head->next;
	if (head->next == NULL) {
		printf("堆栈为空，无法出栈！");
		return 0;
	}
	*d = head->next->data;
	head->next=head->next->next;
	free(p);
	return 1;
}

//取栈顶元素
int StackTop(LinkStack *head, Datatype *d) {
	if (head->next == NULL) {
		printf("堆栈已空无法取栈顶元素！");
		return 0;
	}
	*d = head->next->data;
	return 1;
}

//撤销堆栈
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
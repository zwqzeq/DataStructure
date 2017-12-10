#pragma once
typedef int Datatype;

//链式堆栈的结点
typedef struct snode
{
	Datatype data;//数据域
	struct snode *next;//指针域
}LinkStack;

//函数声明
void StackInitiate(LinkStack **head);
int StackNotEmpty(LinkStack *head);
int StackPush(LinkStack *head, Datatype x);
int StackPop(LinkStack*head, Datatype *d);
int StackTop(LinkStack *head, Datatype *d);
int StackDestroy(LinkStack *head);



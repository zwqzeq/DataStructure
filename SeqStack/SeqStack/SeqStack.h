#pragma once
#define MaxStackSize 100               //宏定义

typedef int Datatype;                     

/*
顺序堆栈和顺序表的不同和相同点：
相同点：顺序堆栈和顺序表的数据成员相同
不同点：顺序堆栈的入栈和出栈只能对当前栈顶元素进行
*/
typedef struct
{
	Datatype stack[MaxStackSize];//顺序堆栈的大小
	int top;//记录当前栈顶位置（也可以以此（top的值）知道当前栈中存放了多少元素）;注意：每向堆栈中存放一个数，top就向右移动一位，top标记的位置始终是一个空位置（没有存放数据）
}SeqStack;

//函数声明
void StackInitiate(SeqStack*S);//初始化
int StackNotEmpty(SeqStack S);//栈顶非空否
int StackPush(SeqStack*S,Datatype x);//入栈
int StackPop(SeqStack*S,Datatype *d);//出栈
int StackTop(SeqStack*S, Datatype *d);//取栈顶元素

